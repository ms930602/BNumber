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
	friend UINT __stdcall UI_ThreadFunc(LPVOID p);//UI �̺߳���
	friend UINT __stdcall KillMonster_ThreadFunc(LPVOID p);//�����̺߳���
	friend UINT __stdcall Login_ThreadFunc(void* p);//��¼�̺߳���
	friend UINT __stdcall Protecd_ThreadFunc(void* p);//�����̺߳���
	friend UINT __stdcall Task_ThreadFunc(void* p);//�ű������̺߳���
	friend UINT __stdcall Login_AgainFunc(void* p);//��¼�̺߳���
public:
	void CreatUI();//����UI
	void CreatKillMonster();//����ɱ���߳�
	void CreatLogin(int nNUM);//������¼�߳�
	void CreatProtect();//���������߳�
	void CreatTask(int nType);//����Task�߳�
	void CreatAgainLogin();//�����л���ɫ���߳�
public:
	HMODULE hDll;//���
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
	bool bTaskThread;//�����̱߳�־
public:
	atomic_int atomic_int_work_thread;//�̼߳�����
};