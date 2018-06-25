#include "stdafx.h"
#include "ServerCtrl.h"

const LPCTSTR CServerCtrl::ADDRESS = _T("0.0.0.0");
const USHORT CServerCtrl::PORT = 5555;
CCriticalSection g_State;
CCriticalSection g_State_Queue;

CServerCtrl::CServerCtrl() :m_Server(this)
{
}

CServerCtrl::~CServerCtrl()
{
	this->stop();
}

void CServerCtrl::start()
{
	m_strAddress.Trim();
	if (m_Server->Start(ADDRESS, PORT))
	{

	}
	else {
		ASSERT(FALSE);
	}
}

void CServerCtrl::stop()
{
	if (m_Server->Stop())
	{

	}
	else
	{
		ASSERT(FALSE);
	}
}

void CServerCtrl::Disconnect()
{
	CString strConnID;
	CONNID dwConnID = (CONNID)_ttoi(strConnID);
	m_Server->Disconnect(dwConnID);
}

EnHandleResult CServerCtrl::OnPrepareListen(ITcpServer * pSender, SOCKET soListen)
{
	TCHAR szAddress[50];
	int iAddressLen = sizeof(szAddress) / sizeof(TCHAR);
	USHORT usPort;

	pSender->GetListenAddress(szAddress, iAddressLen, usPort);
	return HR_OK;
}

EnHandleResult CServerCtrl::OnAccept(ITcpServer * pSender, CONNID dwConnID, SOCKET soClient)
{
	BOOL bPass = TRUE;
	TCHAR szAddress[50];
	int iAddressLen = sizeof(szAddress) / sizeof(TCHAR);
	USHORT usPort;

	pSender->GetRemoteAddress(dwConnID, szAddress, iAddressLen, usPort);

	if (!m_strAddress.IsEmpty())
	{
		if (m_strAddress.CompareNoCase(szAddress) == 0)
			bPass = FALSE;
	}

	if (bPass) pSender->SetConnectionExtra(dwConnID, new TPkgInfo(true, sizeof(TPkgHeader)));

	return bPass ? HR_OK : HR_ERROR;
}

EnHandleResult CServerCtrl::OnSend(ITcpServer * pSender, CONNID dwConnID, const BYTE * pData, int iLength)
{
	return HR_OK;
}

EnHandleResult CServerCtrl::OnReceive(ITcpServer * pSender, CONNID dwConnID, int iLength)
{
	TPkgInfo* pInfo = FindPkgInfo(pSender, dwConnID);
	ITcpPullServer* pServer = ITcpPullServer::FromS(pSender);

	if (pInfo != nullptr)
	{
		int required = pInfo->length;
		int remain = iLength;

		while (remain >= required)
		{
			remain -= required;
			CBufferPtr buffer(required);

			EnFetchResult result = pServer->Fetch(dwConnID, buffer, (int)buffer.Size());
			if (result == FR_OK)
			{
				if (pInfo->is_header)
				{
					TPkgHeader* pHeader = (TPkgHeader*)buffer.Ptr();
					TRACE("[Server] head -> seq: %d, body_len: %d\n", pHeader->seq, pHeader->body_len);

					required = pHeader->body_len;

					if (required == 0)		//接收到只有单纯的包ID这种类型的包
					{
						required = sizeof(TPkgHeader);
						pInfo->is_header = false;
						HandlePacket(dwConnID, pHeader->seq, (CBufferPtr)NULL);
					}
				}
				else
				{
					HandlePacket(dwConnID, pInfo->dwpacketID, buffer);
					required = sizeof(TPkgHeader);
				}

				pInfo->is_header = !pInfo->is_header;
				pInfo->length = required;

				if (!pSender->Send(dwConnID, buffer, (int)buffer.Size()))
					return HR_ERROR;
			}
		}
	}

	return HR_OK;
}

EnHandleResult CServerCtrl::OnClose(ITcpServer * pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode)
{
	RemovePkgInfo(pSender,dwConnID);
	return HR_OK;
}

EnHandleResult CServerCtrl::OnShutdown(ITcpServer * pSender)
{
	return HR_OK;
}

