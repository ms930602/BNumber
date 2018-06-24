#include "stdafx.h"
#include "MSDll.h"
#include <TlHelp32.h>
using namespace std;
BOOL InJectDll(DWORD processID, CString DllName)
{
	if (processID == -1) {
		return FALSE;
	}

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);

	if (!hProcess) {
		return FALSE;
	}

	//申请内存 

	LPVOID lpBassAddr = VirtualAllocEx(hProcess, NULL, 4096, MEM_COMMIT, PAGE_EXECUTE_READWRITE);

	if (!lpBassAddr) {
		CloseHandle(hProcess);
		return FALSE;
	}

	CString curPath = tget_curpath(TRUE);
	if (curPath.IsEmpty()) {
		CloseHandle(hProcess);
		return FALSE;
	}

	curPath += DllName;
	//DLL路径写到目标进程
	BOOL bWirte = WriteProcessMemory(hProcess, lpBassAddr, curPath, MAX_PATH, NULL);
	if (!bWirte)
	{
		CloseHandle(hProcess);
		return FALSE;
	}

	//使用远程线程加载该进程的函数加载dll
	HANDLE hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, lpBassAddr, 0, NULL);

	if (!hThread)
	{
		CloseHandle(hProcess);
		return FALSE;
	}

	//等待远程线程执行完毕
	WaitForSingleObject(hThread, INFINITE);

	//清理申请的内存
	VirtualFreeEx(hProcess, lpBassAddr, 4096, MEM_DECOMMIT);

	CloseHandle(hProcess);

	return 0;
}

vector<DWORD> GetNameProcessId(CString ProcessName)
{
	vector<DWORD> vProcessID;
	//快照缓冲区 读取全部进程到快照缓冲区中
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	//存放快照信息结构体 单个进程
	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(pe);

	BOOL bOK = Process32First(hSnapshot, &pe);

	for (; bOK; Process32Next(hSnapshot, &pe))
	{
		if (ProcessName == pe.szExeFile) {
			vProcessID.push_back(pe.th32ProcessID);
		}
	}

	::CloseHandle(hSnapshot);

	return vProcessID;
}

bool EnablePrivilege(WCHAR PrivilegeName[], BOOL IsEnable)
{
	HANDLE hToken = { 0 };
	LUID luid = { 0 };
	TOKEN_PRIVILEGES tp = { 0 };
	//开启权限控制
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY | TOKEN_READ, &hToken)) {
		return false;
	}
	//查看权限 NULL->本进程
	if (!LookupPrivilegeValueW(NULL, PrivilegeName, &luid))
	{
		return false;
	}

	tp.PrivilegeCount = 1;
	tp.Privileges[0].Luid = luid;
	tp.Privileges[0].Attributes = (IsEnable) ? SE_PRIVILEGE_ENABLED : 0;

	BOOL bSucc = AdjustTokenPrivileges(hToken, FALSE, &tp, NULL, NULL, NULL);
	CloseHandle(hToken);

	return (GetLastError() == ERROR_SUCCESS);
}

unsigned int __stdcall InJect_Thread(void* p) {

	CString* pCStrPath = (CString*)p;
	CString CStrPath = *pCStrPath;
	delete pCStrPath;
	if (!CStrPath.IsEmpty())
	{
		vector<CString> allPID = cstring_substr(CStrPath, _T(","));
		
		CStrPath.ReleaseBuffer();
		for (auto pid : allPID)
		{
			//注入游戏
			InJectDll(cstoul(pid), _T("xb.dll"));
		}
	}

	return 0;
}