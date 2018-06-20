#include "MsEntity.h"

DWORD CMsEnvTree::GetEnvTreeBase()
{
	return 0;
}

BOOL CMsEnvTree::TreeObjectType(DWORD Object, char * szObjectName)
{
	return 0;
}

CMsMonster::CMsMonster()
{
}

CMsMonster::~CMsMonster()
{
}

VMsMonster CMsMonster::GetMonsterDatas()
{
	return VMsMonster();
}

int CMsMonster::OpenNPCDlg(int nId)
{
	return 0;
}

void CMsMonster::MonsterTraverse(TMsTree * Tree, VMsMonster & vm_Monster, DWORD * pCount)
{
}

void CMsMonster::GetMonsterInfo(TMsTree * Tree, VMsMonster & vm_Monster)
{
}

int CMsMonster::GetMonsterType(DWORD MonsterOb, DWORD RoleOb)
{
	return 0;
}

CMsGroundParcel::CMsGroundParcel()
{
}

CMsGroundParcel::~CMsGroundParcel()
{
}

VMsGroundParcel CMsGroundParcel::GetGrountParcelDatas()
{
	return VMsGroundParcel();
}

void CMsGroundParcel::openGroundParcelById(DWORD nId)
{
}

void CMsGroundParcel::getParcelItemData()
{
}

void CMsGroundParcel::getPickupSpecificItemData(DWORD ItemObject)
{
}

void CMsGroundParcel::GroundParcelTraverse(TMsTree * Tree, VMsGroundParcel & vm_Parcel, DWORD * pCount)
{
}

void CMsGroundParcel::GroundParcelInfo(TMsTree * Tree, VMsGroundParcel & vm_Parcel)
{
}

CMsPlayer::CMsPlayer()
{
}

CMsPlayer::~CMsPlayer()
{
}

VMsPlayer CMsPlayer::GetPlayerDatas()
{
	return VMsPlayer();
}

void CMsPlayer::ChoosePlayer(int nPlayerId)
{
}

void CMsPlayer::OpenPlayerBooth(int nPlayerId)
{
}

void CMsPlayer::PlayerTraverse(TMsTree * Tree, VMsPlayer & vm_Player, DWORD * pCount)
{
}

void CMsPlayer::PlayerInfo(TMsTree * Tree, VMsPlayer & vm_Player)
{
}

VMsCollect CAsmCollect::AsmGetCollectData()
{
	return VMsCollect();
}

void CAsmCollect::AsmCollectCall(int nID)
{
}

void CAsmCollect::AsmCollectTraverse(TMsTree * Tree, VMsCollect & vm_Collect, DWORD * pCount)
{
}

void CAsmCollect::AsmCollectInfo(TMsTree * Tree, VMsCollect & vm_Collect)
{
}