TPkgInfo * CServerCtrl::FindPkgInfo(ITcpServer * pSender, CONNID dwConnID)
{
	PVOID pInfo = nullptr;

	pSender->GetConnectionExtra(dwConnID, &pInfo);

	return (TPkgInfo*)pInfo;
}

void CServerCtrl::RemovePkgInfo(ITcpServer * pSender, CONNID dwConnID)
{
	TPkgInfo* pInfo = FindPkgInfo(pSender, dwConnID);
	ASSERT(pInfo != nullptr);

	delete pInfo;
}

void CServerCtrl::HandlePacket(CONNID dwConnID, DWORD dwPacketID, CBufferPtr pbuffer)
{
	switch (dwPacketID)
	{
	case	SOCKET_LINK:
	{
		MySendLoginInfo(dwConnID, pbuffer);
		TRACE(__FUNCTION__"[Server]连接主控\n");
	}
	break;
	case	SOCKET_LINK_重连:
	{
		SocketBind _SocketBind = { 0 };
		_SocketBind = *(SocketBind*)(BYTE*)pbuffer.Ptr();
		_SocketBind.dwConnID = dwConnID;
		MyAddClient(dwConnID, _SocketBind);
		状况信息(_SocketBind, "已注入");
		TRACE(__FUNCTION__"[Server]重连中控\n");
	}
	break;
	case	SOCKET_GAME_INFO:
	{
		//游戏账号的状况信息
		SocketBind _SocketBind = { 0 };
		if (MyGetClientBind(dwConnID, &_SocketBind))
		{
			状况信息(_SocketBind, (char*)(BYTE*)pbuffer.Ptr());
		}
		else
		{
			TRACE(__FUNCTION__"游戏帐号的状况信息-->>此链接没有绑定任何信息");
		}
	}
	break;
	//////////////////////////////////////////////////////////////////////////
	case SOCKET_USERINFO:
	{
		//游戏的角色属性信息
		SocketBind _SocketBind = { 0 };
		if (MyGetClientBind(dwConnID, &_SocketBind))
		{
			SocketBind* pBind = new SocketBind;
			*pBind = _SocketBind;
			SocketGameRoleInfo* _socketgameInfo = new SocketGameRoleInfo;
			*_socketgameInfo = *(SocketGameRoleInfo*)(BYTE*)pbuffer.Ptr();
			::PostMessage(g_MyHwnd, WM_USER_人物属性信息, (WPARAM)pBind, (LPARAM)_socketgameInfo);
		}
		else
		{
			TRACE(__FUNCTION__"游戏的角色属性信息-->>此链接没有绑定任何帐号");
		}
	}
	break;
	case  SOCKET_主控接受客户端_答题信息:
	{
		//dbgPrint("SOCKET_主控接受客户端_答题信息");
		SocketValidate _Validate = *(SocketValidate*)(BYTE*)pbuffer.Ptr();
		if (((CString)_Validate._ImageName).Find(".jpg") == -1)
			break;
		_Validate.dwDllConnID = dwConnID;
		_Validate.dwTimeCount = 55000;
		if (pHPClient->m_Client->GetState() == SS_STOPPED)
			break;
		pHPClient->SendValidateInfo(&_Validate, sizeof(_Validate));
		break;
	}
	default:
		break;
	}
}

void CServerCtrl::OnReceiveStrMessage(CONNID dwConnid, CBufferPtr pbuffer)
{
	if (pbuffer.Size() < 0) return;
}

void CServerCtrl::OnReceivePlayerInfo(CONNID dwConnid, CBufferPtr pbuffer)
{
	if (pbuffer.Size() < 0) return;
}

void CServerCtrl::MySendPackets(CONNID dwConnID, DWORD dwpacketID, int body_len, char * Socketbody)
{
	TPkgHeader header;
	header.seq = dwpacketID;
	header.body_len = body_len;

	WSABUF bufs[2];
	bufs[0].len = sizeof(TPkgHeader);
	bufs[0].buf = (char*)&header;
	bufs[1].len = body_len;
	bufs[1].buf = Socketbody;
	m_Server->SendPackets(dwConnID, bufs, 2);
}

