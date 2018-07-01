#pragma once
#include <Windows.h>
#include <string>
#include "MsRole.h"
#include "MsBase.h"
using namespace std;

#include "MsIndex.h"

/************************************************************************/
/*                                                                      */
/************************************************************************/
#define   LPETSKILLS_TIME_OFFSET 0x9d00
DWORD     Const_Role_Base = LROLE_BASE;     //人物基址
DWORD     Const_Role_Exp = LROLE_EXP;       //人物经验值
DWORD     ROLE_XY = LROLE_XY;        //人物坐标
DWORD     BAG_BASE = LBAG_BASE;      //背包基址
DWORD     PET_OFFSET = LPET_OFFSET;       //宠物数组偏移
DWORD     PET_DATA = LPET_DATA;     //宠物ecx寄存器
DWORD     ITEM_DATA = LITEM_DATA;      //物品初始化封包call
DWORD     SEND_CALL = LSEND_CALL;     //;宠物ecx寄存器
DWORD     SEND_ECX = LSEND_ECX;       //发包call的ecx寄存器
DWORD     MONSTER_TYPE = LMONSTER_TYPE;       //怪物类型
DWORD     HAVE_SKILLS = LHAVE_SKILLS;     //已学会技能
DWORD     SKILLS_TIME_OFFSET = LSKILLS_TIME_OFFSET;       //技能冷却时间偏移
DWORD     SKILLS_TREE_OFFSET = LSKILLS_TREE_OFFSET;       //技能二叉偏移
DWORD     PETSKILLS_TIME_OFFSET = LPETSKILLS_TIME_OFFSET;
DWORD     SKILLS_CALL = LSKILLS_CALL;      //技能call
DWORD     DIUQIWUPIN_DATA = LDIUQIWUPIN_DATA;       //丢弃物品
DWORD     LUASTATE_BASE = LLUASTATE_BASE;       //lua状态L指针
DWORD     RUN_TOTARGETEX = LRUN_TOTARGETEX;       //跨图寻路ecx寄存器基址
DWORD     PASS_MAP = LPASS_MAP;     //过图状态
DWORD     TEAM_DATA1 = LTEAM_DATA1;      //组队封包初始化
DWORD     TEAM_DATA2 = LTEAM_DATA2;      //组队封包初始化
DWORD     TEAM_DATA3 = LTEAM_DATA3;      //组队封包初始化
DWORD     TEAM_DATA4 = LTEAM_DATA4;      //组队封包初始化
DWORD     HAVE_TASKS = LHAVE_TASKS;     //已接任务数组基址
DWORD     HAVE_TASKS_TREE = LHAVE_TASKS_TREE;       //任务二叉树
DWORD     DiscardedTask = LDiscardedTask;      //丢弃任务
DWORD     DiscardedData = LDiscardedData;     //丢弃任务立即数
DWORD     TASK_NAME_CALLL = LTASK_NAME_CALLL;      //任务名称call
DWORD     TEAM_BASE = LTEAM_BASE;    //队伍
DWORD     CHOOSE_PLAYER = LCHOOSE_PLAYER;       //选人call
DWORD     YAOQING_TEAM = LYAOQING_TEAM;     //有人邀请你组队
DWORD     PET_SKILL_CALL = LPET_SKILL_CALL;     //宠物技能call
DWORD     PET_SKILL_BASE = LPET_SKILL_BASE;      //宠物技能基址
DWORD     BUY_DRUG_CALL = LBUY_DRUG_CALL;    //买药品初始化call_1
DWORD     EQUIPMENT_BASE = LEQUIPMENT_BASE;      //装备数组基址
DWORD     NPC_BASE = LNPC_BASE;   //NPC对话选项数组基址
DWORD     PET_QIANNENG_DATA = LPET_QIANNENG_DATA;     ////宠物潜能封包初始化call
DWORD     CollectCall = LCollectCall;   //采集采药矿石call
DWORD     DIMIAN_WUPIN_SHUZU_OFFSET = LDIMIAN_WUPIN_SHUZU_OFFSET;     //地面物品数组偏移
DWORD     HOOK_XITONG_LIAOTIAN_ADDR = LHOOK_XITONG_LIAOTIAN_ADDR;       //系统聊天基址
DWORD     NPC_DLG_CALL = LNPC_DLG_CALL;   //打开npc对话框call
DWORD     Player_Booth_CALL = LPlayer_Booth_CALL;      //打开玩家摊位的初始化call
DWORD     Player_Booth_Const = LPlayer_Booth_Const;       //打开玩家摊位的立即数
DWORD     Bank_Offset = LBank_Offset;  //银行偏移
DWORD     SKILLS_TIME = LBAG_BASE;
DWORD     SKILLS_BASE = LROLE_BASE;
DWORD     PET_BASE = LBAG_BASE;	//宠物基址和背包是一个
DWORD     MONSTER_BASE = LROLE_BASE;
DWORD     COLLECT_OREPLANT = LMONSTER_TYPE;
DWORD     RUN_TOTARGET = LMONSTER_TYPE;
DWORD     REPAIR_BASE = LMONSTER_TYPE;
DWORD     MAP_BASE = LRUN_TOTARGETEX; //地图基址
DWORD     GROUND_BAG = LMONSTER_TYPE; //拾取包裹中指定物品的ecx的基址
DWORD     ItemColdTime = LItemColdTime;
DWORD     BagOffset = 0x9dd0;
DWORD     ShopOffset = 0x9f60;
DWORD     PlayerBoothOffset = 0xBC54;
DWORD     MyBoothOffset = 0xBB4C;

