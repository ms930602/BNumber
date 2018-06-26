
// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// BNumberMain.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

CHPClient* pHPClient = nullptr;
CServerCtrl* pMyServer = nullptr;

//��ȡ��ǰ����·�� ��������// 
CString tget_curpath(BOOL slash)
{
	/************************************************************************
	��ȡ·��
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
	int npos = CStrPath.ReverseFind(_T('\\'));//�������
	if (npos != -1)
	{
		if (slash == TRUE)
			CStrPath = CStrPath.Mid(0, npos + 1);//��ȡ��0��ʼ���ַ�������б��
		else
			CStrPath = CStrPath.Mid(0, npos);//��ȡ��0��ʼ���ַ�����Ҫб��
											 //dbgPrint(_T("%s::\t\t %s\n"), CString(__FUNCTION__), CStrPath);
	}

	return CStrPath;
}

/************************************************************************
// ���ܣ� ��ȡCString��ȫ��ƥ���_Subָ�����ַ��м���ִ� �������ַ�������
// ����:  _Source���ַ���Դ
//        _Sub:  �ָ����ַ���
************************************************************************/
vector<CString>  cstring_substr(IN  CString _Source, IN  CString _Sub, BOOL bAll)
{
	vector<CString> _AllSubstr;
	if (_Source.IsEmpty())//�մ�ֱ�ӷ���
		return _AllSubstr;

	//���һ���ַ�����Ϊ_Sub
	CString str = _Source;
	CString str2 = str.Right(1);

	if (str2 != _Sub)
	{
		str = str + _Sub;
		////dbgPrint("�ַ���׷�� %s",_Sub);
	}

	int nStart = 0, nFirst = 0;
	while ((nFirst = str.Find(_Sub, nStart)) != -1)
	{
		CString _substr = str.Mid(nStart, nFirst - nStart);//�и��ַ���
		nStart = nFirst + 1;

		if (!bAll)//���ַ�����Ҫ
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

/************************************************************************
ö��ָ����ǩ�����еļ�ֵ���ı�����
************************************************************************/
vector<CString> tenum_inifile(IN CString _FilePath, IN CString _AppName)
{
	vector<CString> AllServer;
	CString CStrAppName(_AppName);
	CString CStrFilePath(_FilePath);
	TCHAR strKeyNameTemp[1024] = { 0 };//��Ӧÿ��AppName������KeyName�ķ���ֵ
	DWORD dwKeyNameSize = GetPrivateProfileString(CStrAppName, NULL, NULL, strKeyNameTemp, 1024, CStrFilePath);
	TCHAR *pKeyName = new TCHAR[dwKeyNameSize];
	TCHAR strReturnTemp[1024] = { 0 };//����ֵ
	int nKeyNameLen = 0;    //ÿ��KeyName�ĳ���
	for (UINT j = 0; j < dwKeyNameSize; j++)
	{
		pKeyName[nKeyNameLen++] = strKeyNameTemp[j];
		if (strKeyNameTemp[j] == _T('\0'))
		{
			if (GetPrivateProfileString(CStrAppName, pKeyName, NULL, strReturnTemp, 1024, CStrFilePath))
			{
				memset(pKeyName, 0, dwKeyNameSize);
			}
			nKeyNameLen = 0;
			AllServer.push_back(strReturnTemp);
			////dbgPrint(_T("%s::\t\t %s\n"), CString(__FUNCTION__), strReturnTemp);
		}
	}
	delete[]pKeyName;

	return AllServer;
}