void CServerCtrl::MySendLoginInfo(CONNID dwConnID, CBufferPtr pbuffer)
{
	SocketBind _SocketBind = { 0 };
	_SocketBind.dwConnID = dwConnID;
	_SocketBind.dwGameID = *(DWORD*)(BYTE*)pbuffer;

	SocketLoginInfo __SocketLoginInfo = { 0 };
	if (!MyGetLoginInfo(&__SocketLoginInfo)) {
		MyAddClient(dwConnID, _SocketBind);
		状况信息(_SocketBind, "已注入");
		return;//获取登录帐号信息
	}
	strcpy(_SocketBind.Account, __SocketLoginInfo.GameName);
	MyAddClient(dwConnID, _SocketBind);
	状况信息(_SocketBind, "已注入");

	//发送帐号信息给dll
	int body_len = sizeof(__SocketLoginInfo);
	MySendPackets(dwConnID, SOCEKT_LOGIN_INFO, body_len, (char*)&__SocketLoginInfo);
}

void CServerCtrl::MySendGameScript(SocketBind _SocketBind, CString Script)
{
	CONNID dwConnID;
	if (MyGetClientConnID(&dwConnID, _SocketBind))
	{
		SocketGameScript _SocketGameScript = { 0 };
		strcpy(_SocketGameScript._GameScript, CStringA(Script));
		int body_len = sizeof(_SocketGameScript);
		MySendPackets(dwConnID, SOCKET_GAME_SCRIPT_INFO, body_len, (char*)&_SocketGameScript);
	}
	else
	{
		TRACE(__FUNCTION__"[Server]执行脚本-->>此帐号未绑定链接ID\n");
	}
}

void CServerCtrl::MySendStopScript(SocketBind _SocketBind)
{
	CONNID dwConnID;
	if (MyGetClientConnID(&dwConnID, _SocketBind))
	{
		TPkgHeader header;
		header.seq = SOCKET_GAME_STOP_SCRIPT;
		header.body_len = 0;

		WSABUF buf;
		buf.len = sizeof(TPkgHeader);
		buf.buf = (char*)&header;
		m_Server->SendPackets(dwConnID, &buf, 1);
	}
	else
	{
		TRACE(__FUNCTION__"[Server]斩停脚本-->>此帐号未绑定链接ID\n");
	}
}

void CServerCtrl::MySendContinueScript(SocketBind _SocketBind)
{
	CONNID dwConnID;
	if (MyGetClientConnID(&dwConnID, _SocketBind))
	{
		TPkgHeader header;
		header.seq = SOCKET_GAME_START_SCRIPT;
		header.body_len = 0;

		WSABUF buf;
		buf.len = sizeof(TPkgHeader);
		buf.buf = (char*)&header;
		m_Server->SendPackets(dwConnID, &buf, 1);
	}
	else
	{
		TRACE(__FUNCTION__"[Server]继续脚本-->>此帐号未绑定链接ID\n");
	}
}

void CServerCtrl::SendValidateAnswer(SocketValidateResult * _Validate, INT body_len)
{
	MySendPackets(_Validate->dwDllConnID, SOCKET_主控发送客户端_答题结果, body_len, (char*)_Validate);
}

INT CServerCtrl::MyDelClient(CONNID dwConnID)
{
	CriticalSectionLock Lock(&g_State);
	vector<SocketBind>::iterator it;
	for (it = m_vClient.begin(); it != m_vClient.end();)
	{
		if (it->dwConnID == dwConnID)
		{
			it = m_vClient.erase(it);//移除无效的包裹
		}
		else
		{
			++it;
		}
	}

	return TRUE;
}

INT CServerCtrl::MyDelClient(SocketBind _SocketBind)
{
	CriticalSectionLock Lock(&g_State);
	if (!((CString)_SocketBind.Account).IsEmpty())//帐号比较
	{
		vector<SocketBind>::iterator it;
		for (it = m_vClient.begin(); it != m_vClient.end();)
		{
			if ((CString)it->Account == (CString)_SocketBind.Account)
				it = m_vClient.erase(it);//移除无效的包裹
			else
				++it;
		}
	}
	else if (_SocketBind.dwGameID > 0)//进程比较
	{
		vector<SocketBind>::iterator it;
		for (it = m_vClient.begin(); it != m_vClient.end();)
		{
			if (it->dwGameID == _SocketBind.dwGameID)
				it = m_vClient.erase(it);//移除无效的包裹
			else
				++it;
		}
	}

	return TRUE;
}

