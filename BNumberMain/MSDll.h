#pragma once
#include "stdafx.h"
using namespace std;

BOOL InJectDll(DWORD processID, CString DllName);

vector<DWORD> GetNameProcessId(CString ProcessName);

//开启或关闭权限
bool EnablePrivilege(WCHAR PrivilegeName[], BOOL IsEnable);

unsigned int __stdcall InJect_Thread(void* p);

unsigned int __stdcall Strat_Thread(void* p);

unsigned int __stdcall Launch_thread(void *p);//登录游戏线程函数

unsigned int __stdcall MoreLaunch_thread(void *p);//批量登录游戏函数

unsigned int __stdcall TimeLaunch_thread(void *p);//定时登录游戏线程函数