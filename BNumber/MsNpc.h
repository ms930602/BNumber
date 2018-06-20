#pragma once
#include "MsIndex.h"
using namespace std;

struct TMsNpc
{
	char* szName;
	INT nOptionsA;
	INT nOptionsB;
	INT nOptionsC;
	
	TMsNpc() {
		szName = "";
		nOptionsA = 0;
		nOptionsB = 0;
		nOptionsC = 0;
	}
};

typedef vector<TMsNpc> VMsNpc;

class CMsNpc
{
public:
	CMsNpc();
	~CMsNpc();
public:
	VMsNpc GetNpcDatas();
	VMsNpc vm_Npc;
};