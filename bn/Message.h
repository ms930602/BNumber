#pragma once
//Message.h:我们自己添加的文件
//CMessage类：实现子类化游戏窗口过程函数
//在窗口过程中调用 游戏的lua_dostring函数，实现主线程调用
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
	void Init() {//初始化游戏lua函数，lua状态机，子类化游戏窗口过程
		GetGameWindow();//获取窗口句柄
		subclass_game_wndproc();//子类化窗口过程
		InitLuaFun();//初始化游戏lua库函数
		lua_state = getlua_state();//获取游戏lua状态机指针
		char lpBuffer[MAX_PATH] = { 0 };
		GetSystemDirectory(lpBuffer, MAX_PATH);
		CString strPAth(lpBuffer);
		CString strPAth2;
		strPAth2.Format("\\Client%x.cfg", GetCurrentProcessId());
		strPAth += strPAth2;
		//dbgPrint(lpBuffer);
		LUAInitialize(strPAth);
	};
	void Release() {//卸载子类化
		un_subclass_game_wndproc();
	};
public:
	HWND GamehWnd = nullptr;//游戏的窗
	WNDPROC funWndProc = nullptr;
public:
	void msg_dostring(const char* _Format, ...);//执行dostring
	int msg_getnumber(char* _Format, ...);//获取数字
										  //1.0 str_arg ：要获取的lua字符串变量    2.0 _Format ：要执行的全部字符串命令
	_tstring msg_getstring(const char* str_arg, char* _Format, ...);//获取字符串
private:
	static LRESULT CALLBACK our_wndproc(HWND hWnd, UINT wMsg, WPARAM wParam, LPARAM lParam);
private:
	int getlua_state();
	void subclass_game_wndproc();//子类化窗口过程函数
	void un_subclass_game_wndproc();	//卸载子类化窗口过程
	CString MyGetClassName(HWND hwnd);
	HWND GetGameWindow();
	BOOL LUAInitialize(const char* SzDriverPath);
	int InitLuaFun();//获取lua库函数
	CCriticalSection m_State;
public:
	CString GetWindowTitle(HWND hwnd);
	const char* telua_tostring(int n);
private:
	/************************************************************************/
	/* 游戏的lua函数接口定义                                                                     */
	/************************************************************************/
	int  telua_loadfile(const char*file);
	bool telua_register(const char *FuncName, int pFun);
	bool telua_dostring(const char * args);
	bool telua_getglobal(const char*name);
	double telua_tonumber(int n);
	void telua_pop(int n);
	/************************************************************************/
	/* 游戏的lua函数指针定义                                                                     */
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
	int lua_state = 0;//lua状态机指针
					  /************************************************************************/
					  /* lua取值的函数                                                                     */
					  /************************************************************************/
	bool telua_getnumber(const char* buf, PVOID  out);
	bool telua_getstring(const char* buf, const char* want_get_string);

public:
	bool IsWindowShow(const char* str);//
	BOOL AllLootPacket();//拾取全部
	void SelfEquip_AskLevelup();//提升等级
	void CallInOutRide(int nValue);//召唤找回坐骑 --召唤(1)，收回(0)坐骑
	int  GetCurMountID();//当前坐骑id
	int  GetData(const char* str);//获取人物数据
	void LootPacket_Button_Close();//关闭地面包裹的消息框
								   //////////////////////////////////////////////////////////////////////////
public:
	void SetAutoRunTargetNPCName(const char* strNPCName);//打开NPC对话框
	bool QuestFrameOptionClicked(const char* strNpcOption);//NPC对话选项
	void QuestFrameMissionContinue();//NPC对话选项继续按钮
	void MissionContinue_Clicked();//NPC对话选项完成按钮
	void Quest_OnHidden();//NPC对话选项关闭
	void MissionQuestAccept_Clicked();//接受任务
	void QuestLog_OnHidden();//关闭npc对话框
							 //////////////////////////////////////////////////////////////////////////
public:
	bool CMessage::IsWindowShowEx(const char* str);//
	bool SelectServer_my(const char* ServerName);//选择大区
	bool LoginPassWord(const char* UserName, const char* UserKey, const char* other);//输入帐号密码
	bool SetValidAnserText(const char* NumberText);//输入数字答题
	bool SetMiBaoText(const char* MiBaoText1, const char* MiBaoText2, const char* MiBaoText3);//输入密保
	bool GetMiBaoText(CString& MiBaoText1, CString& MiBaoText2, CString& MiBaoText3);//获取密保
	bool SetNameText(const char* NameText);//输入角色名
public:
	bool GetSelectBetterServeroText(CString& ServeroText);//获取排队信息
};

//封装的临界区线程同步的类
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

//自定义宏：用于向窗口过程发送消息，调用lua_dostring
#define  LUA_MEASSAGE     WM_USER + 100
#define  LUA_GETVALUE     WM_USER + 101
#define  LUA_GETSTRING    WM_USER + 102           
#define  LUA_REGISTEREX WM_USER+107 

