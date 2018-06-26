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

	//�����ڴ� 

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
	//DLL·��д��Ŀ�����
	BOOL bWirte = WriteProcessMemory(hProcess, lpBassAddr, curPath, MAX_PATH, NULL);
	if (!bWirte)
	{
		CloseHandle(hProcess);
		return FALSE;
	}

	//ʹ��Զ���̼߳��ظý��̵ĺ�������dll
	HANDLE hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, lpBassAddr, 0, NULL);

	if (!hThread)
	{
		CloseHandle(hProcess);
		return FALSE;
	}

	//�ȴ�Զ���߳�ִ�����
	WaitForSingleObject(hThread, INFINITE);

	//����������ڴ�
	VirtualFreeEx(hProcess, lpBassAddr, 4096, MEM_DECOMMIT);

	CloseHandle(hProcess);

	return 0;
}

vector<DWORD> GetNameProcessId(CString ProcessName)
{
	vector<DWORD> vProcessID;
	//���ջ����� ��ȡȫ�����̵����ջ�������
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (INVALID_HANDLE_VALUE == hSnapshot)
	{
		return vProcessID;
	}
	PROCESSENTRY32 pe = { sizeof(pe) };
	BOOL fOk;

	// ö���б��еĵ�һ������
	BOOL bProcess = Process32First(hSnapshot, &pe);
	while (bProcess)
	{
		// �ȽϽ��������ҵ�Ҫ�ҵĽ�����
		if (ProcessName.CompareNoCase(pe.szExeFile) == 0)
		{
			TRACE(pe.szExeFile);
			vProcessID.push_back(pe.th32ProcessID);
		}
		// ��������
		bProcess = Process32Next(hSnapshot, &pe);
	}

	::CloseHandle(hSnapshot);

	return vProcessID;
}

bool EnablePrivilege(WCHAR PrivilegeName[], BOOL IsEnable)
{
	HANDLE hToken = { 0 };
	LUID luid = { 0 };
	TOKEN_PRIVILEGES tp = { 0 };
	//����Ȩ�޿���
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY | TOKEN_READ, &hToken)) {
		return false;
	}
	//�鿴Ȩ�� NULL->������
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
			//ע����Ϸ
			InJectDll(cstoul(pid), _T("xb.dll"));
		}
	}

	return 0;
}