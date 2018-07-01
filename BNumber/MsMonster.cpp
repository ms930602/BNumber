#include "MsMonster.h"

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

VMsMonster CMsMonster::GetMonsterData()
{
	return VMsMonster();
}

int CMsMonster::OpenNpcDlg(int nID)
{
	return 0;
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
