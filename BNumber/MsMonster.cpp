#include "MsMonster.h"
#include "MsRole.h"
#include "MsBase.h"

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

CMsEnvTree::CMsEnvTree()
{
}

CMsEnvTree::~CMsEnvTree()
{
}

DWORD CMsEnvTree::GetEnvTreeBase()
{
	return 0;
}

BOOL CMsEnvTree::TreeObjectType(DWORD Object, char * szObjectName)
{
	return 0;
}
