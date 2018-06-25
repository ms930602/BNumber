#include "stdafx.h"
#include "GameDataFun.h"

CString MyGetFilePathName(CString strFileName)
{
	auto strPath = tget_curpath(TRUE);
	strPath += strFileName;

	return strPath;
}


CString GetRoleState(INT nState)
{
	CString CstrText;
	if (nState == 0)
	{
		CstrText = "不动";
	}
	else if (nState == 2)
	{
		CstrText = "移动";
	}
	else if (nState == 5)
	{
		CstrText = "回城";
	}
	else if (nState == 6)
	{
		CstrText = "打坐或吃药";
	}
	else if (nState == 7)
	{
		CstrText = "杀怪";
	}
	else if (nState == 8)
	{
		CstrText = "采集";
	}
	else if (nState == 9)
	{
		CstrText = "死亡";
	}
	else if (nState == 10)
	{
		CstrText = " 摆摊";
	}

	return CstrText;
}

CString GetRoleMenPai(INT nMenpai)
{
	CString Cstr;
	if (nMenpai == 0)
		Cstr = "少林";
	else if (nMenpai == 1)
		Cstr = "明教";
	else if (nMenpai == 2)
		Cstr = "丐帮";
	else if (nMenpai == 3)
		Cstr = "武当";
	else if (nMenpai == 4)
		Cstr = "峨嵋";
	else if (nMenpai == 5)
		Cstr = "星宿";
	else if (nMenpai == 6)
		Cstr = "天龙";
	else if (nMenpai == 7)
		Cstr = "天山";
	else if (nMenpai == 8)
		Cstr = "逍遥";
	else if (nMenpai == 10)
		Cstr = "慕容";
	else if (nMenpai == 11)
		Cstr = "唐门";
	else
		Cstr = "无门派";

	return Cstr;
}
