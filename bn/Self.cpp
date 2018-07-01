#include "stdafx.h"
#include "Self.h"
#include "Login.h"

extern UI* pUI;

CSelf::CSelf()
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

void CSelf::CreatUI()
{
	bUiThread = true;
	hUIThread = (HANDLE)_beginthreadex(NULL, 0, &UI_ThreadFunc, this, 0, NULL);
}

void CSelf::CreatKillMonster()
{
}

void CSelf::CreatLogin(int nNUM)//创建登录线程
{
	HANDLE hlg = (HANDLE)_beginthreadex(NULL, 0, &Login_ThreadFunc, (void*)nNUM, 0, NULL);
	::CloseHandle(hlg);
}

void CSelf::CreatProtect()
{
}

void CSelf::CreatTask(int nType)
{
}

void CSelf::CreatAgainLogin()//创建切换角色的线程
{
	bLogin = true;
	hAgainLoginThread = (HANDLE)_beginthreadex(NULL, 0, &Login_AgainFunc, NULL, 0, NULL);
}

UINT __stdcall UI_ThreadFunc(LPVOID p)
{

	//采用成员变量创建一个模态对话框
	pUI = new UI(); //给指针分配内存
	pUI->DoModal(); //创建一个模态对话框

	return 0;
}