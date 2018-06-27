// bn.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "bn.h"
#include "Self.h"

CSelf* self;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CbnApp

BEGIN_MESSAGE_MAP(CbnApp, CWinApp)
END_MESSAGE_MAP()


// CbnApp 构造

CbnApp::CbnApp()
{
	// TODO:  在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CbnApp 对象

CbnApp theApp;


// CbnApp 初始化

BOOL CbnApp::InitInstance()
{
	CWinApp::InitInstance();

	self = new CSelf;
	self->hDll = theApp.m_hInstance;
	self->CreatLogin(1);

	return TRUE;
}

int CbnApp::ExitInstance()
{

	delete self;

	return 0;
}
