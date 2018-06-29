#include "stdafx.h"
#include "Message.h"
#include "Self.h"

extern UI* pUI;
extern CMessage* pMsg;
extern CSelf* pMe;
//extern  luahelp* pluahelp;
extern CFileSystem* pFileSystem;
extern CMsRole* pAsmRole;
extern CMsSkill* pAsmSkill;

int MyLuaRegisterToGame(int a)
{
	pMe->CreatAgainLogin();
	return 0;
}

int MyLuaDBGPrint(int a)
{
	dbgPrint(pMsg->telua_tostring(-1));
	TRACE("错误日志--->");
	return 0;
}

void CMessage::msg_dostring(const char * _Format, ...)
{
	CriticalSectionLock lock(&m_State);
	try
	{
		TCHAR do_stringBuf[2048] = { 0 };//用于存放do_string的字符串缓冲区
		va_list list;
		va_start(list, _Format);
		vsprintf(do_stringBuf, _Format, list);
		::SendMessage(GamehWnd, LUA_MEASSAGE, 0, (LPARAM)do_stringBuf);
	}
	catch (...)
	{
		dbgPrint(__FUNCTION__);
	}
}

int CMessage::msg_getnumber(char * _Format, ...)
{
	CriticalSectionLock lock(&m_State);

	int nValue = 0;
	try
	{
		TCHAR getnumberBuf[2048] = { 0 };//用于存放getnumber的字符串缓冲区
		va_list list;
		va_start(list, _Format);
		vsprintf(getnumberBuf, _Format, list);
		va_end(list);
		::SendMessage(GamehWnd, LUA_GETVALUE, (WPARAM)&nValue, (LPARAM)getnumberBuf);
	}
	catch (...)
	{
		dbgPrint(__FUNCTION__);
	}

	return nValue;
}

LRESULT CMessage::our_wndproc(HWND hWnd, UINT wMsg, WPARAM wParam, LPARAM lParam)
{
	switch (wMsg)
	{
	case LUA_MEASSAGE: {
		pMsg->telua_dostring((char*)lParam);
	}
	break;
	case LUA_GETVALUE: {
		pMsg->telua_getnumber((char*)lParam, (PVOID)wParam);
	}
	break;
	case LUA_GETSTRING: {
		pMsg->telua_getstring((char*)lParam, (char*)wParam);
	}
	break;
	case LUA_REGISTEREX: {//加载注册lua lib文件
		pMsg->telua_loadfile((char*)lParam);
		pMsg->telua_register("myluaregstertogame", (int)MyLuaRegisterToGame);
		pMsg->telua_register("myluadbgprint", (int)MyLuaDBGPrint);
	}
    break;
	default:
		break;
	}
	//////////////////////////////////////////////////////////////////////////
	/////////////////////////////辅助窗口的显示相关//////////////////////////
	if (wMsg == WM_KEYDOWN&&wParam == VK_HOME//判断热键
		&&pUI&&pUI->m_hWnd&&::IsWindow(pUI->m_hWnd))//判断窗口是否创建好了
	{
		if (::IsWindowVisible(pUI->m_hWnd))//判断窗口状态可见就隐藏这个窗口
		{
			::ShowWindow(pUI->m_hWnd, SW_HIDE);
		}
		else
		{
			::SendMessage(pUI->m_hWnd, WM_MYSTYLEEX_MESSAGE, 0, 0);//弹出辅助窗口并置顶
		}
	}
	return ::CallWindowProc(pMsg->funWndProc, hWnd, wMsg, wParam, lParam);
}

void CMessage::subclass_game_wndproc()
{
	if (GamehWnd)
	{
		funWndProc = (WNDPROC)::SetWindowLong(GamehWnd, GWL_WNDPROC, (LONG)our_wndproc);
		dbgPrint(_T("子类化窗口"));
	}
}

HWND CMessage::GetGameWindow()
{
	while (true)
	{
		DWORD dwCurPId = ::GetCurrentProcessId();
		HWND hWnd = ::GetTopWindow(NULL);//获取顶层窗口句柄
		while (hWnd)
		{
			DWORD dwPid = 0;
			::GetWindowThreadProcessId(hWnd, &dwPid);//找出某个窗口的创建者线程或进程返回创建者的标志
			if (dwCurPId == dwPid)
			{
				if (::GetParent(hWnd) == 0)//检查这个窗口是否有父窗口 如果没有则进入if中去
				{
					if (MyGetClassName(hWnd) == "TianLongBaBu WndClass")//对比窗口类名是不是游戏的类
					{
						GamehWnd = hWnd;
						return GamehWnd;
					}
				}
			}
			hWnd = ::GetNextWindow(hWnd, GW_HWNDNEXT);//获取下一个窗口句柄
		}
		Sleep(1000);
	}
	return NULL;
}

int CMessage::InitLuaFun()
{
	return 0;
}
