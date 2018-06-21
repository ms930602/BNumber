#pragma once
#include <atomic>
using namespace std;
class CBNCtrl
{
public:
	CBNCtrl();
	~CBNCtrl();

public:
	void EndThread();
public:
	friend UINT __stdcall UI_ThradFunc(LPVOID p);//UI �̺߳���
	friend UINT __stdcall KillMonster_ThreadFunc(LPVOID p);//�����̺߳���
	friend UINT __stdcall Login_ThreadFunc(void* p);//��¼�̺߳���
	friend UINT __stdcall Protecd_ThreadFunc(void* p);//�����̺߳���
	friend UINT __stdcall Task_ThreadFunc(void* p);//�ű������̺߳���
public:
	void CreateUI();
	void CreateKillMonster();
	void CreateLogin();
	void CreateProtect();
	void CreateTask();
public:
	HMODULE hDll;//���
public:
	HANDLE hKillThread;
	HANDLE hUIThread;
	HANDLE hProtectThread;
	HANDLE hTaskThread;
	HANDLE hMapFile;
public:
	bool bLogin;
	bool bUiThread;
	bool bKillThread;
	bool bRun;
	bool bProtectRun;
	bool bTaskThread;//�����̱߳�־
public:
	atomic_int atomic_int_work_thread;//�̼߳�����
};