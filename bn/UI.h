#pragma once
#include "afxcmn.h"

#define WM_MY_MESSAGE (WM_USER+200)
#define WM_MYSTYLEEX_MESSAGE (WM_USER+201)
// UI �Ի���

class UI : public CDialogEx
{
	DECLARE_DYNAMIC(UI)

public:
	UI(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~UI();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	int nUICreat = 0;//��ʼ�����ش��ڣ����������־
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);//��Ϣ����
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
