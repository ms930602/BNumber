#pragma once
#include "stdafx.h"
using namespace std;

BOOL InJectDll(DWORD processID, CString DllName);

vector<DWORD> GetGameProcessId(CString ProcessName);

//������ر�Ȩ��
bool EnablePrivilege(WCHAR PrivilegeName[], BOOL IsEnable);

unsigned int __stdcall InJect_Thread(void* p);

unsigned int __stdcall Strat_Thread(void* p);

unsigned int __stdcall Launch_thread(void *p);//��¼��Ϸ�̺߳���

unsigned int __stdcall MoreLaunch_thread(void *p);//������¼��Ϸ����

unsigned int __stdcall TimeLaunch_thread(void *p);//��ʱ��¼��Ϸ�̺߳���