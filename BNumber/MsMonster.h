#pragma once
#include <Windows.h>
#include <vector>
#include <string>

using namespace std;

#include "MsIndex.h"

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
struct TAsmMonster
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
	TAsmMonster()
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

typedef 	vector<TAsmMonster> VAsmMonster;

class CMsMonster :
	public CMsEnvTree
{
public:
	CMsMonster() {};
	~CMsMonster() {};
public:
	VAsmMonster GetMonsterData();
	int OpenNpcDlg(int nID);
private:
	void MonsterTraverse(TMsTree* Tree, VAsmMonster& vm_Monster, DWORD* pCount);//先序遍历二叉树
	void GetMonsterInfo(TMsTree* Tree, VAsmMonster& vm_Monster);//取怪物的属性信息
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
