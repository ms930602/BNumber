#include "stdafx.h"
#include "BNCtrl.h"
#include "UI.h"

extern UI* pUI;

CBNCtrl::CBNCtrl()
{
	pUI = nullptr;//UI指针
	hDll = nullptr;//模块句柄
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

	if (hKillThread)//杀怪线程
	{
		::CloseHandle(hKillThread);
		hKillThread = nullptr;
	}

	if (hTaskThread)//任务线程停止时可能要等待很久
	{
		::CloseHandle(hTaskThread);
		hTaskThread = nullptr;
	}

	//HANDLE hTryThread;
	if (hProtectThread)//任务线程停止时可能要等待很久
	{
		::CloseHandle(hProtectThread);
		hProtectThread = nullptr;
	}
}

UINT __stdcall UI_ThradFunc(LPVOID p)
{

	//采用成员变量创建一个模态对话框
	pUI = new UI(); //给指针分配内存
	pUI->DoModal(); //创建一个模态对话框

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