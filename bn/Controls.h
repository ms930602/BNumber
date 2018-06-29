#pragma once
#include "stdafx.h"
#include <vector>

using namespace std;

struct  tagCONTROLS
{
	DWORD CtrAddress = 0;
	PCHAR Name = "";
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
};

class CControls
{
public:
	CControls();
	~CControls();

	vector<tagCONTROLS> m_vCtrl;
	DWORD ControlsCount(DWORD ControlsBase);
	DWORD ControlsAddress(size_t i, DWORD ControlsBase);
	DWORD ControlsState(DWORD ControlsAddr);
	DWORD ControlsType(DWORD ControlsAddr);
	void ControlsName(DWORD Type, DWORD ControlsAddr);
	void Controlsinformation(DWORD ControlsBase);
	BOOL ControlsTraverse();//指定copy的副本类型

};
