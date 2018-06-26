// TabDlgB.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BNumberMain.h"
#include "TabDlgB.h"
#include "afxdialogex.h"
#include "DlgLoginAdd.h"


// CTabDlgB �Ի���

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
	CString	strPath = MyGetFilePathName(_T("��Ϸ·��.ini"));
	if (strPath != "")
	{
		CString strPathName;

		GetPrivateProfileString(_T("�˺�"), _T("�˺��ļ�"), _T(""), strPathName.GetBuffer(MAX_PATH), MAX_PATH, strPath);
		strPathName.ReleaseBuffer();
		if (strPathName != "")
		{
			GetDlgItem(IDC_EDIT_zhPath)->SetWindowText(strPathName);
			CString CStr;
			INT nItem = m_list_b.GetItemCount();
			CStdioFile file(strPathName, CFile::modeRead);
			while (file.ReadString(CStr))//���ж�
			{
				vector<CString> info = cstring_substr(CStr, _T(","), 1);
				if (info.size() == 11)//һ����11��
				{
					m_list_b.InsertItem(nItem, to_cstra(nItem + 1));//��
					m_list_b.SetItemText(nItem, 1, info[0]);//��
					m_list_b.SetItemText(nItem, 2, info[1]);//��
					m_list_b.SetItemText(nItem, 3, info[2]);//��
					m_list_b.SetItemText(nItem, 4, info[3]);//��
					m_list_b.SetItemText(nItem, 5, info[4]);//��
					m_list_b.SetItemText(nItem, 6, info[5]);//��
					m_list_b.SetItemText(nItem, 7, info[6]);//ѡ
					m_list_b.SetItemText(nItem, 8, info[7]);//��
					m_list_b.SetItemText(nItem, 9, info[8]);//�ű�
					m_list_b.SetItemText(nItem, 10, info[9]);//��ע
					if (info[10] == _T("��"))
						m_list_b.SetCheck(nItem, 1);
					else if (info[10] == _T("��"))
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

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	/************************************************************************/
	/* CListCtrl��������                                               */
	/************************************************************************/
	m_list_b.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES | LVS_EX_MULTIWORKAREAS | LVS_EX_INFOTIP | LVS_EX_LABELTIP);//��������ƶ��������ʾȫ������
	m_list_b.InsertColumn(0, _T("��"), NULL, 50, -1);
	m_list_b.InsertColumn(1, _T("��"), NULL, 130, -1);
	m_list_b.InsertColumn(2, _T("��"), NULL, 130, -1);
	m_list_b.InsertColumn(3, _T("��"), NULL, 160, -1);
	m_list_b.InsertColumn(4, _T("��"), NULL, 70, -1);
	m_list_b.InsertColumn(5, _T("��"), NULL, 40, -1);
	m_list_b.InsertColumn(6, _T("��"), NULL, 40, -1);
	m_list_b.InsertColumn(7, _T("ѡ"), NULL, 40, -1);
	m_list_b.InsertColumn(8, _T("��"), NULL, 40, -1);
	m_list_b.InsertColumn(9, _T("�ű�"), NULL, 60, -1);
	m_list_b.InsertColumn(10, _T("��ע"), NULL, 100, -1);
	m_list_b.InsertColumn(11, _T("״��"), NULL, 60, -1);
	m_list_b.InsertColumn(12, _T("����"), NULL, 40, -1);
	m_list_b.InsertColumn(13, _T("����"), NULL, 60, -1);
	m_list_b.InsertColumn(14, _T("����"), NULL, 40, -1);
	m_list_b.InsertColumn(15, _T("�ȼ�"), NULL, 40, -1);
	m_list_b.InsertColumn(16, _T("����"), NULL, 50, -1);
	m_list_b.InsertColumn(17, _T("��ͼ"), NULL, 60, -1);
	m_list_b.InsertColumn(18, _T("����"), NULL, 60, -1);
	m_list_b.InsertColumn(19, _T("״̬"), NULL, 50, -1);
	m_list_b.InsertColumn(20, _T("����"), NULL, 50, -1);
	m_list_b.InsertColumn(21, _T("��Ǯ"), NULL, 50, -1);
	m_list_b.InsertColumn(22, _T("Ԫ��"), NULL, 50, -1);

	initLoginInfo();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
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
		AfxMessageBox(_T("��ѡ��һ���ʺ�"));
	}
	else if (stCount > 1)
	{
		AfxMessageBox(_T("ÿ��ֻ���޸�һ���ʺ�"));
	}
}

void CTabDlgB::OnClickMenuDelete()
{
	MessageBox("�����ɾ��");
}


BEGIN_MESSAGE_MAP(CTabDlgB, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CTabDlgB::OnBnClickedButton1)
	ON_COMMAND(ID_32771, &CTabDlgB::OnClickMenuUpdate)
	ON_COMMAND(ID_32772, &CTabDlgB::OnClickMenuDelete)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_B, &CTabDlgB::OnNMRClickListB)
	ON_BN_CLICKED(IDC_BTN_2_save, &CTabDlgB::OnBnClickedBtn2save)
	ON_BN_CLICKED(IDC_BTN_2_refresh, &CTabDlgB::OnBnClickedBtn2refresh)
	ON_BN_CLICKED(IDC_BTN_2_FLook, &CTabDlgB::OnBnClickedBtn2Flook)
