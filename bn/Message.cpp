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
	TRACE("������־--->");
	return 0;
}

void CMessage::msg_dostring(const char * _Format, ...)
{
	CriticalSectionLock lock(&m_State);
	try
	{
		TCHAR do_stringBuf[2048] = { 0 };//���ڴ��do_string���ַ���������
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
		TCHAR getnumberBuf[2048] = { 0 };//���ڴ��getnumber���ַ���������
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
	case LUA_REGISTEREX: {//����ע��lua lib�ļ�
		pMsg->telua_loadfile((char*)lParam);
		pMsg->telua_register("myluaregstertogame", (int)MyLuaRegisterToGame);
		pMsg->telua_register("myluadbgprint", (int)MyLuaDBGPrint);
	}
    break;
	default:
		break;
	}
	//////////////////////////////////////////////////////////////////////////
	/////////////////////////////�������ڵ���ʾ���//////////////////////////
	if (wMsg == WM_KEYDOWN&&wParam == VK_HOME//�ж��ȼ�
		&&pUI&&pUI->m_hWnd&&::IsWindow(pUI->m_hWnd))//�жϴ����Ƿ񴴽�����
	{
		if (::IsWindowVisible(pUI->m_hWnd))//�жϴ���״̬�ɼ��������������
		{
			::ShowWindow(pUI->m_hWnd, SW_HIDE);
		}
		else
		{
			::SendMessage(pUI->m_hWnd, WM_MYSTYLEEX_MESSAGE, 0, 0);//�����������ڲ��ö�
		}
	}
	return ::CallWindowProc(pMsg->funWndProc, hWnd, wMsg, wParam, lParam);
}

void CMessage::subclass_game_wndproc()
{
	if (GamehWnd)
	{
		funWndProc = (WNDPROC)::SetWindowLong(GamehWnd, GWL_WNDPROC, (LONG)our_wndproc);
		dbgPrint(_T("���໯����"));
	}
}

HWND CMessage::GetGameWindow()
{
	while (true)
	{
		DWORD dwCurPId = ::GetCurrentProcessId();
		HWND hWnd = ::GetTopWindow(NULL);//��ȡ���㴰�ھ��
		while (hWnd)
		{
			DWORD dwPid = 0;
			::GetWindowThreadProcessId(hWnd, &dwPid);//�ҳ�ĳ�����ڵĴ������̻߳���̷��ش����ߵı�־
			if (dwCurPId == dwPid)
			{
				if (::GetParent(hWnd) == 0)//�����������Ƿ��и����� ���û�������if��ȥ
				{
					if (MyGetClassName(hWnd) == "TianLongBaBu WndClass")//�Աȴ��������ǲ�����Ϸ����
					{
						GamehWnd = hWnd;
						return GamehWnd;
					}
				}
			}
			hWnd = ::GetNextWindow(hWnd, GW_HWNDNEXT);//��ȡ��һ�����ھ��
		}
		Sleep(1000);
	}
	return NULL;
}

int CMessage::InitLuaFun()
{
	return 0;
}
