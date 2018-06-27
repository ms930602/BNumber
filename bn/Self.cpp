#include "stdafx.h"
#include "Self.h"
#include "UI.h"

extern UI* pUI;
extern CSelf* self;

CSelf::CSelf()
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

CSelf::~CSelf()
{
	if (hMapFile)
	{
		::CloseHandle(hMapFile);
	}
}

void CSelf::EndThread()
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

void CSelf::CreatLogin(int nNUM)
{
}

UINT __stdcall UI_ThradFunc(LPVOID p)
{

	//���ó�Ա��������һ��ģ̬�Ի���
	pUI = new UI(); //��ָ������ڴ�
	pUI->DoModal(); //����һ��ģ̬�Ի���

	return 0;
}
