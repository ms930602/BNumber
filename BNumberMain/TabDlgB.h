#pragma once


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

	DECLARE_MESSAGE_MAP()
};
