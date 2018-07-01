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

class CFunction
{
public:
	CFunction();
	~CFunction();

public:
	/************************************************************************/
	/////////////////////////////人物信息相关的函数封装//////////////
	/************************************************************************/
	bool FUN_IsStateValue(int nState);//判断人物的状态值
	void FUN_WaitTime(int nState);//使用发功运气技能的阻塞函数
	void FUN_LevelUp(); //提升人物等级
	bool FUN_IsTeamFollowStateValue(int nState);//判断人物组队跟随状态值
public:
	/************************************************************************/
	/////////////////////////////寻路相关的函数封装//////////////
	/************************************************************************/
	bool FUN_IsFuBenSceneId(int nSceneId);//副本场景ID
	void FUN_FuBenRunTo(float x, float y, int nID);//副本寻路
	int FUN_GetSceneID(const char* szSceneName);//通过名称获取地图场景ID
	float FUN_GetDistance(float x2, float y2);//获取与目标的距离
	void  FUN_KaTuMov(float fOldX, float fOldY);//防卡图
	void  FUN_OutHell();//走出地府
	void  FUN_OutJianYU();//走出监狱
	BOOL  FUN_RunToTarget(float x, float y, bool bRide = true); //本地寻路函数
	BOOL  FUN_RunToTargetEx(float x, float y, int SceneId, bool bRide = true);//跨地图寻路
	void  FUN_BackCityFunc();//寻路回城，或者技能回城
	void  FUN_RunTo(float x, float y, int nTime);//不卡状态寻路
public:
	int   FUN_ZhiLiao();//满血治疗
public:
	/************************************************************************/
	/////////////////////////////装备相关的函数//////////////
	/************************************************************************/
	float FUN_GetEquipmentNaiJiuRatio(int nType, float fVal);//获取装备耐久是否低于上限%
	int  FUN_GetEquipmentNaiJiu(int nNum = -1, int nType = -1);//获取装备耐久是否低于下限
public:
	/************************************************************************/
	/////////////////////////////物品相关的函数封装//////////////
	/************************************************************************/
	int FUN_GetItemCountByName(CString CstrName, int nIndex = 1);//获取指定的背包物品总数
	int FUN_GetItemCountByTypeName(CString CstrType, CString CstrInfo, int nIndex, BOOL bFindInfo = TRUE);//物品类型查找
	void FUN_BuyDrugByName(CString CstrName, int nNum);//买药通过名称
	void FUN_UseItem(CString CstrName, int nIndex);//使用物品
public:
	/************************************************************************/
	/////////////////////////////采集相关的函数封装//////////////
	/************************************************************************/
	TMsCollect FUN_GetCollectByName(CString CstrName);//获取采集对象
	void FUN_CollectByName(CString CstrName);//采集函数
	int FUN_Collect(int CollectID);//采集草药矿石
	bool FUN_IsCAIYAO(CString CstrCaoYao);
	bool FUN_IsCAIKUANG(CString CstrCAIKUANG);

public:
	/************************************************************************/
	/////////////////////////////地面包裹的函数封装//////////////
	/************************************************************************/
	int FUN_PickupGroundParcelItem(CString CstrName, int nVal = 0);
	BOOL FUN_FindItemById(TMsGroundParcel GroundParcel);//如果包裹不在过滤包裹中就移动到包裹旁
	BOOL FUN_PickupUserSetupItem(CString CstrName, int GroundParcelId, int nVal = 0);
	void FUN_RemoveFilterId();
	bool FUN_FindGroundParcelId(INT ParcelId);//在包裹二叉树中查找过滤id是否有效
	BOOL FUN_UserWantItem(CString CstrName, int nVal = 0);

public:
	/************************************************************************/
	/////////////////////////////宠物相关的函数封装//////////////
	/************************************************************************/
	TMsPet FUN_GetPetById(int nPetId);//根据名字获取宠物信息
	TMsPet FUN_GetPetByName(CString PetName);//根据名字获取宠物信息
	void FUN_UseFighPetSkillByName(VUserSkillName& v_Skill, int nPetID);//战斗宠物技能
	void FUN_CallPetByName(CString PetName);//释放出宠物
	void FUN_PotentialUp();//分配宠物点
	void FUN_UseFightPetSkill();//战斗宠物技能
	void FUN_CallFightPet();//释放出战斗宠物
	void FUN_CallXueJiPet();
	void FUN_CallGongShengPet();
	void FUN_CallMaxLevelPet();//释放出最大等级的宠物
	TMsPet FUN_GetMaxLevelPet();//获取最大等级宠物信息
public:
	/************************************************************************/
	/////////////////////////////玩家队伍相关的函数封装//////////////
	/************************************************************************/
	TMsPlayer FUN_GetPlayerByID(int nPlayerId);//通过获取玩家信息
	TMsPlayer FUN_GetPlayerByName(CString PlayerName, int nCMP_TYPE = 1);//通过名称获取玩家信息
	TMsTeam  FUN_GetTeamLeader();//获取队长信息
	TMsTeam  FUN_GetAllTeamMember();//获取所有队员在不在身边
	void FUN_RunToLeader(TMsPlayer leader);//移动到队长身边
	void FUN_AcceptTeam();//是否自动接收组队邀请
	TMsMonster FUN_GetLeaderMonster(int nLeaderMonster);//获取队长打的怪物
	void FUN_AssistAttack();//协助队友攻击
	void FUN_UseEMeiBloodSkill(int nPlayerId);//使用峨嵋加血技能
	void FUN_EMeiTeamerBlood();//给队友加血
	void FUN_EMeiPlayerBlood();//给指定玩家加血
	void FUN_ActionEMeiSkill(TMsSkill tAsmSkill, TMsPlayer tAsmPlayer);//开始释放峨嵋加血技能
	void FUN_TeamFollow(bool bFollow);//组队跟随队列
	void FUN_GameSetupTeamFollow();//设置组队跟随队列
	void FUN_FollowLeader();//跟随队长
	void FUN_InitiativeFollowLeader();//手动主动跟随队长
public:
	/************************************************************************/
	/////////////////////////////技能打怪相关的函数封装//////////////
	/************************************************************************/
	TMsSkill FUN_GetLXUSkillInfo();//获取门派攻击技能
	TMsMonster FUN_GetNpcByName(CString MonsterName, int nType);//名称获取npc
	bool FUN_TimeChange(TUserTime* ptUserTime);//时间检测
	TMsSkill FUN_GetSkillInfo(CString SkillName);//获取指定技能信息
	void FUN_UseMovAttackSkill(TMsSkill tAsmSkill, TMsMonster tAsmMonster);//开始释放攻击技能
	float FUN_MaximumRange(TMsSkill tAsmSkill);//技能攻击射程
	bool FUN_MovToMonster(TMsMonster tAsmMonster, TMsSkill tAsmSkill);//走到技能射程内
	void FUN_ActionAttackSkill(TMsSkill tAsmSkill, TMsMonster tAsmMonster);//开始释放技能
	void FUN_AttackSkillSort(TMsSkill tAsmSkill, TMsMonster tAsmMonster);//攻击技能分类
	void FUN_UseStrongSkill();//使用增强自身的技能
	void FUN_UseAttackSkill(TMsSkill tAsmSkill/*CString SkillName*/, TMsMonster tAsmMonster);//使用攻击技能
	void FUN_UseSkillKillMonster(TMsMonster tAsmMonster, int nMonsterType = 0, int nKillType = 2);
	bool FUN_MinDistanceObject(float* fdistance, float fx, float fy);	//true是最近的
	TMsMonster FUN_GetMonsterByName(CString MonsterName, int nMonsterType, int nKillType);//名称获取最近的怪物
	int FUN_GetFuJinMonsterNum();	//获取距离最近的任意怪物
	TMsMonster FUN_GetAnyMonster(int nMonsterType, int nKillType);//获取最近的任意怪物
	bool FUN_IsMonsterDie(TMsMonster* ptAsmMonster);//false为死亡
	BOOL FUN_KillAnyMonster(int nMonsterType, int nKillType = 2);//杀任意怪
	BOOL FUN_KillMonsterByName(VUserMonsterName vm_UserMonsterName, int nMonsterType, int nKillType = 2);//杀指定怪//0普攻杀怪， 1技能杀怪 ， 2任务杀怪

