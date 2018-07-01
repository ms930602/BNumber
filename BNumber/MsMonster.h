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

class CMsEnvTree//��Χ������
{
public:
	CMsEnvTree();
	~CMsEnvTree();

protected:
	DWORD GetEnvTreeBase();//��ȡ��Χ������������ַ
	BOOL TreeObjectType(DWORD Object, char*  szObjectName);//������� 
};


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//������Ϣ�ṹ
struct TMsMonster
{

	DWORD dwTree;    //����������ڵ�
	DWORD dwObject;  //�������
	int   nMonsterId;//�������+34�ǹ����ID
	float fMonsterX;//�������+48�����x����
	float fMonsterY;//�������+50�����y����
	DWORD dwOffset;    //ƫ�ƹ�������ƣ�Ѫֵ���ȼ����ڵ�ƫ�ƻ�ַ
	float fMonsterHp;   //�������������ƫ��+8�����Ѫֵ�ٷֱ�
	int   nWhoHave;    //�������������ƫ��+24�����Ƿ���ӵ����
	PCHAR szName;     //�������������ƫ��+3C���������
	int   nLevel;    //�������������ƫ��+6C�ȼ�
	int   nType;//����ǹ�����������֣�-1�̹֣���ɫ�������һ��ֵ-��֣��������ǽ�ɫ��������ֵ-�׹�
	int   nNpcType;//�������npc������
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
	void MonsterTraverse(TMsTree* Tree, VMsMonster& vm_Monster, DWORD* pCount);//�������������
	void GetMonsterInfo(TMsTree* Tree, VMsMonster& vm_Monster);//ȡ�����������Ϣ
	int  GetMonsterType(DWORD MonsterOb, DWORD RoleOb);//���ֹ��� ���� NPC
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

//��Ʒ����
struct TMsItem
{
	PCHAR szName;//Name����
	ULONG uNumber;//number����
	ULONG uLevel; //level�ȼ�
	int   nEquipType;//װ����Ʒ����
	ULONG uType;//��Ʒ����
	ULONG uObject;//��Ʒ����,�����Ƕ���
	BYTE  byCurnaijiu;//��ǰ�;ö�
	BYTE  byMaxnaijiu;//����;ö�
	char  *szTypeName;//��Ʒ��������
	char  *szDataAttribute;//����˵��
	int   nIntdex;//��Ʒ���ڸ���

	TMsItem()
	{
		nEquipType = -1;
		szName = "";//Name����
		uNumber = 0;//number����
		uLevel = 0; //level�ȼ�
		uType = 0;//��Ʒ����
		uObject = 0;//��Ʒ����
		byCurnaijiu = 0;//��ǰ�;ö�
		byMaxnaijiu = 0;//����;ö�
		szTypeName = "";//��Ʒ��������
		szDataAttribute = "";//����˵��
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
	VMsGroundParcel GetGroundParcelData();//�������������
	void OpenGroundParcelById(DWORD ParcelId);//�򿪵������

public:
	VMsItem GetParcelItemData();//��ȡ�����������Ʒ
	void PickupSpecificItem(DWORD ItemObject);//ʰȡ�ض���Ʒ
private:
	//����
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
	int nHaveMonster;//�Ƿ�ӵ�й���Ľ���

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
