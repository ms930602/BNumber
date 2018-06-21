// UI.cpp : 实现文件
//

#include "stdafx.h"
#include "bn.h"
#include "UI.h"
#include "afxdialogex.h"


// UI 对话框

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


// UI 消息处理程序


void UI::OnBnClickedBtnStart()
{
	// TODO: 在此添加控件通知处理程序代码
}


void UI::OnBnClickedBtnSave()
{
	// TODO: 在此添加控件通知处理程序代码
}


void UI::OnBnClickedAbort()
{
	// TODO: 在此添加控件通知处理程序代码
}
