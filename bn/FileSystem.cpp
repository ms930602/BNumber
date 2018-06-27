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
	////////////////////脚本目录下的文件//////////////////////////////////////
	//Script目录

	Script = Module + _T("script\\");

	////////////////////data目录下的文件//////////////////////////////////////
	//物品文件
	Item = Module + ITEM_FILE_NAME;
	Skill = Module + SKILL_DATA_NAME;

	////////////////////用户目录下的文件//////////////////////////////////////
	//默认ui设置文件
	DefaultSetup = Module + DEFAULTSETUP_FILE_NAME;
	//用户名文件夹路径

	auto ARoleInfo = pMsRole->GetRoleInfo();
	if (!ARoleInfo.bool_ret)
	{
		AfxMessageBox("获取人物名称失败");
		return;
	}
	_tstring strRole = ARoleInfo.szName;
	Directory = Module + _T("user\\") + strRole;
	//用户物品设置文件
	UserItem = Directory + USER_ITEM_FILE_NAME;
	//扫地摊物品价格配置文件路径
	UserBuyBoothItem = Directory + USER_BuyBooth_ITEM_FILE_NAME;
	//摆地摊物品价格配置文件路径
	UserSellBoothItem = Directory + USER_SELLBooth_ITEM_FILE_NAME;
	//用户界面设置文件
	UserSetup = Directory + USERSETUP_FILE_NAME;
	//用户技能界面设置文件
	SkillSetup = Directory + SKILL_FILE_NAME;
	//用户挂机中心坐标界面设置文件
	UserPos = Directory + USERPOS_FILE_NAME;
	//日志文件路径
	logFile = Directory + LOG_FILE_NAME;
	//在用户目录下创建一个以角色名命名的文件夹，如果已经存在就不创建
	MyCreateDirectory(Directory.c_str());
	//在角色目录下创建一个物品文件，如果已经存在就不创建
	MyCopyfiles(Item.c_str(), UserItem.c_str(), TRUE);
	//在角色目录下创建一个物品文件，如果已经存在就不创建
	MyCopyfiles(DefaultSetup.c_str(), UserSetup.c_str(), TRUE);
}

void CFileSystem::MyGetFilePath(HMODULE hModule)
{//获取dll路径和登录脚本文件路径


	TCHAR* szBuffer = new TCHAR[MAX_PATH * 2];
	::GetModuleFileName(hModule, szBuffer, MAX_PATH * 2);
	if (!_tcscmp(szBuffer, _T("")))
	{//获取模块路径
	 //dbgPrint(_T("GetModuleFileName Error %d"), GetLastError());
	}
	//查找字符串最左侧的'\'字符
	TCHAR* lpPath = _tcsrchr(szBuffer, _T('\\'));
	::ZeroMemory(++lpPath, 50);//将模块名字清除

	Module = szBuffer;
	//存放帐号的文件
	Account = szBuffer;
	Account += ACCOUNT_FILE_NAME;
	//用户登录文件路径--START
	Login = szBuffer;
	Login += LOGIN_FILE_NAME;
	//用户登录文件路径---END
	Script = Module + _T("script\\");
	//_tprintf(_T("%s\n"), Item.c_str());

	delete[]szBuffer;
}

//------------------------------------------------------------------------
//技能数据文件流操作
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

//创建一个新文件夹
BOOL CFileSystem::MyCreateDirectory(LPCTSTR strFolderPath)
{
	// 判断路径是否存在 
	if (!PathIsDirectory(strFolderPath))
	{
		//创建一个新文件夹
		if (!CreateDirectory(strFolderPath, NULL))
		{//BOOL，非零表示成功，零表示失败。会设置GetLastError
		 //dbgPrint(_T("CreateDirectoryA Error %d"), GetLastError());
			return FALSE;
		}
	}

	return TRUE;
}

//lpExistingFileName String，源文件名
//lpNewFileName String，目标文件名
//bFailIfExists 如果设为TRUE（非零）那么一旦目标文件已经存在，则函数调用会失败。否则目标文件被改写。
BOOL CFileSystem::MyCopyfiles(LPCTSTR lpExistingFileName,
	LPCTSTR lpNewFileName,
	_In_ BOOL bFailIfExists)
{
	//BOOL，非零表示成功，零表示失败。会设置GetLastError

	BOOL bCopy = CopyFile(lpExistingFileName, lpNewFileName, bFailIfExists);

	if (!bCopy)
	{
		if (GetLastError() != 80)
			dbgPrint(_T("CopyFileA Error %d"), );
	}

	return bCopy;
}

BOOL CFileSystem::MyDeleteFile(
	LPCTSTR lpFileName // 文件名指针
)
{
	//删除一个存在的文件
	//如果成功返回一个非0值
	//失败返回0 可以用GetLastError函数得到错误信息
	//如果程序尝试删除一个不存在的文件。GetLastError返回ERROR_FILE_NOT_FOUND。如果文件是只读 的，则GetLastError返回ERROR_ACCESS_DENIED

	BOOL bDelete = DeleteFile(lpFileName);

	if (!bDelete)
	{
		dbgPrint(_T("DeleteFileA Error %d"), GetLastError());
	}

	return bDelete;
}

VUserScriptName CFileSystem::MyEnumFile(LPCTSTR lpFileName)
{//枚举指定目录下的文件
	VUserScriptName UserScriptName;
	_tstring strFileName = lpFileName;
	strFileName += _T("*.*");//必须加这个*.*

	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(strFileName.c_str(), &fd);

	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))//不是是子目录，就是文件
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

//写日志文件函数
void WriteLog(CString& Cstr)
{
	try
	{
		//设置文件的打开参数
		CStdioFile outFile(pFileSystem->logFile.c_str(), CFile::modeNoTruncate | CFile::modeCreate | CFile::modeWrite | CFile::typeText);
		//////////////////////////////////////////////////////////////////////////

		CFileStatus fileStatus;
		if (outFile.GetStatus(pFileSystem->logFile.c_str(), fileStatus))
		{
			if (fileStatus.m_size > 40960)
				outFile.SetLength(0);
		}

		CTime tt = CTime::GetCurrentTime();
		//作为Log文件，经常要给每条Log打时间戳，时间格式可自由定义，
		//这里的格式如：2010-June-10 Thursday, 15:58:12
		Cstr = tt.Format(_T("[%Y-%B-%d %A, %H:%M:%S]")) + Cstr + _T("\n");
		//在文件末尾插入新纪录
		outFile.SeekToEnd();
		outFile.WriteString(Cstr);
		outFile.Close();

	}
	catch (CFileException *fx)
	{//文件异常
		fx->Delete();
	}
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//下面是全局函数
//////////////////////////////////////////////////////////////////////////


CStringW CString__A_to_W(IN const CStringA CStrA)
{
	/*
	ASCII转换UNICODE
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
	UNICODE换ASCII
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