END_MESSAGE_MAP()


// CTabDlgB ��Ϣ�������

void CTabDlgB::OnBnClickedButton1()
{
	DlgLoginAdd dla(NULL, &m_list_b);
	dla.DoModal();
}


void CTabDlgB::OnNMRClickListB(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMenu menu, *pPopup;
	menu.LoadMenu(IDR_MENU_List_2);
	pPopup = menu.GetSubMenu(0);
	CPoint myPoint;
	ClientToScreen(&myPoint);
	GetCursorPos(&myPoint); //���λ��  
	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, myPoint.x, myPoint.y, this);
	*pResult = 0;
}


void CTabDlgB::OnBnClickedBtn2save()
{
	try
	{
		CString	strPath = MyGetFilePathName(_T("��Ϸ·��.ini"));
		CString strPathName;
		GetPrivateProfileString(_T("�˺�"), _T("�˺��ļ�"), _T(""), strPathName.GetBuffer(MAX_PATH), MAX_PATH, strPath);
		strPathName.ReleaseBuffer();
		if (strPathName != "")
		{
				CString CStrText;
				INT nCount = m_list_b.GetItemCount();
				for (INT i = 0; i < nCount; i++)
				{
					CString strItemText = m_list_b.GetItemText(i, 1);//��
					CStrText = CStrText + strItemText + _T(",");
					strItemText = m_list_b.GetItemText(i, 2);//��
					CStrText = CStrText + strItemText + _T(",");
					strItemText = m_list_b.GetItemText(i, 3);//��
					CStrText = CStrText + strItemText + _T(",");
					strItemText = m_list_b.GetItemText(i, 4);//��
					CStrText = CStrText + strItemText + _T(",");
					strItemText = m_list_b.GetItemText(i, 5);//��
					CStrText = CStrText + strItemText + _T(",");
					strItemText = m_list_b.GetItemText(i, 6);//��
					CStrText = CStrText + strItemText + _T(",");
					strItemText = m_list_b.GetItemText(i, 7);//ѡ
					CStrText = CStrText + strItemText + _T(",");
					strItemText = m_list_b.GetItemText(i, 8);//��
					CStrText = CStrText + strItemText + _T(",");
					strItemText = m_list_b.GetItemText(i, 9);//�ű�
					CStrText = CStrText + strItemText + _T(",");
					strItemText = m_list_b.GetItemText(i, 10);//��ע
					CStrText = CStrText + strItemText + _T(",");
					if (m_list_b.GetCheck(i))
						strItemText = _T("��");
					else
						strItemText = _T("��");
					CStrText = CStrText + strItemText + _T(",\n");
				}
				//////////////////////////////////////////////////////////////////////////
				//�����ļ��Ĵ򿪲���
				if (!CStrText.IsEmpty())
				{
					CStdioFile outFile(strPathName, CFile::modeNoTruncate | CFile::modeCreate | CFile::modeWrite | CFile::typeText);
					outFile.SetLength(0);
					outFile.WriteString(CStrText);
					outFile.Close();
				}
				::MessageBox(NULL, _T("����ɹ���"), _T("��ʾ"), MB_OK);
		}
		else
		{
			AfxMessageBox(_T("�����ļ�������!"));
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
		TCHAR szFilter[] = _T("�ı��ļ�(*.txt)|*.txt||");
		CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter);
		if (dlg.DoModal() == IDOK)
		{
			CString CStrScript = dlg.GetPathName();
			if (!CStrScript.IsEmpty())
			{
				CString	strPath = MyGetFilePathName(_T("��Ϸ·��.ini"));
				WritePrivateProfileString(_T("�˺�"), _T("�˺��ļ�"), CStrScript, strPath);
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
