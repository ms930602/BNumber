#pragma once
#include "Controls.h"

class CGameFrame
{
public:
	CGameFrame();
	~CGameFrame();

public:
	BOOL IsShowFrame(CString Cstr);//�����Ƿ�����ʾ��û�гɹ��ر�
	BOOL IsSuccessFulSwitch(CString Cstr);//�Ƿ�ɹ��л�����һ������
public:
	BOOL IsLootPacket();//������Ʒ�Ľ����Ƿ�����ʾ
	BOOL IsSwitchToPacketFrame();//�Ƿ��л����˵������ui����
	BOOL IsShop_Frame();//�̵괰��
	BOOL IsQuest_Frame();//�Ի�����
	BOOL IsQuestLog_Frame();//�����б���
	BOOL IsMessageBox_Self_Frame();//����װ����Ϣ�򴰿�
	BOOL IsFreshManMission_JLYH_Frame();//����װ����Ϣ�򴰿�
	BOOL IsAntiRobot_Frame();//����Ҵ���
	BOOL IsPlayerGuide_Frame();
	BOOL UpdateInfo_Frame();
};