class CMsEnvTree//周围二叉树
{
public:
	CMsEnvTree();
	~CMsEnvTree();

protected:
	DWORD GetEnvTreeBase();//获取周围环境二叉树基址
	BOOL TreeObjectType(DWORD Object, char*  szObjectName);//怪物对象 
};


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//怪物信息结构
struct TMsMonster
{

	DWORD dwTree;    //怪物二叉树节点
	DWORD dwObject;  //怪物对象
	int   nMonsterId;//怪物对象+34是怪物的ID
	float fMonsterX;//怪物对象+48怪物的x坐标
	float fMonsterY;//怪物对象+50怪物的y坐标
	DWORD dwOffset;    //偏移怪物的名称，血值，等级所在的偏移基址
	float fMonsterHp;   //怪物的属性属性偏移+8怪物的血值百分比
	int   nWhoHave;    //怪物的属性属性偏移+24怪物是否有拥有者
	PCHAR szName;     //怪物的属性属性偏移+3C怪物的名字
	int   nLevel;    //怪物的属性属性偏移+6C等级
	int   nType;//这个是怪物归属，区分，-1绿怪，角色对象里的一个值-红怪，不是我们角色对象的里的值-白怪
	int   nNpcType;//这个区分npc的类型
	TMsMonster()
	{
		dwTree = 0;
		nMonsterId = -1;
		nLevel = 0;
		dwObject = 0;
		fMonsterX = 0.0f;
		fMonsterY = 0.0f;
		fMonsterHp = 0.0f;
		szName = "";
		nWhoHave = 0;
		dwOffset = 0;
		nType = 0;
		nNpcType = -1;
	};
};

typedef 	vector<TMsMonster> VMsMonster;

