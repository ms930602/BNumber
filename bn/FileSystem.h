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

#define		 SKILL_DATA_NAME	     _T("data\\����.txt")	//��Ʒ�����ļ�·��
#define		 ITEM_FILE_NAME			 _T("data\\��Ʒ.txt")	//��Ʒ�����ļ�·��
#define		 ACCOUNT_FILE_NAME		 _T("user\\Login.ini")    //��¼�ʺ��ļ�·��
#define		 MAP_FILE_NAME			 _T("data\\��ͼ.txt")    //��ͼ�ļ�·��
#define		 DEFAULTSETUP_FILE_NAME	 _T("user\\Ĭ�Ͻ���.ini") //Ĭ�ϵ�ui����
#define		 USERSETUP_FILE_NAME	 _T("\\����.ini") //�û���ui����
#define		 USER_ITEM_FILE_NAME	 _T("\\��Ʒ.txt")//�û���Ʒ�ļ�·��
#define		 SKILL_FILE_NAME		 _T("\\����.txt")	//�û���������
#define		 LOGIN_FILE_NAME		 _T("script\\��¼.lua")  //��½�ű��ļ�
#define      USERPOS_FILE_NAME       _T("\\�һ�����.txt")  //��½�ű��ļ�
#define      LOG_FILE_NAME           _T("\\��־.txt")  //��½�ű��ļ�
#define      USER_BuyBooth_ITEM_FILE_NAME  _T("\\��̯��Ʒ�۸�.txt")  //��̯��Ʒ�۸�
#define      USER_SELLBooth_ITEM_FILE_NAME _T("\\�ڵ�̯��Ʒ�۸�.txt")  //��̯��Ʒ�۸�

typedef struct tagLOGIN
{
	TCHAR strName[50];//�ʺ�����
	TCHAR strKey[50];//�ʺ�����
}LOGIN;


typedef struct tagITEMS_FILE
{
	CStringA strName;//��Ʒ����
	CStringA strType;//��Ʒ������
	CStringA strSell;//ָ��������Ʒ����
	CStringA strPickUp;//ָ��ʰȡ��Ʒ����
}ItemsFile, *PItemsFile;


typedef vector<CString> VUserScriptName;

extern _tstring Os_stringOferase(_tstring& strSource, _tstring strErase);//�Ƴ�ָ���ַ������ַ���

class CFileSystem
{
public:
	CFileSystem();
	~CFileSystem();
public:
	void FileInitial();
public:

	//�������������
	friend CArchive& operator << (CArchive& ar, const ItemsFile &items);
	//�������������
	friend CArchive& operator >> (CArchive& ar, ItemsFile &items);

	//����һ��ItemsFile���鵽�ļ�
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

	//���ļ��ж�ȡ���ݵ�ItemsFile����
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

	BOOL MyCreateDirectory(LPCTSTR strFolderPath);//����һ�����ļ���

	BOOL MyCopyfiles(LPCTSTR lpExistingFileName,
		LPCTSTR lpNewFileName,
		_In_ BOOL bFailIfExists);	//����һ���ļ����ݵ���һ���ļ�

	BOOL MyDeleteFile(LPCTSTR  lpFileName); //ɾ��ָ���ļ�
											//MoveFile()
	VUserScriptName MyEnumFile(LPCTSTR lpFileName);
	//
	void MyGetFilePath(HMODULE hModule);
	//
public:
	//WritePrivateProfileStruct
	//GetPrivateProfileStruct
public:
	//д��־�ļ�����
	template <typename TF, typename... TS>
	void MyWriteLog(IN  const TF Format, IN const TS... list)
	{
		try
		{
			//���ܲ�������
			CString Cstr;
			Cstr.Format(Format, list...);
			//�����ļ��Ĵ򿪲���
			CStdioFile outFile(logFile.c_str(), CFile::modeNoTruncate | CFile::modeCreate | CFile::modeWrite | CFile::typeText);
			//////////////////////////////////////////////////////////////////////////
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
public:

	_tstring Module;//��̬���ӿ��ļ�·��
	_tstring Script;//�ű��ļ�Ŀ¼
	_tstring DefaultSetup;//Ĭ�ϵ�ui����
	_tstring UserSetup;//�û������ļ�·��
	_tstring Account;//��¼�ʺ��ļ�·��
	_tstring Map; //��ͼ�ļ�·��
	_tstring Skill;//���������ļ�·��
	_tstring SkillSetup;//�������������ļ�·��
	_tstring Item;//��Ʒ�����ļ�·��
	_tstring UserItem;//�û���Ʒ�����ļ�·��
	_tstring UserBuyBoothItem;//�û�ɨ��̯��Ʒ�۸�
	_tstring UserSellBoothItem;//�û��ڵ�̯��Ʒ�۸�
	_tstring UserPos;//�û���Ʒ�����ļ�·��
	_tstring Directory;//�û���ɫĿ¼
	_tstring Login;//��¼�ű��ļ�·��
	_tstring logFile;//��־�ļ�·��
};


void WriteLog(CString& Cstr);

//��ӡ�����OutPutDebugString����
//def__debug__lib ֵ����Ϊ����ֵ������������ַ���
//def__debug__lib ֵ����Ϊ��ֵ���ε����ַ������

template <typename TF, typename... TS>
void DPrint(IN  const TF Format, IN const TS... list)
{
	try
	{
		CString Cstr;
		Cstr.Format(Format, list...);
		Cstr = _T("[WG][dll]") + Cstr;
		::OutputDebugString(Cstr);//������������
		WriteLog(Cstr);//д��־
	}
	catch (...)
	{
		::OutputDebugStringA("[WG][dll]"__FUNCTION__);
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

//�ַ���ת������
CStringW CString__A_to_W(IN const CStringA CStrA);
CStringA CString__W_to_A(IN const CStringW CStrW);