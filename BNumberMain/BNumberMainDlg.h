
// BNumberMainDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "TabDlgA.h"
#include "TabDlgB.h"

// CBNumberMainDlg 对话框
class CBNumberMainDlg : public CDialogEx
{
// 构造
public:
	CBNumberMainDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BNUMBERMAIN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
private:
	NOTIFYICONDATA m_notify;  //系统托盘类
	afx_msg LRESULT OnNotifyMsg(WPARAM wparam, LPARAM lparam);
	CTabCtrl m_tab;
	int m_CurSelTab;
	CTabDlgA m_pageA;
	CTabDlgB m_pageB;
	CDialog* pDialog[2];  //用来保存对话框对象指针  
public:
	afx_msg void OnClose();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
