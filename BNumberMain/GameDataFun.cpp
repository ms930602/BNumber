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
		CstrText = "����";
	}
	else if (nState == 2)
	{
		CstrText = "�ƶ�";
	}
	else if (nState == 5)
	{
		CstrText = "�س�";
	}
	else if (nState == 6)
	{
		CstrText = "�������ҩ";
	}
	else if (nState == 7)
	{
		CstrText = "ɱ��";
	}
	else if (nState == 8)
	{
		CstrText = "�ɼ�";
	}
	else if (nState == 9)
	{
		CstrText = "����";
	}
	else if (nState == 10)
	{
		CstrText = " ��̯";
	}

	return CstrText;
}

CString GetRoleMenPai(INT nMenpai)
{
	CString Cstr;
	if (nMenpai == 0)
		Cstr = "����";
	else if (nMenpai == 1)
		Cstr = "����";
	else if (nMenpai == 2)
		Cstr = "ؤ��";
	else if (nMenpai == 3)
		Cstr = "�䵱";
	else if (nMenpai == 4)
		Cstr = "����";
	else if (nMenpai == 5)
		Cstr = "����";
	else if (nMenpai == 6)
		Cstr = "����";
	else if (nMenpai == 7)
		Cstr = "��ɽ";
	else if (nMenpai == 8)
		Cstr = "��ң";
	else if (nMenpai == 10)
		Cstr = "Ľ��";
	else if (nMenpai == 11)
		Cstr = "����";
	else
		Cstr = "������";

	return Cstr;
}
