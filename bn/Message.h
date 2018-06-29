#pragma once
//Message.h:�����Լ���ӵ��ļ�
//CMessage�ࣺʵ�����໯��Ϸ���ڹ��̺���
//�ڴ��ڹ����е��� ��Ϸ��lua_dostring������ʵ�����̵߳���
#include <afxmt.h>
#include "Function.h"
#include "Login.h"

typedef int(*Glua_dostring)(int, const char *);//do_string
typedef int(*Glua_pushstring)(int, const char *);//pushstring
typedef void(*Glua_gettable)(int, int);//gettable
typedef double(*Glua_tonumber)(int, double);//tonumber
typedef int(*Glua_settop)(int, int);//settop
typedef const char*(*Glua_tostring)(int, int);//tostring
typedef int(*Glua_pushcclosure)(int, int, int);//
typedef void(*Glua_settable)(int, int);
typedef int(*Glua_loadfile)(int, const char*);
typedef int(*Gplua_call)(int, int, int, int);
typedef int(*Glua_type)(int, int);


class CMessage
{
public:
	CMessage() {};
	~CMessage() {};
	void Init() {//��ʼ����Ϸlua������lua״̬�������໯��Ϸ���ڹ���
		GetGameWindow();//��ȡ���ھ��
		subclass_game_wndproc();//���໯���ڹ���
		InitLuaFun();//��ʼ����Ϸlua�⺯��
		lua_state = getlua_state();//��ȡ��Ϸlua״̬��ָ��
		char lpBuffer[MAX_PATH] = { 0 };
		GetSystemDirectory(lpBuffer, MAX_PATH);
		CString strPAth(lpBuffer);
		CString strPAth2;
		strPAth2.Format("\\Client%x.cfg", GetCurrentProcessId());
		strPAth += strPAth2;
		//dbgPrint(lpBuffer);
		LUAInitialize(strPAth);
	};
	void Release() {//ж�����໯
		un_subclass_game_wndproc();
	};
public:
	HWND GamehWnd = nullptr;//��Ϸ�Ĵ�
	WNDPROC funWndProc = nullptr;
public:
	void msg_dostring(const char* _Format, ...);//ִ��dostring
	int msg_getnumber(char* _Format, ...);//��ȡ����
										  //1.0 str_arg ��Ҫ��ȡ��lua�ַ�������    2.0 _Format ��Ҫִ�е�ȫ���ַ�������
	_tstring msg_getstring(const char* str_arg, char* _Format, ...);//��ȡ�ַ���
private:
	static LRESULT CALLBACK our_wndproc(HWND hWnd, UINT wMsg, WPARAM wParam, LPARAM lParam);
private:
	int getlua_state();
	void subclass_game_wndproc();//���໯���ڹ��̺���
	void un_subclass_game_wndproc();	//ж�����໯���ڹ���
	CString MyGetClassName(HWND hwnd);
	HWND GetGameWindow();
	BOOL LUAInitialize(const char* SzDriverPath);
	int InitLuaFun();//��ȡlua�⺯��
	CCriticalSection m_State;
public:
	CString GetWindowTitle(HWND hwnd);
	const char* telua_tostring(int n);
private:
	/************************************************************************/
	/* ��Ϸ��lua�����ӿڶ���                                                                     */
	/************************************************************************/
	int  telua_loadfile(const char*file);
	bool telua_register(const char *FuncName, int pFun);
	bool telua_dostring(const char * args);
	bool telua_getglobal(const char*name);
	double telua_tonumber(int n);
	void telua_pop(int n);
	/************************************************************************/
	/* ��Ϸ��lua����ָ�붨��                                                                     */
	/************************************************************************/
	Glua_dostring GLua_Dostring = nullptr;
	Glua_pushstring GLua_Pushstring = nullptr;
	Glua_gettable GLua_Gettable = nullptr;
	Glua_tonumber GLua_Tonumber = nullptr;
	Glua_settop   GLua_Settop = nullptr;
	Glua_tostring GLua_Tostring = nullptr;
	Glua_pushcclosure GLua_Pushcclosure = nullptr;
	Glua_settable	GLua_Settable = nullptr;
	Glua_loadfile	GLua_Loadfile = nullptr;
	Gplua_call	  GpLua_Call = nullptr;
	Glua_type   Gplua_type = nullptr;
	int lua_state = 0;//lua״̬��ָ��
					  /************************************************************************/
					  /* luaȡֵ�ĺ���                                                                     */
					  /************************************************************************/
	bool telua_getnumber(const char* buf, PVOID  out);
	bool telua_getstring(const char* buf, const char* want_get_string);

public:
	bool IsWindowShow(const char* str);//
	BOOL AllLootPacket();//ʰȡȫ��
	void SelfEquip_AskLevelup();//�����ȼ�
	void CallInOutRide(int nValue);//�ٻ��һ����� --�ٻ�(1)���ջ�(0)����
	int  GetCurMountID();//��ǰ����id
	int  GetData(const char* str);//��ȡ��������
	void LootPacket_Button_Close();//�رյ����������Ϣ��
								   //////////////////////////////////////////////////////////////////////////
public:
	void SetAutoRunTargetNPCName(const char* strNPCName);//��NPC�Ի���
	bool QuestFrameOptionClicked(const char* strNpcOption);//NPC�Ի�ѡ��
	void QuestFrameMissionContinue();//NPC�Ի�ѡ�������ť
	void MissionContinue_Clicked();//NPC�Ի�ѡ����ɰ�ť
	void Quest_OnHidden();//NPC�Ի�ѡ��ر�
	void MissionQuestAccept_Clicked();//��������
	void QuestLog_OnHidden();//�ر�npc�Ի���
							 //////////////////////////////////////////////////////////////////////////
public:
	bool CMessage::IsWindowShowEx(const char* str);//
	bool SelectServer_my(const char* ServerName);//ѡ�����
	bool LoginPassWord(const char* UserName, const char* UserKey, const char* other);//�����ʺ�����
	bool SetValidAnserText(const char* NumberText);//�������ִ���
	bool SetMiBaoText(const char* MiBaoText1, const char* MiBaoText2, const char* MiBaoText3);//�����ܱ�
	bool GetMiBaoText(CString& MiBaoText1, CString& MiBaoText2, CString& MiBaoText3);//��ȡ�ܱ�
	bool SetNameText(const char* NameText);//�����ɫ��
public:
	bool GetSelectBetterServeroText(CString& ServeroText);//��ȡ�Ŷ���Ϣ
};

//��װ���ٽ����߳�ͬ������
class CriticalSectionLock
{
public:
	CriticalSectionLock(CCriticalSection* cs)
	{
		m_cs = cs;
		m_cs->Lock();
	}
	~CriticalSectionLock()
	{
		m_cs->Unlock();
	}
private:
	CCriticalSection* m_cs;
};

//�Զ���꣺�����򴰿ڹ��̷�����Ϣ������lua_dostring
#define  LUA_MEASSAGE     WM_USER + 100
#define  LUA_GETVALUE     WM_USER + 101
#define  LUA_GETSTRING    WM_USER + 102           
#define  LUA_REGISTEREX WM_USER+107 

