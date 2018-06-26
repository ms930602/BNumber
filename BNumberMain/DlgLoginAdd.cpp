// DlgLoginAdd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BNumberMain.h"
#include "DlgLoginAdd.h"
#include "afxdialogex.h"

// DlgLoginAdd �Ի���

IMPLEMENT_DYNAMIC(DlgLoginAdd, CDialogEx)

vector<CString> GetIniInfo(LPCTSTR pFilePath, CString pAppName)//��ȡini�ļ���Ϣ
{
	TCHAR strKeyNameTemp[1024] = { 0 };//��Ӧÿ��AppName������KeyName�ķ���ֵ
	GetPrivateProfileString(pAppName, _T("����"), _T(""), strKeyNameTemp, 1024, pFilePath);
	vector<CString> AllName = cstring_substr(strKeyNameTemp, _T(","), 1);

	return AllName;
}

DlgLoginAdd::DlgLoginAdd(CWnd* pParent, CListCtrl* plist_b,INT nDlg1Num)
	: CDialogEx(IDD_DLG_ADDLogin, pParent)
{
	m_list_b = plist_b;
	m_Dlg1Num = nDlg1Num;
}

DlgLoginAdd::~DlgLoginAdd()
{
}

void DlgLoginAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL DlgLoginAdd::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	((CComboBox*)GetDlgItem(IDC_CBX_2_1))->AddString(_T("��"));
	((CComboBox*)GetDlgItem(IDC_CBX_2_1))->AddString(_T("��"));
	((CComboBox*)GetDlgItem(IDC_CBX_2_1))->SetCurSel(0);
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	CString	strPath = MyGetFilePathName(_T("����������.txt"));
	if (strPath != "")
	{
		auto AllServer = tenum_inifile(strPath, _T("ȫ������"));
		for (auto Server : AllServer)
		{
			((CComboBox*)GetDlgItem(IDC_CBX_2_2))->AddString(Server);
		}
	}

	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	((CComboBox*)GetDlgItem(IDC_CBX_2_4))->AddString(_T("@changyou.com"));
	((CComboBox*)GetDlgItem(IDC_CBX_2_4))->AddString(_T("@game.sohu.com"));
	((CComboBox*)GetDlgItem(IDC_CBX_2_4))->AddString(_T("@Sohu.com"));
	((CComboBox*)GetDlgItem(IDC_CBX_2_4))->AddString(_T("@chinaren.com"));
	((CComboBox*)GetDlgItem(IDC_CBX_2_4))->AddString(_T("@sogou.com"));
	((CComboBox*)GetDlgItem(IDC_CBX_2_4))->AddString(_T("@17173.com"));
	((CComboBox*)GetDlgItem(IDC_CBX_2_4))->AddString(_T("�ֻ������¼"));
	((CComboBox*)GetDlgItem(IDC_CBX_2_4))->AddString(_T("���������˺ź�׺"));
	((CComboBox*)GetDlgItem(IDC_CBX_2_4))->SetCurSel(0);
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	((CComboBox*)GetDlgItem(IDC_CBX_2_5))->AddString(_T("��һ����ɫ"));
	((CComboBox*)GetDlgItem(IDC_CBX_2_5))->AddString(_T("�ڶ�����ɫ"));
	((CComboBox*)GetDlgItem(IDC_CBX_2_5))->AddString(_T("��������ɫ"));
	((CComboBox*)GetDlgItem(IDC_CBX_2_5))->SetCurSel(0);

	if (m_Dlg1Num != -1)
	{
		CString strItemText = m_list_b->GetItemText(m_Dlg1Num, 1);//��
		((CComboBox*)GetDlgItem(IDC_CBX_2_2))->SetWindowText(strItemText);
		strItemText = m_list_b->GetItemText(m_Dlg1Num, 2);//��
		((CComboBox*)GetDlgItem(IDC_CBX_2_3))->SetWindowText(strItemText);
		strItemText = m_list_b->GetItemText(m_Dlg1Num, 3);//��
		GetDlgItem(IDC_EDIT_2_1)->SetWindowText(strItemText);
		strItemText = m_list_b->GetItemText(m_Dlg1Num, 4);//��
		((CComboBox*)GetDlgItem(IDC_CBX_2_4))->SetWindowText(strItemText);
		strItemText = m_list_b->GetItemText(m_Dlg1Num, 5);//��
		GetDlgItem(IDC_EDIT_2_2)->SetWindowText(strItemText);
		strItemText = m_list_b->GetItemText(m_Dlg1Num, 6);//��
		GetDlgItem(IDC_EDIT_2_3)->SetWindowText(strItemText);
		strItemText = m_list_b->GetItemText(m_Dlg1Num, 7);//ѡ
		if (strItemText == "0")
			strItemText = _T("��һ����ɫ");
		else if (strItemText == "1")
			strItemText = _T("�ڶ�����ɫ");
		else if (strItemText == "2")
			strItemText = _T("��������ɫ");
		((CComboBox*)GetDlgItem(IDC_CBX_2_5))->SetWindowText(strItemText);
		strItemText = m_list_b->GetItemText(m_Dlg1Num, 9);//�ű�
		GetDlgItem(IDC_EDIT_2_6)->SetWindowText(strItemText);
		strItemText = m_list_b->GetItemText(m_Dlg1Num, 10);//��ע
		GetDlgItem(IDC_EDIT_2_5)->SetWindowText(strItemText);
		BOOL bCheck = m_list_b->GetCheck(m_Dlg1Num);
		if (bCheck == TRUE)
		{
			((CComboBox*)GetDlgItem(IDC_CBX_2_1))->SetWindowText(_T("��"));
		}
	}

	return TRUE;
}


