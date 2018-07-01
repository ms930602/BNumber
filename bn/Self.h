#pragma once
#include "Resource.h"
#include "UI.h"
#include "Function.h"
#include <atomic>
#include "Message.h"

struct TSelfMapFile
{
	char szName[50];
	char szDiTu[50];
	char szZhuRu[50];
	int  nState;
};

class CSelf
{
public:
	CSelf();
	~CSelf();

public:
	void EndThread();
public:
	friend UINT __stdcall UI_ThreadFunc(LPVOID p);//UI 线程函数
	friend UINT __stdcall KillMonster_ThreadFunc(LPVOID p);//砍怪线程函数
	friend UINT __stdcall Login_ThreadFunc(void* p);//登录线程函数
	friend UINT __stdcall Protecd_ThreadFunc(void* p);//保护线程函数
	friend UINT __stdcall Task_ThreadFunc(void* p);//脚本任务线程函数
	friend UINT __stdcall Login_AgainFunc(void* p);//登录线程函数
public:
	void CreatUI();//创建UI
	void CreatKillMonster();//创建杀怪线程
	void CreatLogin(int nNUM);//创建登录线程
	void CreatProtect();//创建保护线程
	void CreatTask(int nType);//创建Task线程
	void CreatAgainLogin();//创建切换角色的线程
public:
	HMODULE hDll;//句柄
public:
	HANDLE hAgainLoginThread;
	HANDLE hKillThread;
	HANDLE hUIThread;
	HANDLE hProtectThread;
	HANDLE hTryThread;
	HANDLE hTaskThread;
	HANDLE hMapFile;
public:
	bool bLogin;
	bool bUiThread;
	bool bKillThread;
	bool bRun;
	bool bProtectRun;
	bool bTaskThread;//任务线程标志
public:
	atomic_int atomic_int_work_thread;//线程计数器
};