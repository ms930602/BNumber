// TabDlgA.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BNumberMain.h"
#include "TabDlgA.h"
#include "afxdialogex.h"
#include "MSDll.h"

// CTabDlgA �Ի���

IMPLEMENT_DYNAMIC(CTabDlgA, CDialogEx)

CTabDlgA::CTabDlgA(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CTabDlgA::~CTabDlgA()
{
}

void CTabDlgA::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_A_LIST, m_a_list);
}


BEGIN_MESSAGE_MAP(CTabDlgA, CDialogEx)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CTabDlgA ��Ϣ��������


BOOL CTabDlgA::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ����Ӷ���ĳ�ʼ��
	/************************************************************************/
	/* CListCtrl��������                                               */
	/************************************************************************/
	m_a_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES | LVS_EX_MULTIWORKAREAS | LVS_EX_INFOTIP | LVS_EX_LABELTIP | LVS_EX_FLATSB);//��������ƶ���������ʾȫ������
	m_a_list.InsertColumn(0, _T("��ϷID"), NULL, 60, -1);
	m_a_list.InsertColumn(1, _T("�ű�"), NULL, 100, -1);
	m_a_list.InsertColumn(2, _T("״��"), NULL, 100, -1);
	m_a_list.InsertColumn(3, _T("����"), NULL, 50, -1);
	m_a_list.InsertColumn(4, _T("����"), NULL, 80, -1);
	m_a_list.InsertColumn(5, _T("����"), NULL, 60, -1);
	m_a_list.InsertColumn(6, _T("�ȼ�"), NULL, 50, -1);
	m_a_list.InsertColumn(7, _T("����"), NULL, 80, -1);
	m_a_list.InsertColumn(8, _T("��ͼ"), NULL, 80, -1);
	m_a_list.InsertColumn(9, _T("����"), NULL, 80, -1);
	m_a_list.InsertColumn(10, _T("״̬"), NULL, 80, -1);
	m_a_list.InsertColumn(11, _T("����"), NULL, 60, -1);
	m_a_list.InsertColumn(12, _T("��Ǯ"), NULL, 60, -1);
	m_a_list.InsertColumn(13, _T("Ԫ��"), NULL, 60, -1);
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CTabDlgA::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ�������Ϣ������������/�����Ĭ��ֵ
	switch (nIDEvent)
	{
	case	1: {//�ö�ʱ���ǿ���������ڲ������˾�ɾ��
		auto vGamePID = GetNameProcessId(_T("Game.exe"));
		INT i = 0;
		while (i < m_a_list.GetItemCount())
		{
			CString strPID = m_a_list.GetItemText(i, 0);
			DWORD dwPID = cstoul(strPID);

			vector<DWORD>::iterator result = find(vGamePID.begin(), vGamePID.end(), dwPID);
			if (result == vGamePID.end()) {//�ҵ��˲�ɾ û�ҵ���ɾ��
				m_a_list.DeleteItem(i);
				--i;
			}
			++i;
		}
	}
			   break;
	case	2: {

	}
			   break;
	default:
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}