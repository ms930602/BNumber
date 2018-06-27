#include "stdafx.h"
#include "FileSystem.h"
#include "Self.h"

extern CSelf* pMe;
extern CFileSystem* pFileSystem;
extern CMsRole* pMsRole;

CFileSystem::CFileSystem()
{
}


CFileSystem::~CFileSystem()
{
}

//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////
void CFileSystem::FileInitial()
{
	////////////////////�ű�Ŀ¼�µ��ļ�//////////////////////////////////////
	//ScriptĿ¼

	Script = Module + _T("script\\");

	////////////////////dataĿ¼�µ��ļ�//////////////////////////////////////
	//��Ʒ�ļ�
	Item = Module + ITEM_FILE_NAME;
	Skill = Module + SKILL_DATA_NAME;

	////////////////////�û�Ŀ¼�µ��ļ�//////////////////////////////////////
	//Ĭ��ui�����ļ�
	DefaultSetup = Module + DEFAULTSETUP_FILE_NAME;
	//�û����ļ���·��

	auto ARoleInfo = pMsRole->GetRoleInfo();
	if (!ARoleInfo.bool_ret)
	{
		AfxMessageBox("��ȡ��������ʧ��");
		return;
	}
	_tstring strRole = ARoleInfo.szName;
	Directory = Module + _T("user\\") + strRole;
	//�û���Ʒ�����ļ�
	UserItem = Directory + USER_ITEM_FILE_NAME;
	//ɨ��̯��Ʒ�۸������ļ�·��
	UserBuyBoothItem = Directory + USER_BuyBooth_ITEM_FILE_NAME;
	//�ڵ�̯��Ʒ�۸������ļ�·��
	UserSellBoothItem = Directory + USER_SELLBooth_ITEM_FILE_NAME;
	//�û����������ļ�
	UserSetup = Directory + USERSETUP_FILE_NAME;
	//�û����ܽ��������ļ�
	SkillSetup = Directory + SKILL_FILE_NAME;
	//�û��һ�����������������ļ�
	UserPos = Directory + USERPOS_FILE_NAME;
	//��־�ļ�·��
	logFile = Directory + LOG_FILE_NAME;
	//���û�Ŀ¼�´���һ���Խ�ɫ���������ļ��У�����Ѿ����ھͲ�����
	MyCreateDirectory(Directory.c_str());
	//�ڽ�ɫĿ¼�´���һ����Ʒ�ļ�������Ѿ����ھͲ�����
	MyCopyfiles(Item.c_str(), UserItem.c_str(), TRUE);
	//�ڽ�ɫĿ¼�´���һ����Ʒ�ļ�������Ѿ����ھͲ�����
	MyCopyfiles(DefaultSetup.c_str(), UserSetup.c_str(), TRUE);
}

void CFileSystem::MyGetFilePath(HMODULE hModule)
{//��ȡdll·���͵�¼�ű��ļ�·��


	TCHAR* szBuffer = new TCHAR[MAX_PATH * 2];
	::GetModuleFileName(hModule, szBuffer, MAX_PATH * 2);
	if (!_tcscmp(szBuffer, _T("")))
	{//��ȡģ��·��
	 //dbgPrint(_T("GetModuleFileName Error %d"), GetLastError());
	}
	//�����ַ���������'\'�ַ�
	TCHAR* lpPath = _tcsrchr(szBuffer, _T('\\'));
	::ZeroMemory(++lpPath, 50);//��ģ���������

	Module = szBuffer;
	//����ʺŵ��ļ�
	Account = szBuffer;
	Account += ACCOUNT_FILE_NAME;
	//�û���¼�ļ�·��--START
	Login = szBuffer;
	Login += LOGIN_FILE_NAME;
	//�û���¼�ļ�·��---END
	Script = Module + _T("script\\");
	//_tprintf(_T("%s\n"), Item.c_str());

	delete[]szBuffer;
}

//------------------------------------------------------------------------
//���������ļ�������
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
CArchive& operator << (CArchive& ar, const ItemsFile &items)
{
	ASSERT(ar.IsStoring());
	ar << items.strName << items.strType << items.strPickUp << items.strSell;
	return ar;
}

