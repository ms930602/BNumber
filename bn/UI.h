#pragma once
#include "afxcmn.h"

#define WM_MY_MESSAGE (WM_USER+200)
#define WM_MYSTYLEEX_MESSAGE (WM_USER+201)
// UI 对话框

class UI : public CDialogEx
{
	DECLARE_DYNAMIC(UI)

public:
	UI(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~UI();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	int nUICreat = 0;//初始化隐藏窗口，用这个做标志
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);//消息拦截
	afx_msg void OnClose();
	afx_msg void OnNcPaint();
	afx_msg LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMyStyleMessage(WPARAM wParam, LPARAM lParam);
	CString strButton;
	CString strStopButton;
private:
	CTabCtrl m_UITable;
public:
	afx_msg void OnBnClickedBtnStart();
	afx_msg void OnBnClickedBtnSave();
	afx_msg void OnBnClickedAbort();
};
