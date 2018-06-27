// TabDlgB.cpp : 实现文件
//

#include "stdafx.h"
#include "BNumberMain.h"
#include "TabDlgB.h"
#include "afxdialogex.h"
#include "DlgLoginAdd.h"


// CTabDlgB 对话框

IMPLEMENT_DYNAMIC(CTabDlgB, CDialogEx)

CTabDlgB::CTabDlgB(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

CTabDlgB::~CTabDlgB()
{
}

void CTabDlgB::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_B, m_list_b);
}

void CTabDlgB::initLoginInfo()
{
	m_list_b.DeleteAllItems();
	CString	strPath = MyGetFilePathName(_T("游戏路径.ini"));
	if (strPath != "")
	{
		CString strPathName;

		GetPrivateProfileString(_T("账号"), _T("账号文件"), _T(""), strPathName.GetBuffer(MAX_PATH), MAX_PATH, strPath);
		strPathName.ReleaseBuffer();
		if (strPathName != "")
		{
			GetDlgItem(IDC_EDIT_zhPath)->SetWindowText(strPathName);
			CString CStr;
			INT nItem = m_list_b.GetItemCount();
			CStdioFile file(strPathName, CFile::modeRead);
			while (file.ReadString(CStr))//按行读
			{
				vector<CString> info = cstring_substr(CStr, _T(","), 1);
				if (info.size() == 11)//一共有11项
				{
					m_list_b.InsertItem(nItem, to_cstra(nItem + 1));//序
					m_list_b.SetItemText(nItem, 1, info[0]);//区
					m_list_b.SetItemText(nItem, 2, info[1]);//服
					m_list_b.SetItemText(nItem, 3, info[2]);//帐
					m_list_b.SetItemText(nItem, 4, info[3]);//邮
					m_list_b.SetItemText(nItem, 5, info[4]);//密
					m_list_b.SetItemText(nItem, 6, info[5]);//保
					m_list_b.SetItemText(nItem, 7, info[6]);//选
					m_list_b.SetItemText(nItem, 8, info[7]);//二
					m_list_b.SetItemText(nItem, 9, info[8]);//脚本
					m_list_b.SetItemText(nItem, 10, info[9]);//备注
					if (info[10] == _T("是"))
						m_list_b.SetCheck(nItem, 1);
					else if (info[10] == _T("否"))
						m_list_b.SetCheck(nItem, 0);
					++nItem;
				}
			}
		}
	}
}

BOOL CTabDlgB::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	/************************************************************************/
	/* CListCtrl设置类型                                               */
	/************************************************************************/
	m_list_b.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES | LVS_EX_MULTIWORKAREAS | LVS_EX_INFOTIP | LVS_EX_LABELTIP);//加上鼠标移动到表格显示全部文字
	m_list_b.InsertColumn(0, _T("序"), NULL, 50, -1);
	m_list_b.InsertColumn(1, _T("区"), NULL, 130, -1);
	m_list_b.InsertColumn(2, _T("服"), NULL, 130, -1);
	m_list_b.InsertColumn(3, _T("帐"), NULL, 160, -1);
	m_list_b.InsertColumn(4, _T("邮"), NULL, 70, -1);
	m_list_b.InsertColumn(5, _T("密"), NULL, 40, -1);
	m_list_b.InsertColumn(6, _T("保"), NULL, 40, -1);
	m_list_b.InsertColumn(7, _T("选"), NULL, 40, -1);
	m_list_b.InsertColumn(8, _T("二"), NULL, 40, -1);
	m_list_b.InsertColumn(9, _T("脚本"), NULL, 60, -1);
	m_list_b.InsertColumn(10, _T("备注"), NULL, 100, -1);
	m_list_b.InsertColumn(11, _T("状况"), NULL, 60, -1);
	m_list_b.InsertColumn(12, _T("断线"), NULL, 40, -1);
	m_list_b.InsertColumn(13, _T("名称"), NULL, 60, -1);
	m_list_b.InsertColumn(14, _T("门派"), NULL, 40, -1);
	m_list_b.InsertColumn(15, _T("等级"), NULL, 40, -1);
	m_list_b.InsertColumn(16, _T("宠物"), NULL, 50, -1);
	m_list_b.InsertColumn(17, _T("地图"), NULL, 60, -1);
	m_list_b.InsertColumn(18, _T("坐标"), NULL, 60, -1);
	m_list_b.InsertColumn(19, _T("状态"), NULL, 50, -1);
	m_list_b.InsertColumn(20, _T("交子"), NULL, 50, -1);
	m_list_b.InsertColumn(21, _T("金钱"), NULL, 50, -1);
	m_list_b.InsertColumn(22, _T("元宝"), NULL, 50, -1);

	initLoginInfo();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void CTabDlgB::OnClickMenuUpdate()
{
	size_t stCount = m_list_b.GetSelectedCount();
	if (stCount == 1)
	{
		POSITION   pos = m_list_b.GetFirstSelectedItemPosition();
		if (pos)
		{
			int index = m_list_b.GetNextSelectedItem(pos);
			DlgLoginAdd dla(NULL, &m_list_b, index);
			dla.DoModal();
		}
	}
	else if (stCount == 0)
	{
		AfxMessageBox(_T("请选中一个帐号"));
	}
	else if (stCount > 1)
	{
		AfxMessageBox(_T("每次只能修改一个帐号"));
	}
}

void CTabDlgB::OnClickMenuDelete()
{
	MessageBox("点击了删除");
}


