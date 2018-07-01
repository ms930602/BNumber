#pragma once
#include <string>
#include "MsRole.h"

using namespace std;

#if defined (UNICODE) || defined(_UNICODE)
#define cpp_char wchar_t
#define _tstring std::wstring
#define _to_string(x) std::towstring(x)
#else
#define cpp_char char
#define _tstring std::string
#define _to_string(x) std::to_string(x)
#endif

#define		 SKILL_DATA_NAME	     _T("data\\技能.txt")	//物品数据文件路径
#define		 ITEM_FILE_NAME			 _T("data\\物品.txt")	//物品数据文件路径
#define		 ACCOUNT_FILE_NAME		 _T("user\\Login.ini")    //登录帐号文件路径
#define		 MAP_FILE_NAME			 _T("data\\地图.txt")    //地图文件路径
#define		 DEFAULTSETUP_FILE_NAME	 _T("user\\默认界面.ini") //默认的ui设置
#define		 USERSETUP_FILE_NAME	 _T("\\界面.ini") //用户的ui设置
#define		 USER_ITEM_FILE_NAME	 _T("\\物品.txt")//用户物品文件路径
#define		 SKILL_FILE_NAME		 _T("\\技能.txt")	//用户技能设置
#define		 LOGIN_FILE_NAME		 _T("script\\登录.lua")  //登陆脚本文件
#define      USERPOS_FILE_NAME       _T("\\挂机中心.txt")  //登陆脚本文件
#define      LOG_FILE_NAME           _T("\\日志.txt")  //登陆脚本文件
#define      USER_BuyBooth_ITEM_FILE_NAME  _T("\\地摊物品价格.txt")  //地摊物品价格
#define      USER_SELLBooth_ITEM_FILE_NAME _T("\\摆地摊物品价格.txt")  //地摊物品价格

typedef struct tagLOGIN
{
	TCHAR strName[50];//帐号名字
	TCHAR strKey[50];//帐号密码
}LOGIN;


typedef struct tagITEMS_FILE
{
	CStringA strName;//物品名称
	CStringA strType;//物品类型名
	CStringA strSell;//指定出售物品操作
	CStringA strPickUp;//指定拾取物品操作
}ItemsFile, *PItemsFile;


typedef vector<CString> VUserScriptName;

extern _tstring Os_stringOferase(_tstring& strSource, _tstring strErase);//移除指定字符或者字符串

class CFileSystem
{
public:
	CFileSystem();
	~CFileSystem();
public:
	void FileInitial();
public:

	//重载输出操作符
	friend CArchive& operator << (CArchive& ar, const ItemsFile &items);
	//重载输入操作符
	friend CArchive& operator >> (CArchive& ar, ItemsFile &items);

	//保存一个ItemsFile数组到文件
	template <typename TFP, typename TST, typename TN>
	bool Save_Data(TFP szFilePath, const TST *pData, TN nSize)
	{
		CFile file;
		if (!file.Open(szFilePath, CFile::modeCreate | CFile::modeWrite))
			return false;
		CArchive ar(&file, CArchive::store);
		ar << nSize;
		for (int i = 0; i < nSize; i++)
			ar << pData[i];
		return true;
	};

	//从文件中读取数据到ItemsFile数组
	template <typename TFP, typename TST, typename TN>
	bool Load_Data(TFP szFilePath, TST *pData, TN nSize)
	{
		int n = 0;
		CFile file;
		if (!file.Open(szFilePath, CFile::modeRead))
			return false;
		CArchive ar(&file, CArchive::load);
		ar >> n;
		for (int i = 0; i < n && i < nSize; i++)
			ar >> pData[i];
		return true;
	};

public:

	BOOL MyCreateDirectory(LPCTSTR strFolderPath);//创建一个新文件夹

	BOOL MyCopyfiles(LPCTSTR lpExistingFileName,
		LPCTSTR lpNewFileName,
		_In_ BOOL bFailIfExists);	//复制一个文件内容到另一个文件

	BOOL MyDeleteFile(LPCTSTR  lpFileName); //删除指定文件
											//MoveFile()
	VUserScriptName MyEnumFile(LPCTSTR lpFileName);
	//
	void MyGetFilePath(HMODULE hModule);
	//
public:
	//WritePrivateProfileStruct
	//GetPrivateProfileStruct
public:
	//写日志文件函数
	template <typename TF, typename... TS>
	void MyWriteLog(IN  const TF Format, IN const TS... list)
	{
		try
		{
			//接受参数队列
			CString Cstr;
			Cstr.Format(Format, list...);
			//设置文件的打开参数
			CStdioFile outFile(logFile.c_str(), CFile::modeNoTruncate | CFile::modeCreate | CFile::modeWrite | CFile::typeText);
			//////////////////////////////////////////////////////////////////////////
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
public:

	_tstring Module;//动态链接库文件路径
	_tstring Script;//脚本文件目录
	_tstring DefaultSetup;//默认的ui设置
	_tstring UserSetup;//用户配置文件路径
	_tstring Account;//登录帐号文件路径
	_tstring Map; //地图文件路径
	_tstring Skill;//技能数据文件路径
	_tstring SkillSetup;//技能数据配置文件路径
	_tstring Item;//物品数据文件路径
	_tstring UserItem;//用户物品配置文件路径
	_tstring UserBuyBoothItem;//用户扫地摊物品价格
	_tstring UserSellBoothItem;//用户摆地摊物品价格
	_tstring UserPos;//用户物品配置文件路径
	_tstring Directory;//用户角色目录
	_tstring Login;//登录脚本文件路径
	_tstring logFile;//日志文件路径
};


void WriteLog(CString& Cstr);

//打印输出版OutPutDebugString函数
//def__debug__lib 值设置为非零值可以输出调试字符串
//def__debug__lib 值设置为零值屏蔽调试字符串输出

template <typename TF, typename... TS>
void DPrint(IN  const TF Format, IN const TS... list)
{
	try
	{
		CString Cstr;
		Cstr.Format(Format, list...);
		Cstr = _T("[WG][dll]") + Cstr;
		::OutputDebugString(Cstr);//调试输出到软件
		WriteLog(Cstr);//写日志
	}
	catch (...)
	{
		::OutputDebugStringA(__FUNCTION__);
	}
}

#define def__debug__dll 1
#undef  dbgPrint
#if     def__debug__dll
#define dbgPrint(_x_,...) DPrint(_x_,__VA_ARGS__)
#else
#define dbgPrint( _x_ ,...)
#endif

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

//字符串转换操作
CStringW CString__A_to_W(IN const CStringA CStrA);
CStringA CString__W_to_A(IN const CStringW CStrW);