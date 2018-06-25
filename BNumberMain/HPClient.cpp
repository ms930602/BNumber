#include "stdafx.h"
#include "HPClient.h"

#define DEFAULT_ADDRESS _T("127.0.0.1")
#define DEFAULT_PORT    _T("9897")

CHPClient::CHPClient() :m_Client(this)
{
}

CHPClient::~CHPClient()
{
}

TPkgInfo * CHPClient::FindPkgInfo(ITcpServer * pSender, CONNID dwConnID)
{
	PVOID pInfo = nullptr;

	pSender->GetConnectionExtra(dwConnID, &pInfo);

	return (TPkgInfo*)pInfo;
}

void CHPClient::RemovePkgInfo(ITcpServer * pSender, CONNID dwConnID)
{
	TPkgInfo* pInfo = FindPkgInfo(pSender, dwConnID);
	ASSERT(pInfo != nullptr);

	delete pInfo;
}

void CHPClient::HPInit()
{
	CString strAddress = DEFAULT_ADDRESS;
	CString strPort = DEFAULT_PORT;
	USHORT usPort = (USHORT)_ttoi(strPort);
	this->m_strAddress = strAddress;
	if (m_Client->GetState() == SS_STOPPED) {
		if (m_Client->Start(strAddress, usPort)) {
			
		}
		else {
			ASSERT(false);
		}
	}
}

void CHPClient::HPRelease()
{
	m_Client->Stop();
}

void CHPClient::MySendPackets(DWORD dwpacketID, int body_len, char * Socketbody)
{
	TPkgHeader header;
	header.seq = dwpacketID;
	header.body_len = body_len;

	WSABUF bufs[2];
	bufs[0].len = sizeof(TPkgHeader);
	bufs[0].buf = (char*)&header;
	bufs[1].len = body_len;
	bufs[1].buf = Socketbody;
	m_Client->SendPackets(bufs, 2);
}

void CHPClient::HandlePacket(DWORD dwPacketID, CBufferPtr & buffer)
{
	switch (dwPacketID)
	{
	case SOCKET_主控接受答题端_答题结果:
	{
		SocketValidateResult _Validate = *(SocketValidateResult*)(BYTE*)buffer.Ptr();
		pMyServer->SendValidateAnswer(&_Validate, sizeof(_Validate));
		break;
	}
	default:
		break;
	}
}

void CHPClient::SendValidateInfo(SocketValidate * _Validate, INT body_len)
{
	MySendPackets(SOCKET_主控发送答题端_答题信息, body_len, (char*)_Validate);
}

EnHandleResult CHPClient::OnPrepareListen(ITcpServer * pSender, SOCKET soListen)
{
	TCHAR szAddress[50];
	int iAddressLen = sizeof(szAddress) / sizeof(TCHAR);
	USHORT usPort;

	pSender->GetListenAddress(szAddress, iAddressLen, usPort);
	return HR_OK;
}

EnHandleResult CHPClient::OnAccept(ITcpServer * pSender, CONNID dwConnID, SOCKET soClient)
{
	BOOL bPass = TRUE;
	TCHAR szAddress[50];
	int iAddressLen = sizeof(szAddress) / sizeof(TCHAR);
	USHORT usPort;

	pSender->GetRemoteAddress(dwConnID, szAddress, iAddressLen, usPort);

	if (m_strAddress.CompareNoCase(szAddress) == 0)
		bPass = FALSE;

	if (bPass) pSender->SetConnectionExtra(dwConnID, new TPkgInfo(true, sizeof(TPkgHeader)));

	return bPass ? HR_OK : HR_ERROR;
}

EnHandleResult CHPClient::OnSend(ITcpServer * pSender, CONNID dwConnID, const BYTE * pData, int iLength)
{
	return HR_OK;
}

EnHandleResult CHPClient::OnReceive(ITcpServer * pSender, CONNID dwConnID, int iLength)
{
	TPkgInfo* pInfo = FindPkgInfo(pSender,dwConnID);
	ITcpPullServer* pServer = ITcpPullServer::FromS(pSender);

	if (pInfo != nullptr) {
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

					pInfo->dwpacketID = pHeader->seq;
					required = pHeader->body_len;
					//接收到只有单纯的包ID这种类型的包
					if (required == 0)
					{
						required = sizeof(TPkgHeader);
						pInfo->is_header = false;
						HandlePacket(dwConnID, (CBufferPtr)NULL);
					}
				}
				else
				{
					HandlePacket(dwConnID, buffer);
					required = sizeof(TPkgHeader);
					pInfo->dwpacketID = NULL;
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

EnHandleResult CHPClient::OnClose(ITcpServer * pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode)
{
	RemovePkgInfo(pSender, dwConnID);
	return HR_OK;
}