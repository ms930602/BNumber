
// BNumberMainDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BNumberMain.h"
#include "BNumberMainDlg.h"
#include "afxdialogex.h"
#include "MSDll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

HWND g_MyHwnd = nullptr;

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBNumberMainDlg �Ի���



CBNumberMainDlg::CBNumberMainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_BNUMBERMAIN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBNumberMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}

BEGIN_MESSAGE_MAP(CBNumberMainDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_USER_NOTIFYICON, OnNotifyMsg)
	ON_WM_CLOSE()
	ON_WM_TIMER()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CBNumberMainDlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CBNumberMainDlg ��Ϣ�������

BOOL CBNumberMainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_tab.InsertItem(0, _T("����̨"));
	m_tab.InsertItem(1, _T("�˺���Ϣ"));
	m_pageA.Create(IDD_DIALOG1, &m_tab);
	m_pageB.Create(IDD_DIALOG2, &m_tab);
	//�趨��Tab����ʾ�ķ�Χ  
	CRect rc;
	m_tab.GetClientRect(rc);
	rc.top += 20;
	rc.bottom -= 0;
	rc.left += 0;
	rc.right -= 0;
	m_pageA.MoveWindow(&rc);
	m_pageB.MoveWindow(&rc);
	//�ѶԻ������ָ�뱣������  
	pDialog[0] = &m_pageA;
	pDialog[1] = &m_pageB;
	//��ʾ��ʼҳ��
	pDialog[0]->ShowWindow(SW_SHOW);
	pDialog[1]->ShowWindow(SW_HIDE);
	//���浱ǰѡ��  
	m_CurSelTab = 0;
	
	/***** Start *****
	����ͼ��
	*/
	m_notify.cbSize = sizeof(NOTIFYICONDATA);//�ṹ���С
	m_notify.hWnd = m_hWnd;//��Ӧ����
	m_notify.uID = IDR_MAINFRAME;//����id
	m_notify.hIcon = m_hIcon;//ͼ��

	_tcscpy(m_notify.szTip, _T("B������̨"));//��ʾ�ַ�

	m_notify.uCallbackMessage = WM_USER_NOTIFYICON;//������Ϣ
	m_notify.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP; //��Ч��־
	Shell_NotifyIcon(NIM_ADD, &m_notify);//�������
	/***** End *****
	����ͼ��
	*/
	g_MyHwnd = m_hWnd;
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CBNumberMainDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CBNumberMainDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CBNumberMainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

LRESULT CBNumberMainDlg::OnNotifyMsg(WPARAM wparam, LPARAM lparam)
//wParam���յ���ͼ���ID����lParam���յ���������Ϊ     
{
	if (wparam != IDR_MAINFRAME)
		return    1;
	switch (lparam)
	{
	case  WM_RBUTTONUP://�Ҽ�����ʱ������ݲ˵�������ֻ��һ�����رա�     
	{
		LPPOINT    lpoint = new    tagPOINT;
		::GetCursorPos(lpoint);//�õ����λ��     
		CMenu    menu;
		menu.CreatePopupMenu();//����һ������ʽ�˵�     
							   //���Ӳ˵���رա������������ϢWM_DESTROY�������ڣ���     
							   //���أ��������������    
		menu.AppendMenuW(MF_STRING, WM_DESTROY, _T("�ر�"));
		//ȷ������ʽ�˵���λ��     
		menu.TrackPopupMenu(TPM_LEFTALIGN, lpoint->x, lpoint->y, this);
		//��Դ����
		HMENU    hmenu = menu.Detach();
		menu.DestroyMenu();
		delete    lpoint;
	}
	break;
	case    WM_LBUTTONDBLCLK://˫������Ĵ���     
	{
		if (IsWindowVisible())
			ShowWindow(SW_HIDE);
		else
			ShowWindow(SW_SHOW);//�򵥵���ʾ���������¶� 
	}
	break;
	}
	return 0;
}



LRESULT CBNumberMainDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: Add your specialized code here and/or call the base class  
	switch (message) //�ж���Ϣ����  
	{
	case WM_SYSCOMMAND:
		//�����ϵͳ��Ϣ   
		if (wParam == SC_MINIMIZE)
		{
			//���յ���С����Ϣʱ����������   
			AfxGetApp()->m_pMainWnd->ShowWindow(SW_HIDE);
			return 0;
		}
		if (wParam == SC_CLOSE)
		{
			::Shell_NotifyIcon(NIM_DELETE, &m_notify); //�ر�ʱɾ��ϵͳ����ͼ��  
		}
		break;
	}
	return CDialog::WindowProc(message, wParam, lParam);
}


void CBNumberMainDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	if (IDNO == ::MessageBox(this->m_hWnd, _T("�˳������޷�ִ�нű����˳���?"), _T("����"),

		MB_ICONEXCLAMATION | MB_YESNO))
	{
		return;
	}
	else {

		CDialog::OnClose();
	}
}


void CBNumberMainDlg::OnTimer(UINT_PTR nIDEvent)
{
	CDialogEx::OnTimer(nIDEvent);
}


void CBNumberMainDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������  

	//�õ��µ�ҳ������  
	int index = m_CurSelTab;
	m_CurSelTab = m_tab.GetCurSel();
	if (m_CurSelTab != index) {
		//�ѵ�ǰ��ҳ����������  
		pDialog[index]->ShowWindow(SW_HIDE);
		//���µ�ҳ����ʾ����  
		pDialog[m_CurSelTab]->ShowWindow(SW_SHOW);
	}
	*pResult = 0;
}
