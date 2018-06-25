// TabDlgA.cpp : 实现文件
//

#include "stdafx.h"
#include "BNumberMain.h"
#include "TabDlgA.h"
#include "afxdialogex.h"
#include "MSDll.h"
#include "GameDataFun.h"

// CTabDlgA 对话框

IMPLEMENT_DYNAMIC(CTabDlgA, CDialogEx)

CTabDlgA::CTabDlgA(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CTabDlgA::~CTabDlgA()
{
}

void CTabDlgA::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_A_LIST, m_a_list);
}


BEGIN_MESSAGE_MAP(CTabDlgA, CDialogEx)
	ON_WM_TIMER()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CTabDlgA 消息处理程序


BOOL CTabDlgA::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	/************************************************************************/
	/* CListCtrl设置类型                                               */
	/************************************************************************/
	m_a_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES | LVS_EX_MULTIWORKAREAS | LVS_EX_INFOTIP | LVS_EX_LABELTIP | LVS_EX_FLATSB);//加上鼠标移动到表格显示全部文字
	m_a_list.InsertColumn(0, _T("游戏ID"), NULL, 60, -1);
	m_a_list.InsertColumn(1, _T("脚本"), NULL, 100, -1);
	m_a_list.InsertColumn(2, _T("状况"), NULL, 100, -1);
	m_a_list.InsertColumn(3, _T("断线"), NULL, 50, -1);
	m_a_list.InsertColumn(4, _T("名称"), NULL, 80, -1);
	m_a_list.InsertColumn(5, _T("门派"), NULL, 60, -1);
	m_a_list.InsertColumn(6, _T("等级"), NULL, 50, -1);
	m_a_list.InsertColumn(7, _T("宠物"), NULL, 80, -1);
	m_a_list.InsertColumn(8, _T("地图"), NULL, 80, -1);
	m_a_list.InsertColumn(9, _T("坐标"), NULL, 80, -1);
	m_a_list.InsertColumn(10, _T("状态"), NULL, 80, -1);
	m_a_list.InsertColumn(11, _T("交子"), NULL, 60, -1);
	m_a_list.InsertColumn(12, _T("金钱"), NULL, 60, -1);
	m_a_list.InsertColumn(13, _T("元宝"), NULL, 60, -1);

	CString	strPath = MyGetFilePathName(_T("游戏路径.txt"));
	if (strPath != "")
	{
		CString strPathName;
		GetPrivateProfileString(_T("路径"), _T("游戏路径"), _T(""), strPathName.GetBuffer(MAX_PATH), MAX_PATH, strPath);
		strPathName.ReleaseBuffer();

		GetPrivateProfileString(_T("帐号"), _T("账号文件"), _T(""), strPathName.GetBuffer(MAX_PATH), MAX_PATH, strPath);
		strPathName.ReleaseBuffer();
		
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CTabDlgA::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nIDEvent)
	{
	case	1: {//该定时器是控制如果窗口不存在了就删除
		auto vGamePID = GetNameProcessId(_T("Game.exe"));
		INT i = 0;
		while (i < m_a_list.GetItemCount())
		{
			CString strPID = m_a_list.GetItemText(i, 0);
			DWORD dwPID = cstoul(strPID);

			vector<DWORD>::iterator result = find(vGamePID.begin(), vGamePID.end(), dwPID);
			if (result == vGamePID.end()) {//找到了不删 没找到就删除
				m_a_list.DeleteItem(i);
				--i;
			}
			++i;
		}
	}
			   break;
	case	2: {

	}
			   break;
	default:
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CTabDlgA::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CRect   rect;
	GetClientRect(rect);
	dc.FillSolidRect(rect, RGB(255, 255, 255));
}
