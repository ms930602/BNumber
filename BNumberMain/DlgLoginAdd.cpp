// DlgLoginAdd.cpp : 实现文件
//

#include "stdafx.h"
#include "BNumberMain.h"
#include "DlgLoginAdd.h"
#include "afxdialogex.h"

// DlgLoginAdd 对话框

IMPLEMENT_DYNAMIC(DlgLoginAdd, CDialogEx)

vector<CString> GetIniInfo(LPCTSTR pFilePath, CString pAppName)//获取ini文件信息
{
	TCHAR strKeyNameTemp[1024] = { 0 };//对应每个AppName的所有KeyName的返回值
	GetPrivateProfileString(pAppName, _T("名称"), _T(""), strKeyNameTemp, 1024, pFilePath);
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
	// TODO:  在此添加额外的初始化
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	((CComboBox*)GetDlgItem(IDC_CBX_2_1))->AddString(_T("否"));
	((CComboBox*)GetDlgItem(IDC_CBX_2_1))->AddString(_T("是"));
	((CComboBox*)GetDlgItem(IDC_CBX_2_1))->SetCurSel(0);
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	CString	strPath = MyGetFilePathName(_T("服务器配置.txt"));
	if (strPath != "")
	{
		auto AllServer = tenum_inifile(strPath, _T("全部大区"));
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
	((CComboBox*)GetDlgItem(IDC_CBX_2_4))->AddString(_T("手机号码登录"));
	((CComboBox*)GetDlgItem(IDC_CBX_2_4))->AddString(_T("输入其他账号后缀"));
	((CComboBox*)GetDlgItem(IDC_CBX_2_4))->SetCurSel(0);
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	((CComboBox*)GetDlgItem(IDC_CBX_2_5))->AddString(_T("第一个角色"));
	((CComboBox*)GetDlgItem(IDC_CBX_2_5))->AddString(_T("第二个角色"));
	((CComboBox*)GetDlgItem(IDC_CBX_2_5))->AddString(_T("第三个角色"));
	((CComboBox*)GetDlgItem(IDC_CBX_2_5))->SetCurSel(0);

	if (m_Dlg1Num != -1)
	{
		CString strItemText = m_list_b->GetItemText(m_Dlg1Num, 1);//区
		((CComboBox*)GetDlgItem(IDC_CBX_2_2))->SetWindowText(strItemText);
		strItemText = m_list_b->GetItemText(m_Dlg1Num, 2);//服
		((CComboBox*)GetDlgItem(IDC_CBX_2_3))->SetWindowText(strItemText);
		strItemText = m_list_b->GetItemText(m_Dlg1Num, 3);//帐
		GetDlgItem(IDC_EDIT_2_1)->SetWindowText(strItemText);
		strItemText = m_list_b->GetItemText(m_Dlg1Num, 4);//邮
		((CComboBox*)GetDlgItem(IDC_CBX_2_4))->SetWindowText(strItemText);
		strItemText = m_list_b->GetItemText(m_Dlg1Num, 5);//密
		GetDlgItem(IDC_EDIT_2_2)->SetWindowText(strItemText);
		strItemText = m_list_b->GetItemText(m_Dlg1Num, 6);//保
		GetDlgItem(IDC_EDIT_2_3)->SetWindowText(strItemText);
		strItemText = m_list_b->GetItemText(m_Dlg1Num, 7);//选
		if (strItemText == "0")
			strItemText = _T("第一个角色");
		else if (strItemText == "1")
			strItemText = _T("第二个角色");
		else if (strItemText == "2")
			strItemText = _T("第三个角色");
		((CComboBox*)GetDlgItem(IDC_CBX_2_5))->SetWindowText(strItemText);
		strItemText = m_list_b->GetItemText(m_Dlg1Num, 9);//脚本
		GetDlgItem(IDC_EDIT_2_6)->SetWindowText(strItemText);
		strItemText = m_list_b->GetItemText(m_Dlg1Num, 10);//备注
		GetDlgItem(IDC_EDIT_2_5)->SetWindowText(strItemText);
		BOOL bCheck = m_list_b->GetCheck(m_Dlg1Num);
		if (bCheck == TRUE)
		{
			((CComboBox*)GetDlgItem(IDC_CBX_2_1))->SetWindowText(_T("是"));
		}
	}

	return TRUE;
}


BEGIN_MESSAGE_MAP(DlgLoginAdd, CDialogEx)
	ON_CBN_SELCHANGE(IDC_CBX_2_2, &DlgLoginAdd::OnCbnSelchangeCbx22)
	ON_BN_CLICKED(IDC_BTN_LookFile, &DlgLoginAdd::OnBnClickedBtnLookfile)
	ON_BN_CLICKED(IDOK_BTN_Login, &DlgLoginAdd::OnBnClickedBtnLogin)
END_MESSAGE_MAP()


// DlgLoginAdd 消息处理程序


void DlgLoginAdd::OnCbnSelchangeCbx22()
{
	CString strText;
	((CComboBox*)GetDlgItem(IDC_CBX_2_2))->GetWindowText(strText);
	((CComboBox*)GetDlgItem(IDC_CBX_2_3))->ResetContent();
	CString	strPath = MyGetFilePathName(_T("服务器配置.txt"));
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
		TCHAR szFilter[] = _T("所有文件(*.*)|*.*||");
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
		strText8 = _T("是");
	else
		strText8 = _T("否");
	((CComboBox*)GetDlgItem(IDC_CBX_2_5))->GetWindowText(strText7);
	if (strText7 == _T("第一个角色"))
		strText7 = "0";
	else if (strText7 == _T("第二个角色"))
		strText7 = "1";
	else if (strText7 == _T("第三个角色"))
		strText7 = "2";
	GetDlgItem(IDC_EDIT_2_6)->GetWindowText(strText9);
	GetDlgItem(IDC_EDIT_2_5)->GetWindowText(strText10);

	if (strText0.IsEmpty())
	{
		AfxMessageBox(_T("选中设置不能为空！！"));
	}
	else if (strText1.IsEmpty())
	{
		AfxMessageBox(_T("大区设置不能为空！！"));
	}
	else if (strText2.IsEmpty())
	{
		AfxMessageBox(_T("服务器设置不能为空！！"));
	}
	else if (strText3.IsEmpty())
	{
		AfxMessageBox(_T("帐号设置不能为空！！"));
	}
	else if (strText4.IsEmpty())
	{
		AfxMessageBox(_T("后缀设置不能为空！！"));
	}
	else if (strText5.IsEmpty())
	{
		AfxMessageBox(_T("密码设置不能为空！！"));
	}
	else if (strText7.IsEmpty())
	{
		AfxMessageBox(_T("选择角色设置不能为空！！"));
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
			m_list_b->InsertItem(nCount, f);//序
		}
		m_list_b->SetItemText(nCount, 1, strText1);//区
		m_list_b->SetItemText(nCount, 2, strText2);//服
		m_list_b->SetItemText(nCount, 3, strText3);//帐
		m_list_b->SetItemText(nCount, 4, strText4);//邮
		m_list_b->SetItemText(nCount, 5, strText5);//密
		m_list_b->SetItemText(nCount, 6, strText6);//保
		m_list_b->SetItemText(nCount, 7, strText7);//选
		m_list_b->SetItemText(nCount, 8, strText8);//二
		m_list_b->SetItemText(nCount, 9, strText9);//脚本
		m_list_b->SetItemText(nCount, 10, strText10);//备注
		if (strText0 == _T("是"))
		{
			m_list_b->SetCheck(nCount);
		}
		CDialogEx::OnOK();
	}
}
