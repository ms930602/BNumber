#pragma once

#include "MsIndex.h"

using namespace std;

struct TMsTask//任务数据
{
	DWORD  dwTree;
	char*  szName;
	int    nTaskID;
	int   nSchedule;
	int   nVa1;
	int   nVa2;
	int   nVa3;

	TMsTask()
	{
		dwTree = 0;
		szName = "";
		nTaskID = -1;
		nSchedule = FALSE;
		nVa1 = -1;
		nVa2 = -1;
		nVa3 = -1;
	};
};

typedef vector<TMsTask> VMsTask;

class CMsTask
{
public:
	CMsTask();
	~CMsTask();
public:
	VMsTask GetData();//获取任务数据
	DWORD GetTaskName(INT TaskID);
	void  DiscardedTask(int nTaskID);//放弃任务
};