	/************************************************************************/
	/* 主线任务打怪函数                                                                     */
	/************************************************************************/
	VMsSkill  FUN_UserGetSkill();//获取技能
	BOOL FUN_MisKillAnyMonster(int nMonsterType, int nKillType);//杀任意怪
	BOOL FUN_MisKillMonsterByName(VUserMonsterName vm_UserMonsterName, int nMonsterType, int nKillType);//杀指定怪
	void FUN_MisUseSkillKillMonster(TMsMonster tAsmMonster, int nMonsterType, int nKillType);
};

//获取人物的最新信息出错时的日志消息，并作相应的处理
#define 获取人物信息异常日志(ARoleInfo,command)\
if (!ARoleInfo.bool_ret)\
{\
	dbgPrint("获取人物信息Info失败__FUNCTION__%s__FILE__%s__LINE__%d",__FUNCTION__,__FILE__,__LINE__);\
	command;\
}

//获取人物的最新信息出错时的日志消息
#define 获取人物坐标异常日志(APos,command)\
if (!APos.bool_ret)\
{\
	dbgPrint("获取人物坐标Pos失败__FUNCTION__%s__FILE__%s__LINE__%d",__FUNCTION__,__FILE__,__LINE__);\
	command;\
}

#define 防卡图更新人物原始坐标(dwBGTime,fOldX,fOldY,APos)  \
fOldX = APos.fx;\
fOldY = APos.fy;\
dwBGTime = GetTickCount();

