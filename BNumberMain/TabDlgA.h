#pragma once
#include "afxcmn.h"


// CTabDlgA �Ի���

class CTabDlgA : public CDialogEx
{
	DECLARE_DYNAMIC(CTabDlgA)

public:
	CTabDlgA(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTabDlgA();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_a_list;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnPaint();
	afx_msg void OnBnClickedBtna1();
};
