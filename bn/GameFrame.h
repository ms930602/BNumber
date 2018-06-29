#pragma once
#include "Controls.h"

class CGameFrame
{
public:
	CGameFrame();
	~CGameFrame();

public:
	BOOL IsShowFrame(CString Cstr);//界面是否还在显示，没有成功关闭
	BOOL IsSuccessFulSwitch(CString Cstr);//是否成功切换到另一个界面
public:
	BOOL IsLootPacket();//地面物品的界面是否还在显示
	BOOL IsSwitchToPacketFrame();//是否切换到了地面包裹ui数组
	BOOL IsShop_Frame();//商店窗口
	BOOL IsQuest_Frame();//对话窗口
	BOOL IsQuestLog_Frame();//任务列表窗口
	BOOL IsMessageBox_Self_Frame();//立即装备消息框窗口
	BOOL IsFreshManMission_JLYH_Frame();//立即装备消息框窗口
	BOOL IsAntiRobot_Frame();//防外挂答题
	BOOL IsPlayerGuide_Frame();
	BOOL UpdateInfo_Frame();
};
