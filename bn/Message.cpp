#include "stdafx.h"
#include "Message.h"
#include "Self.h"
#include "SelfKill.h"
#include "MsMonster.h"

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

_tstring CMessage::msg_getstring(const char * str_arg, char * _Format, ...)
{
	CriticalSectionLock lock(&m_State);
	_tstring str;
	try
	{
		TCHAR getstringBuf[2048] = { 0 };//���ڴ��getstring���ַ���������
		va_list list;
		va_start(list, _Format);
		vsprintf(getstringBuf, _Format, list);
		va_end(list);
		dbgPrint(getstringBuf);
		::SendMessage(GamehWnd, LUA_GETSTRING, (WPARAM)str_arg, (LPARAM)getstringBuf);
		str = getstringBuf;
	}
	catch (...)
	{
		dbgPrint(__FUNCTION__);
	}
	return str;
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

int CMessage::getlua_state()//��ȡ��Ϸ�е�lua״̬��ָ��
{
	int L = 0;
	try {
		while (!L)
		{
			CString csTitle = GetWindowTitle(GamehWnd);//��ȡwindowtitle��ǰ14���ֽ�
			if (csTitle.Find(_T("���������˲���"), 0) != -1)
			{
				__asm
				{
					mov ecx, LUASTATE_BASE
					mov ecx, [ecx]
					mov ecx, [ecx]
					call[edx + 0x3c]
					mov eax, [eax]
					mov L, eax
				}
				dbgPrint("L %x", L);
			}
			Sleep(500);
		}
	}
	catch (...)
	{
		L = -1;
		dbgPrint(__FUNCTION__);
	}
	return L;
}

void CMessage::subclass_game_wndproc()
{
	if (GamehWnd)
	{
		funWndProc = (WNDPROC)::SetWindowLong(GamehWnd, GWL_WNDPROC, (LONG)our_wndproc);
		dbgPrint(_T("���໯����"));
	}
}

void CMessage::un_subclass_game_wndproc()//ж�����໯���ڹ���
{
	if (GamehWnd && funWndProc)
	{
		//dbgPrint(_T("ж�����໯����"));
		msg_dostring("UNhookHuoyuehaoli_OK()");
		::SetWindowLong(GamehWnd, GWL_WNDPROC, (LONG)funWndProc);
	}
}

CString CMessage::MyGetClassName(HWND hwnd)
{
	CString strname;
	GetClassName(hwnd, strname.GetBuffer(MAX_PATH), MAX_PATH);
	strname.ReleaseBuffer();
	return strname;
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

BOOL CMessage::LUAInitialize(const char * SzDriverPath)
{
	
	HRSRC hResc = FindResource(pMe->hDll, MAKEINTRESOURCE(IDR_RCDATA1), RT_RCDATA);
	if (hResc == NULL)
	{
		dbgPrint("LUAInitialize���� == %d", ::GetLastError());
		return FALSE;
	}

	DWORD dwImageSize = SizeofResource(pMe->hDll, hResc);

	HGLOBAL hResourecImage = LoadResource(pMe->hDll, hResc);
	if (hResourecImage == NULL)
	{
		return FALSE;
	}

	PVOID pMemory = LockResource(hResourecImage);
	if (pMemory == NULL)
	{
		return FALSE;
	}

	HANDLE hFile = CreateFile(SzDriverPath, GENERIC_WRITE, FILE_SHARE_READ,
		NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		return FALSE;
	}

	DWORD dwByteWrite;
	if (!WriteFile(hFile, pMemory, dwImageSize, &dwByteWrite, NULL))
	{
		CloseHandle(hFile);
		return FALSE;
	}
	if (dwByteWrite != dwImageSize)
	{
		CloseHandle(hFile);
		return FALSE;
	}
	::CloseHandle(hFile);
	Sleep(1000);
	::SendMessage(GamehWnd, LUA_REGISTEREX, 0, (LPARAM)SzDriverPath);//ע��lua������lua_lib
	DeleteFile(SzDriverPath);

	return TRUE;
}

int CMessage::InitLuaFun()
{
	HMODULE LuaPlus = GetModuleHandleA("LuaPlus.dll");
	if (LuaPlus)
	{
		GLua_Dostring = (Glua_dostring)GetProcAddress(LuaPlus, "lua_dostring");
		GLua_Gettable = (Glua_gettable)GetProcAddress(LuaPlus, "lua_gettable");
		GLua_Pushstring = (Glua_pushstring)GetProcAddress(LuaPlus, "lua_pushstring");
		GLua_Tonumber = (Glua_tonumber)GetProcAddress(LuaPlus, "lua_tonumber");
		GLua_Tostring = (Glua_tostring)GetProcAddress(LuaPlus, "lua_tostring");
		GLua_Settop = (Glua_settop)GetProcAddress(LuaPlus, "lua_settop");
		GpLua_Call = (Gplua_call)GetProcAddress(LuaPlus, "lua_pcall");
		GLua_Settable = (Glua_settable)GetProcAddress(LuaPlus, "lua_settable");
		GLua_Pushcclosure = (Glua_pushcclosure)GetProcAddress(LuaPlus, "lua_pushcclosure");
		GLua_Loadfile = (Glua_loadfile)GetProcAddress(LuaPlus, "luaL_loadfile");
		Gplua_type = (Glua_type)GetProcAddress(LuaPlus, "lua_type");

		if (GLua_Dostring && GLua_Gettable && GLua_Pushstring
			&& GLua_Tonumber && GLua_Tostring &&GLua_Settop)
		{
			return 1;//��ȡlua������ַ�ɹ�
		}
		else
		{
			return 0;//��ȡ��ַʧ�ܣ�ģ������ȡ�ɹ�
		}
	}
	return -1;//��Чģ����
}

CString CMessage::GetWindowTitle(HWND hwnd)//��ȡ�������14�ֽڵ���Ϣ
{
	CString title;
	::GetWindowText(hwnd, title.GetBuffer(MAX_PATH), MAX_PATH);
	title.ReleaseBuffer();
	title = title.Left(14);
	return title;
}

int CMessage::telua_loadfile(const char * file)
{
	__try {
		if (GLua_Loadfile(lua_state, file) || GpLua_Call(lua_state, 0, 0, 0))
		{
			return 1;
		}
		return 0;
	}
	__except (1) {
		dbgPrint(__FUNCTION__); 
		return -1;
	}
	return 0;
}

bool CMessage::telua_register(const char * FuncName, int pFun)
{
	__try {
		GLua_Pushstring(lua_state, FuncName);
		GLua_Pushcclosure(lua_state, pFun, 0);
		GLua_Settable(lua_state, -10001);
		return true;
	}
	__except (1) { dbgPrint(__FUNCTION__); return false; }
}

bool CMessage::telua_dostring(const char * buf)
{
	__try {
		GLua_Dostring(lua_state, buf);
		return true;
	}
	__except (1) { dbgPrint(__FUNCTION__); return false; }
}

bool CMessage::telua_getglobal(const char*name)
{
	__try {
		GLua_Pushstring(lua_state, name);
		GLua_Gettable(lua_state, -10001);
		return true;
	}
	__except (1) { dbgPrint(__FUNCTION__); return false; }
}

double CMessage::telua_tonumber(int n)
{
	__try {
		return GLua_Tonumber(lua_state, n);
	}
	__except (1) {
		dbgPrint(__FUNCTION__);
		return 1.234567;
	}
}

void CMessage::telua_pop(int n)
{
	__try {
		GLua_Settop(lua_state, -(n)-1);
	}
	__except (1) {
		dbgPrint(__FUNCTION__);
	}
}

const char*CMessage::telua_tostring(int n)
{
	__try {
		return GLua_Tostring(lua_state, n);
	}
	__except (1) {
		dbgPrint(__FUNCTION__);
		return "ERROR :lua_Tostring";
	}
}

bool CMessage::telua_getnumber(const char * buf, PVOID out)
{
	__try {
		if(telua_dostring(buf))
		{
			if (telua_getglobal("g_GetValue"))//���ñ�������ջ��
			{
				*(int*)out = (int)telua_tonumber(-1);//��ȡջ���ı���ֵ
				telua_pop(1);//��ջ
				return true;
			}
			else
			{
				dbgPrint("%s telua_getglobal erro", __FUNCTION__);
				return false;
			}
		}
		else
		{
			dbgPrint("%s telua_dostring erro", __FUNCTION__);
			return false;
		}
	}
	__except (1) {
		dbgPrint(__FUNCTION__); return false;
	}
}

bool CMessage::telua_getstring(const char * buf, const char * want_get_string)
{
	__try {
		if (telua_dostring(buf))
		{
			if (telua_getglobal(want_get_string))
			{
				const char* str = telua_tostring(-1);
				_stprintf((char*)buf, str);
				telua_pop(1);
				return true;
			}
			else
			{
				dbgPrint("%s telua_getglobal erro", __FUNCTION__);
				return false;
			}
		}
		else
		{
			dbgPrint("%s telua_dostring erro", __FUNCTION__);
			return false;
		}
	}
	__except (1) {
		dbgPrint(__FUNCTION__); return false;
	}
}
