#include "stdafx.h"
#include "Login.h"
#include "Self.h"
#include <mmsystem.h>
#include "MeProject.h"
#include "ScriptSystem.h"
#pragma comment(lib, "winmm.lib")

CHPInit* pHPInit = nullptr;

extern CSelf* pMe;
UI* pUI;
CMessage* pMsg;
//luahelp* pluahelp;
CFileSystem* pFileSystem;
CCriticalSection* pCriticalSection;
CCriticalSection* pCriticalSection2;
CMsRole* pAsmRole;
CMsTeam* pAsmTeam;
CMsItem* pAsmItem;
CMsSkill* pAsmSkill;
CMsPet* pAsmPet;
CMsMonster* pAsmMonster;
CMsPlayer* pAsmPlayer;
CMsCollect* pAsmCollect;
CScriptSystem* pScriptSystem;
CUser* pUser;

#define DEFAULT_CONTENT	_T("text to be sent")
#define DEFAULT_ADDRESS	_T("127.0.0.1")
#define DEFAULT_PORT	_T("5555")

bool LoginFunction()
{
	while (true)
	{
		CString CStitle = pMsg->GetWindowTitle(pMsg->GamehWnd);
		if (CStitle == _T("《新天龙八部》"))
		{

			//dbgPrint("%x", pAsmRole->getobject());

			if (pMsg->msg_getnumber("if IsWindowShow(\"MiniMap\") then g_GetValue = 1 else g_GetValue = 0 end"))
				return TRUE;
			Sleep(1000);
		}
	}

	return FALSE;
}

enum ELogin
{
	注入模块 = 1,
	卸载模块 = 2,
	切换角色 = 3
};
//这里可能要做个通信函数，用于dll的卸载，任务的触发等，与控制台交互

UINT __stdcall Login_threadFunc(void* p)//登录线程函数
{

	int nType = (int)p;

	if (nType == 注入模块)
	{
		Initial();
		dbgPrint("注入模块");
		return 0;
	}

	dbgPrint("卸载模块");
	ExitLogin();
	UnDetoursHook();
	UnAnserHook();
	::FreeLibraryAndExitThread(pMe->hDll, 1);

	return 1;
}

void Initial()
{
	pHPInit = new CHPInit;
	pHPInit->HPInit();
	TSelfMapFile tMeMapFile;
	sprintf(tMeMapFile.szName, "未登录");
	sprintf(tMeMapFile.szDiTu, "未登录");
	sprintf(tMeMapFile.szZhuRu, "已注入");
	tMeMapFile.nState = -1;
	//保存注入信息到映射对象中去
	SendToCtrl(tMeMapFile);
	//-----------------------------------------------------------------------
	pFileSystem = new CFileSystem;
	pMsg = new CMessage;
	pCriticalSection = new CCriticalSection;
	pCriticalSection2 = new CCriticalSection;
	pAsmRole = new CMsRole;
	pAsmTeam = new CMsTeam;
	pAsmItem = new CMsItem;
	pAsmSkill = new CMsSkill;
	pAsmPet = new CMsPet;
	pAsmMonster = new CMsMonster;
	pAsmPlayer = new CMsPlayer;
	pAsmCollect = new CMsCollect;
	pUser = new CUser;
	pScriptSystem = new CScriptSystem;
	pScriptSystem->LUA_ScriptSystemInitial();
	//------------------------------------------------------------------------
	//------------------------------------------------------------------------
	pFileSystem->MyGetFilePath(pMe->hDll);//获取文件路径初始化
	pMsg->Init();

}

UINT __stdcall Login_AgainFunc(void* p)//登录线程函数
{
	for (size_t i = 0; i < 10 && pMe->bLogin; i++)
	{
		if (!pMsg->msg_getnumber("if IsWindowShow(\"MiniMap\") then g_GetValue = 1 else g_GetValue = 0 end"))//迷你地图
		{
			break;
		}
		Sleep(2000);
	}

	while (pMe->bLogin)
	{
		if (pMsg->msg_getnumber("if IsWindowShow(\"MiniMap\") then g_GetValue = 1 else g_GetValue = 0 end"))//迷你地图
		{
			Sleep(1000);//暂时不延迟不行			
			pFileSystem->FileInitial();//初始化文件
			::SendMessage(pUI->m_hWnd, WM_MY_MESSAGE, 0, 3);
			break;
		}

		Sleep(2000);
	}


	if (pMe->bLogin)//hAgainLoginThread
	{
		::CloseHandle(pMe->hAgainLoginThread);
		pMe->hAgainLoginThread = NULL;
	}

	dbgPrint("再次登录线程退出");

	return 0;
}

CHPInit::~CHPInit()
{
}

void CHPInit::HPInit()
{
	CString strAddress = DEFAULT_ADDRESS;
	CString strPort = DEFAULT_PORT;
	USHORT usPort = (USHORT)_ttoi(strPort);
	m_pkgInfo.Reset();

	if (m_Client)
	{
		MySendPID();
	}
}

void CHPInit::HPRelease()
{
}

void CHPInit::MySendPID()
{
	DWORD dwGameID = GetCurrentProcessId();
	MySendPackets(SOCKET_LINK, sizeof(dwGameID), (char*)&dwGameID);
}

void CHPInit::MySendReconnection()
{
}

void CHPInit::MySendGameInfo(const char * message)
{
}

void CHPInit::MySendValidate(SocketValidate _Validate)
{
}

void CHPInit::MySendRoleInfo(int body_len, char * Socketbody)
{
}

void CHPInit::HandlePacket(DWORD dwPacketID, CBufferPtr & buffer)
{
}

EnHandleResult CHPInit::OnSend(ITcpClient * pSender, CONNID dwConnID, const BYTE * pData, int iLength)
{
	return EnHandleResult();
}

EnHandleResult CHPInit::OnReceive(ITcpClient * pSender, CONNID dwConnID, int iLength)
{
	return EnHandleResult();
}

EnHandleResult CHPInit::OnClose(ITcpClient * pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode)
{
	return EnHandleResult();
}

EnHandleResult CHPInit::OnConnect(ITcpClient * pSender, CONNID dwConnID)
{
	return EnHandleResult();
}

bool CHPInit::GetMibao(CString args, CString & strMiBao)
{
	return false;
}

void CHPInit::MySendPackets(DWORD dwpacketID, int body_len, char * Socketbody)
{
	TPkgHeader header;
	header.body_len = body_len;
	header.dwpacketID = dwpacketID;

	WSABUF bufs[2];
	bufs[0].len = sizeof(TPkgHeader);
	bufs[0].buf = (char*)&header;
	bufs[1].len = body_len;
	bufs[1].buf = Socketbody;
	m_Client->SendPackets(bufs, 2);
}

void CHPInit::MyReconnection()
{
}

UINT CHPInit::SendRoleInfo()
{
	return 0;
}

UINT CHPInit::Login_Thread()
{
	return 0;
}

UINT CHPInit::bmp_thread(SocketValidate _Validate)
{
	return 0;
}

UINT CHPInit::anser_thread(SocketValidateResult __SocketValidateResult)
{
	return 0;
}

UINT CHPInit::LUA_thread(CString file)
{
	return 0;
}