#pragma once
#include "Function.h"
#include "LuaPlus.h"
using namespace LuaPlus;

class CSelfLua :
	public CFunction
{
public:
	CSelfLua() {};
	~CSelfLua() {};
public:


	int LUA_Sleep(LuaState* pState);

	int LUA_LoadScript(LuaState* pState);

	int LUA_GetTickCount(LuaState* pState);

	int LUA_Stop(LuaState* pState);

	int LUA_ShowMessage(LuaState* pState);

	/************************************************************************/
	/////////////////////////////NPC对话相关的函数封装//////////////
	/************************************************************************/
	int LUA_OpenNpcDlgByID(LuaState* pState);//打开NPC对话框，参数是npcID

	int LUA_SetAutoRunTargetNPCName(LuaState* pState);//打开NPC对话框，参数是npc名称

	int LUA_QuestFrameOptionClicked(LuaState* pState);//点击对话选项，参数是对话选项字符串

	int LUA_QuestFrameMissionContinue(LuaState* pState);//继续

	int LUA_MissionContinue_Clicked(LuaState* pState);//完成

	int LUA_MissionQuestAccept_Clicked(LuaState* pState);//完成

	int LUA_Quest_OnHidden(LuaState* pState);//关闭

	/************************************************************************/
	/////////////////////////////寻路相关的函数封装//////////////
	/************************************************************************/
	int  LUA_GetSceneId(LuaState* pState);//参数怪物名称杀怪

	int  LUA_FuBenMovTo(LuaState* pState);//副本移动到目标

	int  LUA_AutoRunToTarget(LuaState* pState);//移动到目标

	int  LUA_MoveToNPC(LuaState* pState);//参数怪物名称杀怪

	int  LUA_MoveTo(LuaState* pState);//移动函数

	int  LUA_Dismount(LuaState* pState);//骑马，下马函数

	/************************************************************************/
	/////////////////////////////采集与物品相关的函数封装//////////////
	/************************************************************************/
	int LUA_GetZHongDI_UI(LuaState* pState);//获取种植ui设置 

	int LUA_GetZuoWuNum(LuaState* pState);//获取空地上还有几个未收获的作物

	int LUA_GetScarecrowInfo(LuaState* pState);//获取空地，稻草人啊

	int LUA_GetCanQiangeTudi(LuaState* pState);//获取可以抢的早产土地

	int LUA_GetCollectInfo(LuaState* pState);//获取采集物品信息

	int LUA_Collect(LuaState* pState);//采集草药矿石物品

	int LUA_UserCollectSceneName(LuaState* pState);//采集场景的名字

	int LUA_UserBackCity(LuaState* pState);//用户回程

	int LUA_Player_UseSkill_Collect(LuaState* pState);//采集任务物品

	int LUA_CollectByName(LuaState* pState);//采集物品

	int LUA_GetTaskCollectByName(LuaState* pState);//获取采集物品

	int LUA_TaskCollect(LuaState* pState);//采集物品

	int LUA_PickUpItem(LuaState* pState);//拾取物品

	int LUA_UseItem(LuaState* pState);//使用物品

	int LUA_UseZhuangBei(LuaState* pState);//使用新手无忧物品

	int LUA_UserBag_CountItemByName(LuaState* pState);//查找物品

	int LUA_ShopBuy(LuaState* pState);//购买物品

	//int LUA_FreshManMission_JLYH_Frame(LuaState* pState);//立即装备

	//int LUA_FreshmanWatch_Time_Text(LuaState* pState);//领取物品

	/************************************************************************/
	/////////////////////////////怪物宠物周围环境相关的函数封装///////
	/************************************************************************/

	int LUA_FindCharacterByName(LuaState* pState);//查找怪物

	int LUA_GetAnyMonster(LuaState* pState);//查找怪物

	int LUA_KillAnyMonster(LuaState* pState);//杀怪物,可以指定类型

	int LUA_KillMonsterByName(LuaState* pState);//名称杀怪物

	int LUA_Go_Fight(LuaState* pState);//索引召唤宠物

	int LUA_FindPetByName(LuaState* pState);//查找宠物栏宠物

	int LUA_PetTrap(LuaState* pState);//抓捕宠物

	/************************************************************************/
	/////////////////////////////人物相关的函数封装///////
	/************************************************************************/

	int LUA_GetData(LuaState* pState);//玩家相关

	int LUA_ZhiLiao(LuaState* pState);//治疗

	int LUA_GetPos(LuaState* pState);//坐标

	int LUA_PassMap(LuaState* pState);//过图状态

	int LUA_InMenPai(LuaState* pState);//要加入的门派

	int LUA_GetActiveDataSceneID(LuaState* pState);//当前所在地图

	int LUA_GetActiveSceneName(LuaState* pState);//当前所在地图名字

	int LUA_AskLevelUp(LuaState* pState);//提升人物等级

	int LUA_RoleState(LuaState* pState);//人物状态

	int LUA_GetDistance(LuaState* pState);//获取距离

	int LUA_GetMountID(LuaState* pState);//获取骑乘ID

	/************************************************************************/
	//////////////////////////////队伍相关的函数封装///////
	/************************************************************************/

	int LUA_EnableTeamFollow(LuaState* pState);//跟随队长

	int LUA_InitiativeFollow(LuaState* pState);//主动跟随

	int LUA_IsTeamLeader(LuaState* pState);//是不是队长

	int LUA_IsTeamFollowState(LuaState* pState);//是不是队伍跟随状态中

	int LUA_FollowState(LuaState* pState);//跟随状态

	int LUA_GetAllTeamMember(LuaState* pState);//获取周边队友，都在身边返回总数，有一个不在身边的返回0

	int FUN_GetTeamMemberCount(LuaState* pState);//获取所有队员总数

	int LUA_FindTeamLeader(LuaState* pState);//队伍掉队了

	/************************************************************************/
	//////////////////////////////任务数据相关的函数封装///////
	/************************************************************************/

	int LUA_IsMissionCanCommit(LuaState* pState);//是否已经完成了任务

	int LUA_GetPlayerMission(LuaState* pState);//是否已经接取了任务

	int LUA_IsMissionOutline(LuaState* pState);//是否在可接任务列表

	int LUA_GetPlayerMission_Variable(LuaState* pState);//是否可交付

	int LUA_GetPlayerMissionInfo(LuaState* pState);//获取任务描述

	int LUA_GetPlayerMissionWhere(LuaState* pState);//获取任务多要求，个选项进度

	int LUA_GetNPCEventListInfo(LuaState* pState);//获取NPC对话选项的文本

	int LUA_DiscardedTask(LuaState* pState);//丢弃任务

	int LUA_GetDTInfo(LuaState* pState);//打图任务

	int LUA_GetDT_UIInfo(LuaState* pState);//打图环数，类型

	int LUA_SanCaiData(LuaState* pState);//三才峡谷

	int LUA_MaZeiData(LuaState* pState);//获取马贼

	int LUA_XiaoXiao(LuaState* pState);//获取江湖宵小

	int LUA_Get_XParam_INT(LuaState* pState);//快活三

	int LUA_IsWindowShow(LuaState* pState);//IsWindowShow

	int HaoYouZhuFu();//领取好友祝福聚宝盆奖励

	int LUA_DoString(LuaState* pState);//lua字符串函数

	int LUA_GetPlayerMission_DataCountByte(LuaState* pState);//任务进度

	int LUA_GetPlayerMission_UI(LuaState* pState);

	int LUA_PlaySound(LuaState* pState);

	int LUA_MessageBox(LuaState* pState);

	int LUA_GetDebugMessage(LuaState* pState);//获取调试信息

	int LUA_Script(LuaState* pState);

	int BuyShop_DiTan();

	int SellShop_DiTan();
};