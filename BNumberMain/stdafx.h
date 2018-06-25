
// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // �� Windows ͷ���ų�����ʹ�õ�����
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // ĳЩ CString ���캯��������ʽ��

// �ر� MFC ��ĳЩ�����������ɷ��ĺ��Եľ�����Ϣ������
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC ��������ͱ�׼���
#include <afxext.h>         // MFC ��չ


#include <afxdisp.h>        // MFC �Զ�����



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC �� Internet Explorer 4 �����ؼ���֧��
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC �� Windows �����ؼ���֧��
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // �������Ϳؼ����� MFC ֧��









#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif

//������Ϣ
#define  WM_USER_NOTIFYICON WM_USER+111
#define  WM_USER_����������Ϣ  WM_USER + 112 
#define  WM_USER_״��  WM_USER + 113 
#define  WM_USER_SOCKET_���PID  WM_USER + 116 
#define  WM_USER_��ť״̬  WM_USER + 117 
extern HWND g_MyHwnd;

#include <WinSock.h>  //һ��Ҫ�������������winsock2.h
#include <vector>
#include <string>
#include <thread>
#include "HPClient.h"
#include "ServerCtrl.h"

#pragma comment(lib,"wsock32.lib")

#ifdef _DEBUG
#pragma comment(lib,"..\\HPSocket\\bin\\HPSocket_D.lib") 
#else
#pragma comment(lib,"..\\HPSocket\\bin\\HPSocket.lib") 
#endif // !_DEBUG
using namespace std;

extern  CHPClient* pHPClient;
//�׽��ַ����
extern  CServerCtrl* pMyServer;
CString tget_curpath(BOOL slash);
vector<CString>  cstring_substr(IN  CString _Source, IN  CString _Sub, BOOL bAll = 0);
vector<CString> tenum_inifile(IN  CString  _FilePath, IN  CString  _AppName);

//�������ַ���ת���ɽ����� ������Ϊ������ 1<x<36 ֻ���һ������ 123,asd ֻ�᷵�� 123
inline unsigned long cstoul(const CStringA& _Str, size_t* _Idx = 0, int _Base = 10) {
	const char *_Ptr = _Str;
	char *_Eptr;
	errno = 0;
	unsigned long _Ans = _CSTD strtoul(_Ptr, &_Eptr, _Base);
	
	if (_Ptr == _Eptr)
		_Xinvalid_argument("invalid stoul argument");
	if (errno == ERANGE)
		_Xout_of_range("stoul argument out of range");
	if (_Idx != 0)
		*_Idx = (size_t)(_Eptr - _Ptr);
	return (_Ans);
}

inline unsigned long cstoul(const CStringW& _Str, size_t *_Idx = 0,
	int _Base = 10)
{	// convert wstring to unsigned long
	const wchar_t *_Ptr = _Str;
	wchar_t *_Eptr;
	errno = 0;
	unsigned long _Ans = _CSTD wcstoul(_Ptr, &_Eptr, _Base);

	if (_Ptr == _Eptr)
		_Xinvalid_argument("invalid stoul argument");
	if (errno == ERANGE)
		_Xout_of_range("stoul argument out of range");
	if (_Idx != 0)
		*_Idx = (size_t)(_Eptr - _Ptr);
	return (_Ans);
}

#ifdef UNICODE
#define to_cstring  to_cstrw
#else
#define to_cstring  to_cstra
#endif // !UNICODE
class CriticalSectionLock
{
	/************************************************************************/
	/*�ٽ����߳�ͬ����                                                */
	/************************************************************************/
public:
	CriticalSectionLock(CCriticalSection* cs)
	{
		cs->Lock();//�����ٽ���
		m_cs = cs;
	}
	~CriticalSectionLock()
	{
		m_cs->Unlock();//�����ٽ���
	}
private:
	CCriticalSection* m_cs;
};