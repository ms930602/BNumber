// UI.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "bn.h"
#include "UI.h"
#include "afxdialogex.h"

// UI �Ի���

IMPLEMENT_DYNAMIC(UI, CDialogEx)

UI::UI(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

UI::~UI()
{
}

void UI::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_UITable);
}


BEGIN_MESSAGE_MAP(UI, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_START, &UI::OnBnClickedBtnStart)
	ON_BN_CLICKED(IDC_BTN_SAVE, &UI::OnBnClickedBtnSave)
	ON_BN_CLICKED(IDABORT, &UI::OnBnClickedAbort)
END_MESSAGE_MAP()


// UI ��Ϣ�������


void UI::OnBnClickedBtnStart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void UI::OnBnClickedBtnSave()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void UI::OnBnClickedAbort()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