class CMsMonster :
	public CMsEnvTree
{
public:
	CMsMonster() {};
	~CMsMonster() {};
public:
	VMsMonster GetMonsterData();
	int OpenNpcDlg(int nID);
private:
	void MonsterTraverse(TMsTree* Tree, VMsMonster& vm_Monster, DWORD* pCount);//先序遍历二叉树
	void GetMonsterInfo(TMsTree* Tree, VMsMonster& vm_Monster);//取怪物的属性信息
	int  GetMonsterType(DWORD MonsterOb, DWORD RoleOb);//区分怪物 宠物 NPC
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

//物品属性
struct TMsItem
{
	PCHAR szName;//Name名称
	ULONG uNumber;//number数量
	ULONG uLevel; //level等级
	int   nEquipType;//装备物品类型
	ULONG uType;//物品类型
	ULONG uObject;//物品类型,这里是对象
	BYTE  byCurnaijiu;//当前耐久度
	BYTE  byMaxnaijiu;//最大耐久度
	char  *szTypeName;//物品类型名称
	char  *szDataAttribute;//属性说明
	int   nIntdex;//物品所在格子

	TMsItem()
	{
		nEquipType = -1;
		szName = "";//Name名称
		uNumber = 0;//number数量
		uLevel = 0; //level等级
		uType = 0;//物品类型
		uObject = 0;//物品类型
		byCurnaijiu = 0;//当前耐久度
		byMaxnaijiu = 0;//最大耐久度
		szTypeName = "";//物品类型名称
		szDataAttribute = "";//属性说明
	};
};


typedef struct  TMsGroundParcel
{
	DWORD dwTree;
	DWORD dwObject;
	int   nParcelId;
	float fParcelX;
	float fParcelY;
	char* szOreName;

	TMsGroundParcel()
	{
		szOreName = "";
		dwTree = 0;
		dwObject = 0;
		nParcelId = -1;
		fParcelX = 0.0f;
		fParcelY = 0.0f;
	};
}TMsCollect;

typedef vector<TMsGroundParcel> VMsGroundParcel;
typedef vector<TMsItem> VMsItem;

class CMsGroundParcel :
	public CMsEnvTree
{
public:
	CMsGroundParcel() {};
	~CMsGroundParcel() {};

public:
	VMsGroundParcel GetGroundParcelData();//地面包裹二叉树
	void OpenGroundParcelById(DWORD ParcelId);//打开地面包裹

public:
	VMsItem GetParcelItemData();//获取地面包裹内物品
	void PickupSpecificItem(DWORD ItemObject);//拾取特定物品
private:
	//包裹
	void GroundParcelTraverse(TMsTree* Tree, VMsGroundParcel& vm_Parcel, DWORD* pCount);
	void GroundParcelInfo(TMsTree* Tree, VMsGroundParcel& vm_Parcel);
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
struct  TMsPlayer
{
	DWORD dwTree;
	DWORD dwObject;
	int nPlayerId;
	int nLevel;
	float fPlayerX;
	float fPlayerY;
	int nState;
	PCHAR szName;
	float fCurHp;
	int nHaveMonster;//是否拥有怪物的奖励

	TMsPlayer()
	{
		dwTree = 0;
		dwObject = 0;
		nPlayerId = -1;
		nLevel = 0;
		fPlayerX = 0.0f;
		fPlayerY = 0.0f;
		szName = "";
		fCurHp = 0;
		nHaveMonster = 0;
		nState = -1;
	};
};

typedef vector<TMsPlayer> VMsPlayer;

class CMsPlayer :
	public CMsEnvTree
{
public:
	CMsPlayer() {};
	~CMsPlayer() {};
public:

	VMsPlayer GetPlayerData();
	void ChoosePlayer(int PlayerId);
	void OpenPlayerBooth(int PlayerId);
private:
	void PlayerTraverse(TMsTree* Tree, VMsPlayer& vm_Player, DWORD* pCount);
	void PlayerInfo(TMsTree* Tree, VMsPlayer& vm_Player);
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

typedef vector<TMsCollect> VMsCollect;

class CMsCollect :
	public CMsEnvTree
{
public:
	CMsCollect() {};
	~CMsCollect() {};
public:
	VMsCollect GetCollectData();
	void CollectCall(int nID);
private:
	void CollectTraverse(TMsTree* Tree, VMsCollect& vm_Collect, DWORD* pCount);
	void CollectInfo(TMsTree* Tree, VMsCollect& vm_Collect);
};
