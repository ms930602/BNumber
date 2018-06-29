#include "MsMonster.h"
#include "MsRole.h"
#include "MsBase.h"

/************************************************************************/
/*                                                                      */
/************************************************************************/
#define   LPETSKILLS_TIME_OFFSET 0x9d00
DWORD     Const_Role_Base = LROLE_BASE;     //�����ַ
DWORD     Const_Role_Exp = LROLE_EXP;       //���ﾭ��ֵ
DWORD     ROLE_XY = LROLE_XY;        //��������
DWORD     BAG_BASE = LBAG_BASE;      //������ַ
DWORD     PET_OFFSET = LPET_OFFSET;       //��������ƫ��
DWORD     PET_DATA = LPET_DATA;     //����ecx�Ĵ���
DWORD     ITEM_DATA = LITEM_DATA;      //��Ʒ��ʼ�����call
DWORD     SEND_CALL = LSEND_CALL;     //;����ecx�Ĵ���
DWORD     SEND_ECX = LSEND_ECX;       //����call��ecx�Ĵ���
DWORD     MONSTER_TYPE = LMONSTER_TYPE;       //��������
DWORD     HAVE_SKILLS = LHAVE_SKILLS;     //��ѧ�Ἴ��
DWORD     SKILLS_TIME_OFFSET = LSKILLS_TIME_OFFSET;       //������ȴʱ��ƫ��
DWORD     SKILLS_TREE_OFFSET = LSKILLS_TREE_OFFSET;       //���ܶ���ƫ��
DWORD     PETSKILLS_TIME_OFFSET = LPETSKILLS_TIME_OFFSET;
DWORD     SKILLS_CALL = LSKILLS_CALL;      //����call
DWORD     DIUQIWUPIN_DATA = LDIUQIWUPIN_DATA;       //������Ʒ
DWORD     LUASTATE_BASE = LLUASTATE_BASE;       //lua״̬Lָ��
DWORD     RUN_TOTARGETEX = LRUN_TOTARGETEX;       //��ͼѰ·ecx�Ĵ�����ַ
DWORD     PASS_MAP = LPASS_MAP;     //��ͼ״̬
DWORD     TEAM_DATA1 = LTEAM_DATA1;      //��ӷ����ʼ��
DWORD     TEAM_DATA2 = LTEAM_DATA2;      //��ӷ����ʼ��
DWORD     TEAM_DATA3 = LTEAM_DATA3;      //��ӷ����ʼ��
DWORD     TEAM_DATA4 = LTEAM_DATA4;      //��ӷ����ʼ��
DWORD     HAVE_TASKS = LHAVE_TASKS;     //�ѽ����������ַ
DWORD     HAVE_TASKS_TREE = LHAVE_TASKS_TREE;       //���������
DWORD     DiscardedTask = LDiscardedTask;      //��������
DWORD     DiscardedData = LDiscardedData;     //��������������
DWORD     TASK_NAME_CALLL = LTASK_NAME_CALLL;      //��������call
DWORD     TEAM_BASE = LTEAM_BASE;    //����
DWORD     CHOOSE_PLAYER = LCHOOSE_PLAYER;       //ѡ��call
DWORD     YAOQING_TEAM = LYAOQING_TEAM;     //�������������
DWORD     PET_SKILL_CALL = LPET_SKILL_CALL;     //���＼��call
DWORD     PET_SKILL_BASE = LPET_SKILL_BASE;      //���＼�ܻ�ַ
DWORD     BUY_DRUG_CALL = LBUY_DRUG_CALL;    //��ҩƷ��ʼ��call_1
DWORD     EQUIPMENT_BASE = LEQUIPMENT_BASE;      //װ�������ַ
DWORD     NPC_BASE = LNPC_BASE;   //NPC�Ի�ѡ�������ַ
DWORD     PET_QIANNENG_DATA = LPET_QIANNENG_DATA;     ////����Ǳ�ܷ����ʼ��call
DWORD     CollectCall = LCollectCall;   //�ɼ���ҩ��ʯcall
DWORD     DIMIAN_WUPIN_SHUZU_OFFSET = LDIMIAN_WUPIN_SHUZU_OFFSET;     //������Ʒ����ƫ��
DWORD     HOOK_XITONG_LIAOTIAN_ADDR = LHOOK_XITONG_LIAOTIAN_ADDR;       //ϵͳ�����ַ
DWORD     NPC_DLG_CALL = LNPC_DLG_CALL;   //��npc�Ի���call
DWORD     Player_Booth_CALL = LPlayer_Booth_CALL;      //�����̯λ�ĳ�ʼ��call
DWORD     Player_Booth_Const = LPlayer_Booth_Const;       //�����̯λ��������
DWORD     Bank_Offset = LBank_Offset;  //����ƫ��
DWORD     SKILLS_TIME = LBAG_BASE;
DWORD     SKILLS_BASE = LROLE_BASE;
DWORD     PET_BASE = LBAG_BASE;	//�����ַ�ͱ�����һ��
DWORD     MONSTER_BASE = LROLE_BASE;
DWORD     COLLECT_OREPLANT = LMONSTER_TYPE;
DWORD     RUN_TOTARGET = LMONSTER_TYPE;
DWORD     REPAIR_BASE = LMONSTER_TYPE;
DWORD     MAP_BASE = LRUN_TOTARGETEX; //��ͼ��ַ
DWORD     GROUND_BAG = LMONSTER_TYPE; //ʰȡ������ָ����Ʒ��ecx�Ļ�ַ
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

VAsmMonster CMsMonster::GetMonsterData()
{
	return VAsmMonster();
}

int CMsMonster::OpenNpcDlg(int nID)
{
	return 0;
}

void CMsMonster::MonsterTraverse(TMsTree * Tree, VAsmMonster & vm_Monster, DWORD * pCount)
{
}

void CMsMonster::GetMonsterInfo(TMsTree * Tree, VAsmMonster & vm_Monster)
{
}

int CMsMonster::GetMonsterType(DWORD MonsterOb, DWORD RoleOb)
{
	return 0;
}

VMsGroundParcel CMsGroundParcel::GetGroundParcelData()
{
	return VMsGroundParcel();
}

void CMsGroundParcel::OpenGroundParcelById(DWORD ParcelId)
{
}

VMsItem CMsGroundParcel::GetParcelItemData()
{
	return VMsItem();
}

void CMsGroundParcel::PickupSpecificItem(DWORD ItemObject)
{
}

void CMsGroundParcel::GroundParcelTraverse(TMsTree * Tree, VMsGroundParcel & vm_Parcel, DWORD * pCount)
{
}

void CMsGroundParcel::GroundParcelInfo(TMsTree * Tree, VMsGroundParcel & vm_Parcel)
{
}

VMsPlayer CMsPlayer::GetPlayerData()
{
	return VMsPlayer();
}

void CMsPlayer::ChoosePlayer(int PlayerId)
{
}

void CMsPlayer::OpenPlayerBooth(int PlayerId)
{
}

void CMsPlayer::PlayerTraverse(TMsTree * Tree, VMsPlayer & vm_Player, DWORD * pCount)
{
}

void CMsPlayer::PlayerInfo(TMsTree * Tree, VMsPlayer & vm_Player)
{
}

VMsCollect CMsCollect::GetCollectData()
{
	return VMsCollect();
}

void CMsCollect::CollectCall(int nID)
{
}

void CMsCollect::CollectTraverse(TMsTree * Tree, VMsCollect & vm_Collect, DWORD * pCount)
{
}

void CMsCollect::CollectInfo(TMsTree * Tree, VMsCollect & vm_Collect)
{
}
