
// stdafx.cpp : 只包括标准包含文件的源文件
// BNumberMain.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

//获取当前程序路径 真带后面的// 
CString tget_curpath(BOOL slash)
{
	/************************************************************************
	获取路径
	************************************************************************/
	TCHAR lpBuffer[MAX_PATH] = { 0 };
	if (GetModuleFileName(
		NULL,
		lpBuffer,
		MAX_PATH
	) == NULL)
	{
		return CString();
	}

	CString CStrPath(lpBuffer);
	int npos = CStrPath.ReverseFind(_T('\\'));//逆向查找
	if (npos != -1)
	{
		if (slash == TRUE)
			CStrPath = CStrPath.Mid(0, npos + 1);//截取从0开始的字符串保留斜杠
		else
			CStrPath = CStrPath.Mid(0, npos);//截取从0开始的字符串不要斜杠
											 //dbgPrint(_T("%s::\t\t %s\n"), CString(__FUNCTION__), CStrPath);
	}

	return CStrPath;
}