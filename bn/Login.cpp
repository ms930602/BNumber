#include "stdafx.h"
#include "Login.h"
#include "Self.h"

CHPInit* pHPInit = nullptr;

extern CSelf* pMe;

CMessage* pMsg;
//luahelp* pluahelp;
CFileSystem* pFileSystem;
CCriticalSection* pCriticalSection;
CCriticalSection* pCriticalSection2;
CAsmRole* pAsmRole;
CAsmTeam* pAsmTeam;
CAsmItem* pAsmItem;
CAsmSkill* pAsmSkill;
CAsmPet* pAsmPet;
CAsmMonster* pAsmMonster;
CAsmPlayer* pAsmPlayer;
CAsmCollect* pAsmCollect;
CScriptSystem* pScriptSystem;
CUser* pUser;

bool LoginFunction()
{
	while (true)
	{
		CString CStitle = pMsg->GetWindowTitle(pMsg->GamehWnd);
		if (CStitle == _T("¡¶ÐÂÌìÁú°Ë²¿¡·"))
		{

			//dbgPrint("%x", pAsmRole->getobject());

			if (pMsg->msg_getnumber("if IsWindowShow(\"MiniMap\") then g_GetValue = 1 else g_GetValue = 0 end"))
				return TRUE;
			Sleep(1000);
		}
	}

	return FALSE;
}

CHPInit::~CHPInit()
{
}

void CHPInit::HPInit()
{
}

void CHPInit::HPRelease()
{
}

void CHPInit::MySendPID()
{
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