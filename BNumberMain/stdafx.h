
// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 从 Windows 头中排除极少使用的资料
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 某些 CString 构造函数将是显式的

// 关闭 MFC 对某些常见但经常可放心忽略的警告消息的隐藏
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC 核心组件和标准组件
#include <afxext.h>         // MFC 扩展


#include <afxdisp.h>        // MFC 自动化类



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC 对 Internet Explorer 4 公共控件的支持
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC 对 Windows 公共控件的支持
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // 功能区和控件条的 MFC 支持









#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif

//托盘消息
#define  WM_USER_NOTIFYICON WM_USER+111
#define  WM_USER_人物属性信息  WM_USER + 112 
#define  WM_USER_状况  WM_USER + 113 
#define  WM_USER_SOCKET_添加PID  WM_USER + 116 
#define  WM_USER_按钮状态  WM_USER + 117 
extern HWND g_MyHwnd;

#include <WinSock.h>  //一定要包含这个，或者winsock2.h
#include <vector>
#include <string>
#include <thread>
#include "HPClient.h"
#include "ServerCtrl.h"
#include "GameDataFun.h"

#pragma comment(lib,"wsock32.lib")

#ifdef _DEBUG
#pragma comment(lib,"..\\HPSocket\\bin\\HPSocket_D.lib") 
#else
#pragma comment(lib,"..\\HPSocket\\bin\\HPSocket.lib") 
#endif // !_DEBUG
using namespace std;

extern  CHPClient* pHPClient;
//套接字服务端
extern  CServerCtrl* pMyServer;
CString tget_curpath(BOOL slash);
vector<CString>  cstring_substr(IN  CString _Source, IN  CString _Sub, BOOL bAll = 0);
vector<CString> tenum_inifile(IN  CString  _FilePath, IN  CString  _AppName);

//将数字字符串转换成进制数 最后参数为几进制 1<x<36 只填第一个参数 123,asd 只会返回 123
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

inline CStringA to_cstra(unsigned int _Val)
{	// convert unsigned int to string
	CStringA f;
	f.Format("%d", _Val);
	return f;
}


class CriticalSectionLock
{
	/************************************************************************/
	/*临界区线程同步类                                                */
	/************************************************************************/
public:
	CriticalSectionLock(CCriticalSection* cs)
	{
		cs->Lock();//进入临界区
		m_cs = cs;
	}
	~CriticalSectionLock()
	{
		m_cs->Unlock();//交出临界区
	}
private:
	CCriticalSection* m_cs;
};