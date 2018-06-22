
// BNumberMainDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "TabDlgA.h"
#include "TabDlgB.h"

// CBNumberMainDlg �Ի���
class CBNumberMainDlg : public CDialogEx
{
// ����
public:
	CBNumberMainDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BNUMBERMAIN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
private:
	NOTIFYICONDATA m_notify;  //ϵͳ������
	afx_msg LRESULT OnNotifyMsg(WPARAM wparam, LPARAM lparam);
	CTabCtrl m_tab;
	int m_CurSelTab;
	CTabDlgA m_pageA;
	CTabDlgB m_pageB;
	CDialog* pDialog[2];  //��������Ի������ָ��  
public:
	afx_msg void OnClose();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