#define 防卡图定时检测人物位置(dwBGTime,fOldX, fOldY)  \
DWORD dwEDTime = GetTickCount();\
if (dwEDTime - dwBGTime > 5000)\
{\
	FUN_KaTuMov(fOldX, fOldY);\
	auto APos = pAsmRole->GetPos();\
	获取人物坐标异常日志(APos, break)\
	防卡图更新人物原始坐标(dwBGTime,fOldX,fOldY,APos) \
}

#define 跨场景(pMsRole,command)\
  if (pMsRole->pass_map()){ \
    while (true)\
	{\
		if (pMsRole->pass_map() == 0)\
			break;\
		Sleep(500) ;\
	}\
Sleep(5000) ; \
command;}

struct TMsMap
{
	BOOL bool_ret;
	int nSceneId;
	CString szName;

	TMsMap()
	{
		bool_ret = FALSE;
		nSceneId = -1;
		szName = "";
	};
};
TMsMap role_curmap();

//--数据池中定义的装备数据.
enum EFunEquip
{
	武器 = 0,		//武器	WEAPON
	帽子 = 1,		//帽子	DEFENCE
	衣服 = 2,		//衣服	DEFENCE
	护腕 = 3,		//护腕	DEFENCE
	鞋 = 4,			//鞋	DEFENCE
	腰带 = 5,		//腰带	ADORN
	戒指 = 6,		//戒指	ADORN
	项链 = 7,		//项链	ADORN
	暗器 = 8,		//暗器	ADORN
	行囊 = 9,		//行囊
	箱格 = 10,		//箱格
	第二个戒指 = 11,//第二个戒指	ADORN
	护符 = 12,		//护符				ADORN
	第二个护符 = 13,//第二个护符	ADORN
	护腕SHOULDER = 14,		//护腕				ADORN
	护肩 = 15,		//护肩				DEFENCE
	时装 = 16,		//时装				DEFENCE
	预留1 = 17,		//预留1
	预留2 = 18,		//预留2
};