CArchive& operator >> (CArchive& ar, ItemsFile &items)
{
	ASSERT(ar.IsLoading());

	ar >> items.strName >> items.strType >> items.strPickUp
		>> items.strSell;

	return ar;
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

//����һ�����ļ���
BOOL CFileSystem::MyCreateDirectory(LPCTSTR strFolderPath)
{
	// �ж�·���Ƿ���� 
	if (!PathIsDirectory(strFolderPath))
	{
		//����һ�����ļ���
		if (!CreateDirectory(strFolderPath, NULL))
		{//BOOL�������ʾ�ɹ������ʾʧ�ܡ�������GetLastError
		 //dbgPrint(_T("CreateDirectoryA Error %d"), GetLastError());
			return FALSE;
		}
	}

	return TRUE;
}

//lpExistingFileName String��Դ�ļ���
//lpNewFileName String��Ŀ���ļ���
//bFailIfExists �����ΪTRUE�����㣩��ôһ��Ŀ���ļ��Ѿ����ڣ��������û�ʧ�ܡ�����Ŀ���ļ�����д��
BOOL CFileSystem::MyCopyfiles(LPCTSTR lpExistingFileName,
	LPCTSTR lpNewFileName,
	_In_ BOOL bFailIfExists)
{
	//BOOL�������ʾ�ɹ������ʾʧ�ܡ�������GetLastError

	BOOL bCopy = CopyFile(lpExistingFileName, lpNewFileName, bFailIfExists);

	if (!bCopy)
	{
		if (GetLastError() != 80)
			dbgPrint(_T("CopyFileA Error %d"), );
	}

	return bCopy;
}

BOOL CFileSystem::MyDeleteFile(
	LPCTSTR lpFileName // �ļ���ָ��
)
{
	//ɾ��һ�����ڵ��ļ�
	//����ɹ�����һ����0ֵ
	//ʧ�ܷ���0 ������GetLastError�����õ�������Ϣ
	//���������ɾ��һ�������ڵ��ļ���GetLastError����ERROR_FILE_NOT_FOUND������ļ���ֻ�� �ģ���GetLastError����ERROR_ACCESS_DENIED

	BOOL bDelete = DeleteFile(lpFileName);

	if (!bDelete)
	{
		dbgPrint(_T("DeleteFileA Error %d"), GetLastError());
	}

	return bDelete;
}

VUserScriptName CFileSystem::MyEnumFile(LPCTSTR lpFileName)
{//ö��ָ��Ŀ¼�µ��ļ�
	VUserScriptName UserScriptName;
	_tstring strFileName = lpFileName;
	strFileName += _T("*.*");//��������*.*

	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(strFileName.c_str(), &fd);

	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))//��������Ŀ¼�������ļ�
			{
				////dbgPrint(_T("%s%s\n"), lpFileName,fd.cFileName);
				_tstring strSource = fd.cFileName;
				strSource = Os_stringOferase(strSource, _T(".lua"));
				UserScriptName.push_back(strSource.c_str());
			}

		} while (::FindNextFile(hFind, &fd));

		::FindClose(hFind);
	}

	return UserScriptName;
}

//д��־�ļ�����
void WriteLog(CString& Cstr)
{
	try
	{
		//�����ļ��Ĵ򿪲���
		CStdioFile outFile(pFileSystem->logFile.c_str(), CFile::modeNoTruncate | CFile::modeCreate | CFile::modeWrite | CFile::typeText);
		//////////////////////////////////////////////////////////////////////////

		CFileStatus fileStatus;
		if (outFile.GetStatus(pFileSystem->logFile.c_str(), fileStatus))
		{
			if (fileStatus.m_size > 40960)
				outFile.SetLength(0);
		}

		CTime tt = CTime::GetCurrentTime();
		//��ΪLog�ļ�������Ҫ��ÿ��Log��ʱ�����ʱ���ʽ�����ɶ��壬
		//����ĸ�ʽ�磺2010-June-10 Thursday, 15:58:12
		Cstr = tt.Format(_T("[%Y-%B-%d %A, %H:%M:%S]")) + Cstr + _T("\n");
		//���ļ�ĩβ�����¼�¼
		outFile.SeekToEnd();
		outFile.WriteString(Cstr);
		outFile.Close();

	}
	catch (CFileException *fx)
	{//�ļ��쳣
		fx->Delete();
	}
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//������ȫ�ֺ���
//////////////////////////////////////////////////////////////////////////


CStringW CString__A_to_W(IN const CStringA CStrA)
{
	/*
	ASCIIת��UNICODE
	*/

	CStringW rt = L"";
	int unicodeLen = ::MultiByteToWideChar(CP_ACP, 0, CStrA, -1, NULL, 0);
	WCHAR* pUnicode;
	pUnicode = new WCHAR[unicodeLen]();
	if (pUnicode)
	{
		::MultiByteToWideChar(CP_ACP, 0, CStrA, -1, (LPWSTR)pUnicode, unicodeLen);
		rt = pUnicode;
		delete[] pUnicode;
	}
	return rt;
}

CStringA CString__W_to_A(IN const CStringW CStrW)
{
	/*
	UNICODE��ASCII
	*/
	int ascii_Len = ::WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK, CStrW, -1, NULL, NULL, NULL, NULL);
	CStringA CStrA;
	PCHAR pchar = new char[ascii_Len]();
	if (pchar)
	{
		::WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK, CStrW, -1, pchar, ascii_Len, NULL, NULL);
		CStrA = pchar;
		delete[] pchar;
	}
	return CStrA;
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

