#pragma once
#include "User.h"
#include "MsPet.h"
#include "MsItem.h"
#include "MsRole.h"
#include "MsSkill.h"
#include "MsMonster.h"
#include "MsTeam.h"
#include "MsNpc.h"
#include "MsTask.h"
#include "FileSystem.h"
#include "GameFrame.h"

enum TASK_TYPE
{
	开始挂机 = 1,
	开始任务 = 2,
	开始调度 = 3,
	开始采集 = 4,
	开始刷马 = 5,
	开始打图 = 6,
	开始经商 = 7
};