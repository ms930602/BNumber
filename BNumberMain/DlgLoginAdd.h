#pragma once


// DlgLoginAdd 对话框

class DlgLoginAdd : public CDialogEx
{
	DECLARE_DYNAMIC(DlgLoginAdd)

public:
	DlgLoginAdd(CWnd* pParent, CListCtrl* plist_b, INT nDlg1Num = -1);   // 标准构造函数
	virtual ~DlgLoginAdd();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_ADDLogin };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
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
