#pragma once
#include "afxcmn.h"


// CTabDlgB �Ի���

class CTabDlgB : public CDialogEx
{
	DECLARE_DYNAMIC(CTabDlgB)

public:
	CTabDlgB(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTabDlgB();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
private:
	void initLoginInfo();
public:
	CListCtrl m_list_b;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnClickMenuUpdate();
	afx_msg void OnClickMenuDelete();
	afx_msg void OnNMRClickListB(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtn2save();
	afx_msg void OnBnClickedBtn2refresh();
	afx_msg void OnBnClickedBtn2Flook();
	afx_msg void OnBnClickedBtnflook2();
};