INT CServerCtrl::MyAddClient(CONNID dwConnID, SocketBind _SocketBind)//添加绑定链接的帐号名
{
	CriticalSectionLock Lock(&g_State);
	if (!((CString)_SocketBind.Account).IsEmpty())//帐号比较
	{
		vector<SocketBind>::iterator it;
		for (it = m_vClient.begin(); it != m_vClient.end();)
		{
			if ((CString)it->Account == (CString)_SocketBind.Account)
				it = m_vClient.erase(it);//移除无效的包裹
			else
				++it;
		}
	}
	else if (_SocketBind.dwGameID > 0)//进程比较
	{
		vector<SocketBind>::iterator it;
		for (it = m_vClient.begin(); it != m_vClient.end();)
		{
			if (it->dwGameID == _SocketBind.dwGameID)
				it = m_vClient.erase(it);//移除无效的包裹
			else
				++it;
		}
	}

	m_vClient.push_back(_SocketBind);

	return TRUE;
}

BOOL CServerCtrl::MyGetClientConnID(CONNID * dwConnID, SocketBind _SocketBind)//获取绑定帐号名链接的ID
{
	CriticalSectionLock Lock(&g_State);
	if (!((CString)_SocketBind.Account).IsEmpty())//帐号比较
	{
		for (auto Bind : m_vClient)
		{
			if ((CString)Bind.Account == (CString)_SocketBind.Account)
			{
				*dwConnID = Bind.dwConnID;
				return TRUE;
			}
		}
	}
	else if (_SocketBind.dwGameID > 0)//进程比较
	{
		for (auto Bind : m_vClient)
		{
			if (Bind.dwGameID == _SocketBind.dwGameID)
			{
				*dwConnID = Bind.dwConnID;
				return TRUE;
			}
		}
	}

	return FALSE;
}

BOOL CServerCtrl::MyGetClientBind(CONNID dwConnID, SocketBind * _SocketBind)
{
	CriticalSectionLock Lock(&g_State);
	for (auto Bind : m_vClient)
	{
		if (Bind.dwConnID == dwConnID)
		{
			*_SocketBind = Bind;
			return TRUE;
		}
	}

	return FALSE;
}

vector<SocketBind> CServerCtrl::MyGetAllClient()
{
	CriticalSectionLock Lock(&g_State);
	vector<SocketBind> Client = m_vClient;

	return Client;
}

BOOL CServerCtrl::MyAddLoginInfo(SocketLoginInfo _SocketLoginInfo)//添加一个登录帐号信息数据
{
	CriticalSectionLock Lock(&g_State_Queue);
	m_vLoginInfo.push(_SocketLoginInfo);

	return TRUE;
}

BOOL CServerCtrl::MyGetLoginInfo(SocketLoginInfo * pSocketLoginInfo)//获取一个登录信息数据
{
	CriticalSectionLock Lock(&g_State_Queue);

	if (m_vLoginInfo.empty())return FALSE;//元素为空，退出
										  //获取一个游戏帐号信息，用于登录使用
	*pSocketLoginInfo = m_vLoginInfo.front(); //访问第一个元素
	m_vLoginInfo.pop();//第一个元素出栈

	return TRUE;
}

BOOL CServerCtrl::MyLoginInfoIsEmpty()//获取登录信息数据是否为空
{
	CriticalSectionLock Lock(&g_State_Queue);
	if (m_vLoginInfo.empty())
	{
		return TRUE;
	}//元素为空，退出

	return FALSE;
}

void 状况信息(SocketBind _SocketBind, const char * _Message)
{
	SocketBind* pBind = new SocketBind;
	*pBind = _SocketBind;
	SocketGameInfo* _socketgameInfo = new SocketGameInfo;
	strcpy(_socketgameInfo->_Message, _Message);
	::PostMessage(g_MyHwnd, WM_USER_状况, (WPARAM)pBind, (LPARAM)_socketgameInfo);
}
