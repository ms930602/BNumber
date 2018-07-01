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
	��ʼ�һ� = 1,
	��ʼ���� = 2,
	��ʼ���� = 3,
	��ʼ�ɼ� = 4,
	��ʼˢ�� = 5,
	��ʼ��ͼ = 6,
	��ʼ���� = 7
};

class CFunction
{
public:
	CFunction();
	~CFunction();

public:
	/************************************************************************/
	/////////////////////////////������Ϣ��صĺ�����װ//////////////
	/************************************************************************/
	bool FUN_IsStateValue(int nState);//�ж������״ֵ̬
	void FUN_WaitTime(int nState);//ʹ�÷����������ܵ���������
	void FUN_LevelUp(); //��������ȼ�
	bool FUN_IsTeamFollowStateValue(int nState);//�ж�������Ӹ���״ֵ̬
public:
	/************************************************************************/
	/////////////////////////////Ѱ·��صĺ�����װ//////////////
	/************************************************************************/
	bool FUN_IsFuBenSceneId(int nSceneId);//��������ID
	void FUN_FuBenRunTo(float x, float y, int nID);//����Ѱ·
	int FUN_GetSceneID(const char* szSceneName);//ͨ�����ƻ�ȡ��ͼ����ID
	float FUN_GetDistance(float x2, float y2);//��ȡ��Ŀ��ľ���
	void  FUN_KaTuMov(float fOldX, float fOldY);//����ͼ
	void  FUN_OutHell();//�߳��ظ�
	void  FUN_OutJianYU();//�߳�����
	BOOL  FUN_RunToTarget(float x, float y, bool bRide = true); //����Ѱ·����
	BOOL  FUN_RunToTargetEx(float x, float y, int SceneId, bool bRide = true);//���ͼѰ·
	void  FUN_BackCityFunc();//Ѱ·�سǣ����߼��ܻس�
	void  FUN_RunTo(float x, float y, int nTime);//����״̬Ѱ·
public:
	int   FUN_ZhiLiao();//��Ѫ����
public:
	/************************************************************************/
	/////////////////////////////װ����صĺ���//////////////
	/************************************************************************/
	float FUN_GetEquipmentNaiJiuRatio(int nType, float fVal);//��ȡװ���;��Ƿ��������%
	int  FUN_GetEquipmentNaiJiu(int nNum = -1, int nType = -1);//��ȡװ���;��Ƿ��������
public:
	/************************************************************************/
	/////////////////////////////��Ʒ��صĺ�����װ//////////////
	/************************************************************************/
	int FUN_GetItemCountByName(CString CstrName, int nIndex = 1);//��ȡָ���ı�����Ʒ����
	int FUN_GetItemCountByTypeName(CString CstrType, CString CstrInfo, int nIndex, BOOL bFindInfo = TRUE);//��Ʒ���Ͳ���
	void FUN_BuyDrugByName(CString CstrName, int nNum);//��ҩͨ������
	void FUN_UseItem(CString CstrName, int nIndex);//ʹ����Ʒ
public:
	/************************************************************************/
	/////////////////////////////�ɼ���صĺ�����װ//////////////
	/************************************************************************/
	TMsCollect FUN_GetCollectByName(CString CstrName);//��ȡ�ɼ�����
	void FUN_CollectByName(CString CstrName);//�ɼ�����
	int FUN_Collect(int CollectID);//�ɼ���ҩ��ʯ
	bool FUN_IsCAIYAO(CString CstrCaoYao);
	bool FUN_IsCAIKUANG(CString CstrCAIKUANG);

public:
	/************************************************************************/
	/////////////////////////////��������ĺ�����װ//////////////
	/************************************************************************/
	int FUN_PickupGroundParcelItem(CString CstrName, int nVal = 0);
	BOOL FUN_FindItemById(TMsGroundParcel GroundParcel);//����������ڹ��˰����о��ƶ���������
	BOOL FUN_PickupUserSetupItem(CString CstrName, int GroundParcelId, int nVal = 0);
	void FUN_RemoveFilterId();
	bool FUN_FindGroundParcelId(INT ParcelId);//�ڰ����������в��ҹ���id�Ƿ���Ч
	BOOL FUN_UserWantItem(CString CstrName, int nVal = 0);

public:
	/************************************************************************/
	/////////////////////////////������صĺ�����װ//////////////
	/************************************************************************/
	TMsPet FUN_GetPetById(int nPetId);//�������ֻ�ȡ������Ϣ
	TMsPet FUN_GetPetByName(CString PetName);//�������ֻ�ȡ������Ϣ
	void FUN_UseFighPetSkillByName(VUserSkillName& v_Skill, int nPetID);//ս�����＼��
	void FUN_CallPetByName(CString PetName);//�ͷų�����
	void FUN_PotentialUp();//��������
	void FUN_UseFightPetSkill();//ս�����＼��
	void FUN_CallFightPet();//�ͷų�ս������
	void FUN_CallXueJiPet();
	void FUN_CallGongShengPet();
	void FUN_CallMaxLevelPet();//�ͷų����ȼ��ĳ���
	TMsPet FUN_GetMaxLevelPet();//��ȡ���ȼ�������Ϣ
public:
	/************************************************************************/
	/////////////////////////////��Ҷ�����صĺ�����װ//////////////
	/************************************************************************/
	TMsPlayer FUN_GetPlayerByID(int nPlayerId);//ͨ����ȡ�����Ϣ
	TMsPlayer FUN_GetPlayerByName(CString PlayerName, int nCMP_TYPE = 1);//ͨ�����ƻ�ȡ�����Ϣ
	TMsTeam  FUN_GetTeamLeader();//��ȡ�ӳ���Ϣ
	TMsTeam  FUN_GetAllTeamMember();//��ȡ���ж�Ա�ڲ������
	void FUN_RunToLeader(TMsPlayer leader);//�ƶ����ӳ����
	void FUN_AcceptTeam();//�Ƿ��Զ������������
	TMsMonster FUN_GetLeaderMonster(int nLeaderMonster);//��ȡ�ӳ���Ĺ���
	void FUN_AssistAttack();//Э�����ѹ���
	void FUN_UseEMeiBloodSkill(int nPlayerId);//ʹ�ö��Ҽ�Ѫ����
	void FUN_EMeiTeamerBlood();//�����Ѽ�Ѫ
	void FUN_EMeiPlayerBlood();//��ָ����Ҽ�Ѫ
	void FUN_ActionEMeiSkill(TMsSkill tAsmSkill, TMsPlayer tAsmPlayer);//��ʼ�ͷŶ��Ҽ�Ѫ����
	void FUN_TeamFollow(bool bFollow);//��Ӹ������
	void FUN_GameSetupTeamFollow();//������Ӹ������
	void FUN_FollowLeader();//����ӳ�
	void FUN_InitiativeFollowLeader();//�ֶ���������ӳ�
public:
	/************************************************************************/
	/////////////////////////////���ܴ����صĺ�����װ//////////////
	/************************************************************************/
	TMsSkill FUN_GetLXUSkillInfo();//��ȡ���ɹ�������
	TMsMonster FUN_GetNpcByName(CString MonsterName, int nType);//���ƻ�ȡnpc
	bool FUN_TimeChange(TUserTime* ptUserTime);//ʱ����
	TMsSkill FUN_GetSkillInfo(CString SkillName);//��ȡָ��������Ϣ
	void FUN_UseMovAttackSkill(TMsSkill tAsmSkill, TMsMonster tAsmMonster);//��ʼ�ͷŹ�������
	float FUN_MaximumRange(TMsSkill tAsmSkill);//���ܹ������
	bool FUN_MovToMonster(TMsMonster tAsmMonster, TMsSkill tAsmSkill);//�ߵ����������
	void FUN_ActionAttackSkill(TMsSkill tAsmSkill, TMsMonster tAsmMonster);//��ʼ�ͷż���
	void FUN_AttackSkillSort(TMsSkill tAsmSkill, TMsMonster tAsmMonster);//�������ܷ���
	void FUN_UseStrongSkill();//ʹ����ǿ����ļ���
	void FUN_UseAttackSkill(TMsSkill tAsmSkill/*CString SkillName*/, TMsMonster tAsmMonster);//ʹ�ù�������
	void FUN_UseSkillKillMonster(TMsMonster tAsmMonster, int nMonsterType = 0, int nKillType = 2);
	bool FUN_MinDistanceObject(float* fdistance, float fx, float fy);	//true�������
	TMsMonster FUN_GetMonsterByName(CString MonsterName, int nMonsterType, int nKillType);//���ƻ�ȡ����Ĺ���
	int FUN_GetFuJinMonsterNum();	//��ȡ����������������
	TMsMonster FUN_GetAnyMonster(int nMonsterType, int nKillType);//��ȡ������������
	bool FUN_IsMonsterDie(TMsMonster* ptAsmMonster);//falseΪ����
	BOOL FUN_KillAnyMonster(int nMonsterType, int nKillType = 2);//ɱ�����
	BOOL FUN_KillMonsterByName(VUserMonsterName vm_UserMonsterName, int nMonsterType, int nKillType = 2);//ɱָ����//0�չ�ɱ�֣� 1����ɱ�� �� 2����ɱ��

