
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

/************************************************************************
// 功能： 提取CString中全部匹配的_Sub指定的字符中间的字串 返回子字符串容器
// 参数:  _Source：字符串源
//        _Sub:  分隔符字符串
************************************************************************/
vector<CString>  cstring_substr(IN  CString _Source, IN  CString _Sub, BOOL bAll)
{
	vector<CString> _AllSubstr;
	if (_Source.IsEmpty())//空串直接返回
		return _AllSubstr;

	//最后一个字符设置为_Sub
	CString str = _Source;
	CString str2 = str.Right(1);

	if (str2 != _Sub)
	{
		str = str + _Sub;
		////dbgPrint("字符串追加 %s",_Sub);
	}

	int nStart = 0, nFirst = 0;
	while ((nFirst = str.Find(_Sub, nStart)) != -1)
	{
		CString _substr = str.Mid(nStart, nFirst - nStart);//切割字符串
		nStart = nFirst + 1;

		if (!bAll)//空字符串不要
		{
			if (_substr.IsEmpty())
			{
				continue;
			}
		}

		////dbgPrint(_T("%s \n"), _substr);
		_AllSubstr.push_back(_substr);
	}

	return _AllSubstr;
}