#pragma once
#include "afxcmn.h"


// CTabDlgA 对话框

class CTabDlgA : public CDialogEx
{
	DECLARE_DYNAMIC(CTabDlgA)

public:
	CTabDlgA(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTabDlgA();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_a_list;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnPaint();
};