	/************************************************************************/
	/* ���������ֺ���                                                                     */
	/************************************************************************/
	VMsSkill  FUN_UserGetSkill();//��ȡ����
	BOOL FUN_MisKillAnyMonster(int nMonsterType, int nKillType);//ɱ�����
	BOOL FUN_MisKillMonsterByName(VUserMonsterName vm_UserMonsterName, int nMonsterType, int nKillType);//ɱָ����
	void FUN_MisUseSkillKillMonster(TMsMonster tAsmMonster, int nMonsterType, int nKillType);
};

//��ȡ�����������Ϣ����ʱ����־��Ϣ��������Ӧ�Ĵ���
#define ��ȡ������Ϣ�쳣��־(ARoleInfo,command)\
if (!ARoleInfo.bool_ret)\
{\
	dbgPrint("��ȡ������ϢInfoʧ��__FUNCTION__%s__FILE__%s__LINE__%d",__FUNCTION__,__FILE__,__LINE__);\
	command;\
}

//��ȡ�����������Ϣ����ʱ����־��Ϣ
#define ��ȡ���������쳣��־(APos,command)\
if (!APos.bool_ret)\
{\
	dbgPrint("��ȡ��������Posʧ��__FUNCTION__%s__FILE__%s__LINE__%d",__FUNCTION__,__FILE__,__LINE__);\
	command;\
}

