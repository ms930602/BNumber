#include "MsRole.h"
#include "MsMonster.h"

#define  ROLEOFFSET(data)\
data = *(PULONG)Const_Role_Base;\
data = *(PULONG)(data + 0x74);\
data = *(PULONG)(data + 0x1EC);\
data = *(PULONG)(data + 0x4);\


#define  ROLEOBJECT(data)\
data = *(PULONG)Const_Role_Base;\
data = *(PULONG)(data + 0x74);\

TMsHPMP CMsRole::GetHPMP()
{
	return TMsHPMP();
}

TMsRolePos CMsRole::GetPos()
{
	return TMsRolePos();
}

TMsRoleInfo CMsRole::GetRoleInfo()
{
	TMsRoleInfo tAsmRoleInfo;

	try
	{
		ULONG data = 0;
		ROLEOBJECT(data)
			tAsmRoleInfo.nRoleID = *(int*)(data + 0x34);//角色ID
		tAsmRoleInfo.nState = *(BYTE*)(data + 0x1f4);//角色状态
													 //------------------------------------------
		data = *(PULONG)(data + 0x1EC);
		data = *(PULONG)(data + 0x4);
		//------------------------------------------
		tAsmRoleInfo.szName = PCHAR(data + 0x3c);
		tAsmRoleInfo.nLevel = *(int*)(data + 0x6c);
		tAsmRoleInfo.nMenpai = *(BYTE*)(data + 0xF4);
		tAsmRoleInfo.nJiaoZI = *(int*)(data + 0x2670);
		tAsmRoleInfo.nMoney = *(int*)(data + 0x2744);
		tAsmRoleInfo.nYuanBao = *(int*)(data + 0x28a8);
		tAsmRoleInfo.nBindYuanBao = *(int*)(data + 0x28ac);
		tAsmRoleInfo.nFanQuan = *(int*)(data + 0x28b0);
		tAsmRoleInfo.nZengDian = *(int*)(data + 0x28b4);
		tAsmRoleInfo.nHongLI = *(int*)(data + 0x28B8);
		tAsmRoleInfo.nPetID = *(int *)(data + 0x2778);
		tAsmRoleInfo.nTeamFollow = *(int *)(data + 0x918);
		tAsmRoleInfo.nHuoLi = *(int *)(data + 0x2750);//活力 2748
		tAsmRoleInfo.nJingLi = *(int *)(data + 0x2758);//精力 2750
		tAsmRoleInfo.nHuoYue = *(int *)(data + 0x2A14);//活跃 29F0
		tAsmRoleInfo.nShanE = *(int *)(data + 0x2764);//善恶 2760
		tAsmRoleInfo.nMenGong = *(int *)(data + 0x30);//门贡 30
		tAsmRoleInfo.nShaGuaiShu = *(int *)(data + 0x29Ec);//杀怪数 29E8
		tAsmRoleInfo.nNuQi = *(int *)(data + 0x70);//怒气 70
		tAsmRoleInfo.nBangGong = *(int *)(data + 0x2880);//帮贡 287c
		tAsmRoleInfo.bool_ret = TRUE;
	}
	catch (...)
	{
		OutputDebugString("[WG[DLL] 获取角色信息错误");
	}

	return tAsmRoleInfo;
}

TMsRoleExp CMsRole::GetRoleExp()
{
	return TMsRoleExp();
}

ULONG CMsRole::getobject()
{
	return 0;
}

DWORD CMsRole::pass_map()
{
	return 0;
}

int CMsRole::GetMonsterTypeFlag()
{
	return 0;
}

void CMsRole::RunToTargetCall(float fx, float fy)
{
}

void CMsRole::RunToTargetExCall(int nTgtMapId, int nCurMapId, float fx, float fy)
{
}
