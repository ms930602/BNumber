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
	/////////////////////////////NPC�Ի���صĺ�����װ//////////////
	/************************************************************************/
	int LUA_OpenNpcDlgByID(LuaState* pState);//��NPC�Ի��򣬲�����npcID

	int LUA_SetAutoRunTargetNPCName(LuaState* pState);//��NPC�Ի��򣬲�����npc����

	int LUA_QuestFrameOptionClicked(LuaState* pState);//����Ի�ѡ������ǶԻ�ѡ���ַ���

	int LUA_QuestFrameMissionContinue(LuaState* pState);//����

	int LUA_MissionContinue_Clicked(LuaState* pState);//���

	int LUA_MissionQuestAccept_Clicked(LuaState* pState);//���

	int LUA_Quest_OnHidden(LuaState* pState);//�ر�

	/************************************************************************/
	/////////////////////////////Ѱ·��صĺ�����װ//////////////
	/************************************************************************/
	int  LUA_GetSceneId(LuaState* pState);//������������ɱ��

	int  LUA_FuBenMovTo(LuaState* pState);//�����ƶ���Ŀ��

	int  LUA_AutoRunToTarget(LuaState* pState);//�ƶ���Ŀ��

	int  LUA_MoveToNPC(LuaState* pState);//������������ɱ��

	int  LUA_MoveTo(LuaState* pState);//�ƶ�����

	int  LUA_Dismount(LuaState* pState);//����������

	/************************************************************************/
	/////////////////////////////�ɼ�����Ʒ��صĺ�����װ//////////////
	/************************************************************************/
	int LUA_GetZHongDI_UI(LuaState* pState);//��ȡ��ֲui���� 

	int LUA_GetZuoWuNum(LuaState* pState);//��ȡ�յ��ϻ��м���δ�ջ������

	int LUA_GetScarecrowInfo(LuaState* pState);//��ȡ�յأ������˰�

	int LUA_GetCanQiangeTudi(LuaState* pState);//��ȡ���������������

	int LUA_GetCollectInfo(LuaState* pState);//��ȡ�ɼ���Ʒ��Ϣ

	int LUA_Collect(LuaState* pState);//�ɼ���ҩ��ʯ��Ʒ

	int LUA_UserCollectSceneName(LuaState* pState);//�ɼ�����������

	int LUA_UserBackCity(LuaState* pState);//�û��س�

	int LUA_Player_UseSkill_Collect(LuaState* pState);//�ɼ�������Ʒ

	int LUA_CollectByName(LuaState* pState);//�ɼ���Ʒ

	int LUA_GetTaskCollectByName(LuaState* pState);//��ȡ�ɼ���Ʒ

	int LUA_TaskCollect(LuaState* pState);//�ɼ���Ʒ

	int LUA_PickUpItem(LuaState* pState);//ʰȡ��Ʒ

	int LUA_UseItem(LuaState* pState);//ʹ����Ʒ

	int LUA_UseZhuangBei(LuaState* pState);//ʹ������������Ʒ

	int LUA_UserBag_CountItemByName(LuaState* pState);//������Ʒ

	int LUA_ShopBuy(LuaState* pState);//������Ʒ

	//int LUA_FreshManMission_JLYH_Frame(LuaState* pState);//����װ��

	//int LUA_FreshmanWatch_Time_Text(LuaState* pState);//��ȡ��Ʒ

	/************************************************************************/
	/////////////////////////////���������Χ������صĺ�����װ///////
	/************************************************************************/

	int LUA_FindCharacterByName(LuaState* pState);//���ҹ���

	int LUA_GetAnyMonster(LuaState* pState);//���ҹ���

	int LUA_KillAnyMonster(LuaState* pState);//ɱ����,����ָ������

	int LUA_KillMonsterByName(LuaState* pState);//����ɱ����

	int LUA_Go_Fight(LuaState* pState);//�����ٻ�����

	int LUA_FindPetByName(LuaState* pState);//���ҳ���������

	int LUA_PetTrap(LuaState* pState);//ץ������

	/************************************************************************/
	/////////////////////////////������صĺ�����װ///////
	/************************************************************************/

	int LUA_GetData(LuaState* pState);//������

	int LUA_ZhiLiao(LuaState* pState);//����

	int LUA_GetPos(LuaState* pState);//����

	int LUA_PassMap(LuaState* pState);//��ͼ״̬

	int LUA_InMenPai(LuaState* pState);//Ҫ���������

	int LUA_GetActiveDataSceneID(LuaState* pState);//��ǰ���ڵ�ͼ

	int LUA_GetActiveSceneName(LuaState* pState);//��ǰ���ڵ�ͼ����

	int LUA_AskLevelUp(LuaState* pState);//��������ȼ�

	int LUA_RoleState(LuaState* pState);//����״̬

	int LUA_GetDistance(LuaState* pState);//��ȡ����

	int LUA_GetMountID(LuaState* pState);//��ȡ���ID

	/************************************************************************/
	//////////////////////////////������صĺ�����װ///////
	/************************************************************************/

	int LUA_EnableTeamFollow(LuaState* pState);//����ӳ�

	int LUA_InitiativeFollow(LuaState* pState);//��������

	int LUA_IsTeamLeader(LuaState* pState);//�ǲ��Ƕӳ�

	int LUA_IsTeamFollowState(LuaState* pState);//�ǲ��Ƕ������״̬��

	int LUA_FollowState(LuaState* pState);//����״̬

	int LUA_GetAllTeamMember(LuaState* pState);//��ȡ�ܱ߶��ѣ�������߷�����������һ��������ߵķ���0

	int FUN_GetTeamMemberCount(LuaState* pState);//��ȡ���ж�Ա����

	int LUA_FindTeamLeader(LuaState* pState);//���������

	/************************************************************************/
	//////////////////////////////����������صĺ�����װ///////
	/************************************************************************/

	int LUA_IsMissionCanCommit(LuaState* pState);//�Ƿ��Ѿ����������

	int LUA_GetPlayerMission(LuaState* pState);//�Ƿ��Ѿ���ȡ������

	int LUA_IsMissionOutline(LuaState* pState);//�Ƿ��ڿɽ������б�

	int LUA_GetPlayerMission_Variable(LuaState* pState);//�Ƿ�ɽ���

	int LUA_GetPlayerMissionInfo(LuaState* pState);//��ȡ��������

	int LUA_GetPlayerMissionWhere(LuaState* pState);//��ȡ�����Ҫ�󣬸�ѡ�����

	int LUA_GetNPCEventListInfo(LuaState* pState);//��ȡNPC�Ի�ѡ����ı�

	int LUA_DiscardedTask(LuaState* pState);//��������

	int LUA_GetDTInfo(LuaState* pState);//��ͼ����

	int LUA_GetDT_UIInfo(LuaState* pState);//��ͼ����������

	int LUA_SanCaiData(LuaState* pState);//����Ͽ��

	int LUA_MaZeiData(LuaState* pState);//��ȡ����

	int LUA_XiaoXiao(LuaState* pState);//��ȡ������С

	int LUA_Get_XParam_INT(LuaState* pState);//�����

	int LUA_IsWindowShow(LuaState* pState);//IsWindowShow

	int HaoYouZhuFu();//��ȡ����ף���۱��轱��

	int LUA_DoString(LuaState* pState);//lua�ַ�������

	int LUA_GetPlayerMission_DataCountByte(LuaState* pState);//�������

	int LUA_GetPlayerMission_UI(LuaState* pState);

	int LUA_PlaySound(LuaState* pState);

	int LUA_MessageBox(LuaState* pState);

	int LUA_GetDebugMessage(LuaState* pState);//��ȡ������Ϣ

	int LUA_Script(LuaState* pState);

	int BuyShop_DiTan();

	int SellShop_DiTan();
};