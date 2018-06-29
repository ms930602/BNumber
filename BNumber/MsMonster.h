#pragma once
#include <Windows.h>
#include <vector>
#include <string>

using namespace std;

#include "MsIndex.h"

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