#define ����ͼ��������ԭʼ����(dwBGTime,fOldX,fOldY,APos)  \
fOldX = APos.fx;\
fOldY = APos.fy;\
dwBGTime = GetTickCount();

#define ����ͼ��ʱ�������λ��(dwBGTime,fOldX, fOldY)  \
DWORD dwEDTime = GetTickCount();\
if (dwEDTime - dwBGTime > 5000)\
{\
	FUN_KaTuMov(fOldX, fOldY);\
	auto APos = pAsmRole->GetPos();\
	��ȡ���������쳣��־(APos, break)\
	����ͼ��������ԭʼ����(dwBGTime,fOldX,fOldY,APos) \
}

#define �糡��(pMsRole,command)\
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

//--���ݳ��ж����װ������.
enum EFunEquip
{
	���� = 0,		//����	WEAPON
	ñ�� = 1,		//ñ��	DEFENCE
	�·� = 2,		//�·�	DEFENCE
	���� = 3,		//����	DEFENCE
	Ь = 4,			//Ь	DEFENCE
	���� = 5,		//����	ADORN
	��ָ = 6,		//��ָ	ADORN
	���� = 7,		//����	ADORN
	���� = 8,		//����	ADORN
	���� = 9,		//����
	��� = 10,		//���
	�ڶ�����ָ = 11,//�ڶ�����ָ	ADORN
	���� = 12,		//����				ADORN
	�ڶ������� = 13,//�ڶ�������	ADORN
	����SHOULDER = 14,		//����				ADORN
	���� = 15,		//����				DEFENCE
	ʱװ = 16,		//ʱװ				DEFENCE
	Ԥ��1 = 17,		//Ԥ��1
	Ԥ��2 = 18,		//Ԥ��2
};