// bn.cpp : ���� DLL �ĳ�ʼ�����̡�
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


// CbnApp ����

CbnApp::CbnApp()
{
	// TODO:  �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CbnApp ����

CbnApp theApp;


// CbnApp ��ʼ��

BOOL CbnApp::InitInstance()
{
	CWinApp::InitInstance();

	self = new CSelf;//��ʼ���ű�
	self->hDll = theApp.m_hInstance;
	self->CreateLogin(1);

	return TRUE;
}

int CbnApp::ExitInstance()
{
	return 0;
}
