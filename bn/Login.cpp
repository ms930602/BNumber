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
		if (CStitle == _T("���������˲���"))
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
	ע��ģ�� = 1,
	ж��ģ�� = 2,
	�л���ɫ = 3
};
//�������Ҫ����ͨ�ź���������dll��ж�أ�����Ĵ����ȣ������̨����

UINT __stdcall Login_threadFunc(void* p)//��¼�̺߳���
{

	int nType = (int)p;

	if (nType == ע��ģ��)
	{
		Initial();
		dbgPrint("ע��ģ��");
		return 0;
	}

	dbgPrint("ж��ģ��");
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
	sprintf(tMeMapFile.szName, "δ��¼");
	sprintf(tMeMapFile.szDiTu, "δ��¼");
	sprintf(tMeMapFile.szZhuRu, "��ע��");
	tMeMapFile.nState = -1;
	//����ע����Ϣ��ӳ�������ȥ
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
	pFileSystem->MyGetFilePath(pMe->hDll);//��ȡ�ļ�·����ʼ��
	pMsg->Init();

}

UINT __stdcall Login_AgainFunc(void* p)//��¼�̺߳���
{
	for (size_t i = 0; i < 10 && pMe->bLogin; i++)
	{
		if (!pMsg->msg_getnumber("if IsWindowShow(\"MiniMap\") then g_GetValue = 1 else g_GetValue = 0 end"))//�����ͼ
		{
			break;
		}
		Sleep(2000);
	}

	while (pMe->bLogin)
	{
		if (pMsg->msg_getnumber("if IsWindowShow(\"MiniMap\") then g_GetValue = 1 else g_GetValue = 0 end"))//�����ͼ
		{
			Sleep(1000);//��ʱ���ӳٲ���			
			pFileSystem->FileInitial();//��ʼ���ļ�
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

	dbgPrint("�ٴε�¼�߳��˳�");

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