BEGIN_MESSAGE_MAP(DlgLoginAdd, CDialogEx)
	ON_CBN_SELCHANGE(IDC_CBX_2_2, &DlgLoginAdd::OnCbnSelchangeCbx22)
	ON_BN_CLICKED(IDC_BTN_LookFile, &DlgLoginAdd::OnBnClickedBtnLookfile)
	ON_BN_CLICKED(IDOK_BTN_Login, &DlgLoginAdd::OnBnClickedBtnLogin)
END_MESSAGE_MAP()


// DlgLoginAdd ��Ϣ�������


void DlgLoginAdd::OnCbnSelchangeCbx22()
{
	CString strText;
	((CComboBox*)GetDlgItem(IDC_CBX_2_2))->GetWindowText(strText);
	((CComboBox*)GetDlgItem(IDC_CBX_2_3))->ResetContent();
	CString	strPath = MyGetFilePathName(_T("����������.txt"));
	if (strPath != "")
	{
		auto AllName = GetIniInfo(strPath, strText);
		for (auto Name : AllName)
		{
			((CComboBox*)GetDlgItem(IDC_CBX_2_3))->AddString(Name);
		}
		((CComboBox*)GetDlgItem(IDC_CBX_2_3))->SetCurSel(0);
	}
}


void DlgLoginAdd::OnBnClickedBtnLookfile()
{
	try {
		TCHAR szFilter[] = _T("�����ļ�(*.*)|*.*||");
		CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter);
		if (dlg.DoModal() == IDOK)
		{
			CString CStrScript = dlg.GetPathName();
			if (!CStrScript.IsEmpty())
			{
				GetDlgItem(IDC_EDIT_2_6)->SetWindowTextA(CStrScript);
			}
		}
	}
	catch (CFileException* e)
	{
		e->Delete();
	}
}


void DlgLoginAdd::OnBnClickedBtnLogin()
{
	CString strText0, strText1, strText2, strText3, strText4, strText5, strText6, strText7, strText8, strText9, strText10;
	((CComboBox*)GetDlgItem(IDC_CBX_2_1))->GetWindowText(strText0);
	((CComboBox*)GetDlgItem(IDC_CBX_2_2))->GetWindowText(strText1);
	((CComboBox*)GetDlgItem(IDC_CBX_2_3))->GetWindowText(strText2);
	GetDlgItem(IDC_EDIT_2_1)->GetWindowText(strText3);
	((CComboBox*)GetDlgItem(IDC_CBX_2_4))->GetWindowText(strText4);
	GetDlgItem(IDC_EDIT_2_2)->GetWindowText(strText5);
	GetDlgItem(IDC_EDIT_2_3)->GetWindowText(strText6);
	if (!strText6.IsEmpty())
		strText8 = _T("��");
	else
		strText8 = _T("��");
	((CComboBox*)GetDlgItem(IDC_CBX_2_5))->GetWindowText(strText7);
	if (strText7 == _T("��һ����ɫ"))
		strText7 = "0";
	else if (strText7 == _T("�ڶ�����ɫ"))
		strText7 = "1";
	else if (strText7 == _T("��������ɫ"))
		strText7 = "2";
	GetDlgItem(IDC_EDIT_2_6)->GetWindowText(strText9);
	GetDlgItem(IDC_EDIT_2_5)->GetWindowText(strText10);

	if (strText0.IsEmpty())
	{
		AfxMessageBox(_T("ѡ�����ò���Ϊ�գ���"));
	}
	else if (strText1.IsEmpty())
	{
		AfxMessageBox(_T("�������ò���Ϊ�գ���"));
	}
	else if (strText2.IsEmpty())
	{
		AfxMessageBox(_T("���������ò���Ϊ�գ���"));
	}
	else if (strText3.IsEmpty())
	{
		AfxMessageBox(_T("�ʺ����ò���Ϊ�գ���"));
	}
	else if (strText4.IsEmpty())
	{
		AfxMessageBox(_T("��׺���ò���Ϊ�գ���"));
	}
	else if (strText5.IsEmpty())
	{
		AfxMessageBox(_T("�������ò���Ϊ�գ���"));
	}
	else if (strText7.IsEmpty())
	{
		AfxMessageBox(_T("ѡ���ɫ���ò���Ϊ�գ���"));
	}
	else
	{
		INT nCount = m_list_b->GetItemCount();
		if (m_Dlg1Num != -1)
		{
			nCount = m_Dlg1Num;
		}
		else
		{
			CStringA f;
			f.Format("%d", nCount + 1);
			m_list_b->InsertItem(nCount, f);//��
		}
		m_list_b->SetItemText(nCount, 1, strText1);//��
		m_list_b->SetItemText(nCount, 2, strText2);//��
		m_list_b->SetItemText(nCount, 3, strText3);//��
		m_list_b->SetItemText(nCount, 4, strText4);//��
		m_list_b->SetItemText(nCount, 5, strText5);//��
		m_list_b->SetItemText(nCount, 6, strText6);//��
		m_list_b->SetItemText(nCount, 7, strText7);//ѡ
		m_list_b->SetItemText(nCount, 8, strText8);//��
		m_list_b->SetItemText(nCount, 9, strText9);//�ű�
		m_list_b->SetItemText(nCount, 10, strText10);//��ע
		if (strText0 == _T("��"))
		{
			m_list_b->SetCheck(nCount);
		}
		CDialogEx::OnOK();
	}
}
