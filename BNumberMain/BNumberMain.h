
// BNumberMain.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CBNumberMainApp: 
// �йش����ʵ�֣������ BNumberMain.cpp
//

class CBNumberMainApp : public CWinApp
{
public:
	CBNumberMainApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CBNumberMainApp theApp;