BEGIN_MESSAGE_MAP(CTabDlgB, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CTabDlgB::OnBnClickedButton1)
	ON_COMMAND(ID_32771, &CTabDlgB::OnClickMenuUpdate)
	ON_COMMAND(ID_32772, &CTabDlgB::OnClickMenuDelete)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_B, &CTabDlgB::OnNMRClickListB)
	ON_BN_CLICKED(IDC_BTN_2_save, &CTabDlgB::OnBnClickedBtn2save)
	ON_BN_CLICKED(IDC_BTN_2_refresh, &CTabDlgB::OnBnClickedBtn2refresh)
	ON_BN_CLICKED(IDC_BTN_2_FLook, &CTabDlgB::OnBnClickedBtn2Flook)
	ON_BN_CLICKED(IDC_BTN_fLook2, &CTabDlgB::OnBnClickedBtnflook2)
END_MESSAGE_MAP()


// CTabDlgB 消息处理程序

void CTabDlgB::OnBnClickedButton1()
{
	DlgLoginAdd dla(NULL, &m_list_b);
	dla.DoModal();
}


void CTabDlgB::OnNMRClickListB(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CMenu menu, *pPopup;
	menu.LoadMenu(IDR_MENU_List_2);
	pPopup = menu.GetSubMenu(0);
	CPoint myPoint;
	ClientToScreen(&myPoint);
	GetCursorPos(&myPoint); //鼠标位置  
	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, myPoint.x, myPoint.y, this);
	*pResult = 0;
}


void CTabDlgB::OnBnClickedBtn2save()
{
	try
	{
		CString	strPath = MyGetFilePathName(_T("游戏路径.ini"));
		CString strPathName;
		GetPrivateProfileString(_T("账号"), _T("账号文件"), _T(""), strPathName.GetBuffer(MAX_PATH), MAX_PATH, strPath);
		strPathName.ReleaseBuffer();
		if (strPathName != "")
		{
				CString CStrText;
				INT nCount = m_list_b.GetItemCount();
				for (INT i = 0; i < nCount; i++)
				{
					CString strItemText = m_list_b.GetItemText(i, 1);//区
					CStrText = CStrText + strItemText + _T(",");
					strItemText = m_list_b.GetItemText(i, 2);//服
					CStrText = CStrText + strItemText + _T(",");
					strItemText = m_list_b.GetItemText(i, 3);//帐
					CStrText = CStrText + strItemText + _T(",");
					strItemText = m_list_b.GetItemText(i, 4);//邮
					CStrText = CStrText + strItemText + _T(",");
					strItemText = m_list_b.GetItemText(i, 5);//密
					CStrText = CStrText + strItemText + _T(",");
					strItemText = m_list_b.GetItemText(i, 6);//保
					CStrText = CStrText + strItemText + _T(",");
					strItemText = m_list_b.GetItemText(i, 7);//选
					CStrText = CStrText + strItemText + _T(",");
					strItemText = m_list_b.GetItemText(i, 8);//二
					CStrText = CStrText + strItemText + _T(",");
					strItemText = m_list_b.GetItemText(i, 9);//脚本
					CStrText = CStrText + strItemText + _T(",");
					strItemText = m_list_b.GetItemText(i, 10);//备注
					CStrText = CStrText + strItemText + _T(",");
					if (m_list_b.GetCheck(i))
						strItemText = _T("是");
					else
						strItemText = _T("否");
					CStrText = CStrText + strItemText + _T(",\n");
				}
				//////////////////////////////////////////////////////////////////////////
				//设置文件的打开参数
				if (!CStrText.IsEmpty())
				{
					CStdioFile outFile(strPathName, CFile::modeNoTruncate | CFile::modeCreate | CFile::modeWrite | CFile::typeText);
					outFile.SetLength(0);
					outFile.WriteString(CStrText);
					outFile.Close();
				}
				::MessageBox(NULL, _T("保存成功！"), _T("提示"), MB_OK);
		}
		else
		{
			AfxMessageBox(_T("保存文件不存在!"));
		}

	}
	catch (CFileException* e)
	{
		e->Delete();
	}
}

void CTabDlgB::OnBnClickedBtn2refresh()
{
	initLoginInfo();
}


void CTabDlgB::OnBnClickedBtn2Flook()
{
	try {
		TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt||");
		CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter);
		if (dlg.DoModal() == IDOK)
		{
			CString CStrScript = dlg.GetPathName();
			if (!CStrScript.IsEmpty())
			{
				CString	strPath = MyGetFilePathName(_T("游戏路径.ini"));
				WritePrivateProfileString(_T("账号"), _T("账号文件"), CStrScript, strPath);
				GetDlgItem(IDC_EDIT_zhPath)->SetWindowText(CStrScript);
				this->initLoginInfo();
			}
		}
	}
	catch (CFileException* e)
	{
		e->Delete();
	}
}


void CTabDlgB::OnBnClickedBtnflook2()
{
	try {
		TCHAR szFilter[] = _T("游戏执行文件(Launch.exe)|Launch.exe||");
		CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter);
		if (dlg.DoModal() == IDOK)
		{
			CString CStrScript = dlg.GetPathName();
			if (!CStrScript.IsEmpty())
			{
				CString	strPath = MyGetFilePathName(_T("游戏路径.ini"));
				WritePrivateProfileString(_T("路径"), _T("游戏路径"), CStrScript, strPath);
				GetDlgItem(IDC_EDIT_GamePath)->SetWindowText(CStrScript);
				this->initLoginInfo();
			}
		}
	}
	catch (CFileException* e)
	{
		e->Delete();
	}
}
