#pragma once


// DlgLoginAdd �Ի���

class DlgLoginAdd : public CDialogEx
{
	DECLARE_DYNAMIC(DlgLoginAdd)

public:
	DlgLoginAdd(CWnd* pParent, CListCtrl* plist_b, INT nDlg1Num = -1);   // ��׼���캯��
	virtual ~DlgLoginAdd();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_ADDLogin };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl* m_list_b;
	BOOL m_Dlg1Num;
public:
	afx_msg void OnCbnSelchangeCbx22();
	afx_msg void OnBnClickedBtnLookfile();
	afx_msg void OnBnClickedBtnLogin();
};
