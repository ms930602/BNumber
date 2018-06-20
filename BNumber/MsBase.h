#pragma once

#include "MsIndex.h"

#define     LROLE_BASE            0xA9DE58        //人物基址A
#define     LROLE_EXP             0x13FF8C0        //人物经验值
#define     LROLE_XY              0x14101E8        //人物坐标
#define     LBAG_BASE             0x13FF5E8        //背包基址
#define     LPET_OFFSET           0xD3B74        //宠物数组偏移
#define     LPET_DATA             0x53C4C0        //宠物ecx寄存器
#define     LITEM_DATA            0x4403A0        //物品初始化封包call
#define     LSEND_CALL            0x6B76A0        //宠物ecx寄存器
#define     LSEND_ECX             0x140E9F4        //发包call的ecx寄存器
#define     LMONSTER_TYPE         0x14101AC        //怪物类型
#define     LHAVE_SKILLS          0x509870        //已学会技能
#define     LSKILLS_TIME_OFFSET   0x9CF0        //技能冷却时间偏移
#define     LSKILLS_TREE_OFFSET   0x286C        //技能二叉偏移
#define     LSKILLS_CALL          0x450E70        //技能call
#define     LDIUQIWUPIN_DATA      0x541680        //丢弃物品
#define     LLUASTATE_BASE        0x1412030        //lua状态L指针
#define     LRUN_TOTARGETEX       0xFFFFFF        //跨图寻路ecx寄存器基址
#define     LPASS_MAP             0x1411D48        //过图状态
#define     LTEAM_DATA1           0x50DFF0        //组队封包初始化
#define     LTEAM_DATA2           0x8C83F4        //组队封包初始化
#define     LTEAM_DATA3           0x7FD240        //组队封包初始化
#define     LTEAM_DATA4           0x4DD810        //组队封包初始化
#define     LHAVE_TASKS           0x13FF5DC        //已接任务数组基址
#define     LHAVE_TASKS_TREE      0x13FFC28        //任务二叉树
#define     LTEAM_BASE            0x14101B0        //队伍
#define     LCHOOSE_PLAYER        0x14101AC        //选人call
#define     LYAOQING_TEAM         0x13FF5DC        //有人邀请你组队
#define     LPET_SKILL_CALL       0x4A2480        //宠物技能call
#define     LPET_SKILL_BASE       0x13FF5E8        //宠物技能基址
#define     LBUY_DRUG_CALL        0x5250D0        //买药品初始化call_1
#define     LEQUIPMENT_BASE       0x14101B4        //装备数组基址
#define     LNPC_BASE             0x5DE58B00        //NPC对话选项数组基址
#define     LPET_QIANNENG_DATA    0x5EBC50        ////宠物潜能封包初始化call
#define     LTASK_NAME_CALLL      0x500EC0        //任务名称call
#define     LCollectCall          0x450540        //采集采药矿石call
#define     LDiscardedTask        0x7CC120        //丢弃任务
#define     LDiscardedData        0x8D2768        //丢弃任务立即数
#define     LDIMIAN_WUPIN_SHUZU_OFFSET  0x9DF8        //地面物品数组偏移
#define     LHOOK_XITONG_LIAOTIAN_ADDR  0x7CCABA        //系统聊天基址
#define     LNPC_DLG_CALL         0x44EA70        //打开npc对话框call
#define     LPlayer_Booth_CALL    0x7CC120        //打开玩家摊位的初始化call
#define     LPlayer_Booth_Const   0x8DEE28        //打开玩家摊位的立即数
#define     LBank_Offset          0xA094        //银行偏移
#define     LItemColdTime         0x9CF0        //物品冷却时间偏移