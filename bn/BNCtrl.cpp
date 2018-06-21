#include "stdafx.h"
#include "BNCtrl.h"
#include "UI.h"

extern UI* pUI;

CBNCtrl::CBNCtrl()
{
	pUI = nullptr;//UIָ��
	hDll = nullptr;//ģ����
	hKillThread = nullptr;
	hUIThread = nullptr;
	hProtectThread = nullptr;
	hTaskThread = nullptr;
	bKillThread = false;
	bUiThread = false;
	bRun = false;
	bTaskThread = false;
	hMapFile = nullptr;
	atomic_int_work_thread = 0;
	bProtectRun = false;
	bLogin = false;
}

CBNCtrl::~CBNCtrl()
{
	if (hMapFile)
	{
		::CloseHandle(hMapFile);
	}
}

void CBNCtrl::EndThread()
{
	bProtectRun = false;
	bRun = false;
	bKillThread = false;
	bTaskThread = false;

	if (hKillThread)//ɱ���߳�
	{
		::CloseHandle(hKillThread);
		hKillThread = nullptr;
	}

	if (hTaskThread)//�����߳�ֹͣʱ����Ҫ�ȴ��ܾ�
	{
		::CloseHandle(hTaskThread);
		hTaskThread = nullptr;
	}

	//HANDLE hTryThread;
	if (hProtectThread)//�����߳�ֹͣʱ����Ҫ�ȴ��ܾ�
	{
		::CloseHandle(hProtectThread);
		hProtectThread = nullptr;
	}
}

UINT __stdcall UI_ThradFunc(LPVOID p)
{

	//���ó�Ա��������һ��ģ̬�Ի���
	pUI = new UI(); //��ָ������ڴ�
	pUI->DoModal(); //����һ��ģ̬�Ի���

	return 0;
}

void CBNCtrl::CreateUI()
{
}

void CBNCtrl::CreateKillMonster()
{
}

void CBNCtrl::CreateLogin()
{
}

void CBNCtrl::CreateProtect()
{
}

void CBNCtrl::CreateTask()
{
}