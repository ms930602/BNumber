#pragma once
#include "MsIndex.h"

using namespace std;

struct TMsPetSkill //宠物技能
{
	unsigned unObject;//技能对象
	int nPetIndex;//归属第几个宠物
	int nLevel;
	int nSkillId;
	int nCoolTimeID;//冷却时间ID
	char* szName;
	int nSkillType;//+64   0是手动，1是自动
	int nSkillType1;//+80  1是手动，0是自动
	int	nStandFlag;	//+A8 这个是技能的立场标记，-1代表技能消弱目标，0是中性，1是技能增强目标

	TMsPetSkill()
	{
		unObject = 0;
		nPetIndex = -1;
		nSkillType = -1;
		nSkillId = -1;
		szName = "";
		nLevel = -1;
		nCoolTimeID = -1;
	}
};

typedef vector<TMsPetSkill> VMsPetSkill;

struct	TMsPetPetSkillEX
{
	int    nPetId;//+C ID
	PCHAR  szName;//+3C珍兽名字
	VMsPetSkill vm_PetSkill;// +120指向技能列表的指针,这里用容器存储技能数组

	TMsPetPetSkillEX()
	{
		szName = "";
		nPetId = 0;
	};
};

typedef vector<TMsPetPetSkillEX> VMsPetSkillEX;

struct	TMsPet
{
	DWORD  dwObject;
	int    nPetId;//+C ID
	PCHAR  szName;//+3C珍兽名字
	int    nPetType;//+34宠物类型 6是肉食闪电貂  a是草食花仙子 呆呆牛宝宝
	int    nLevel;//+24等级	
	int    nMaxHP;//+48最大血
	int    nCurHP;//+4C当前血
	int    nKuaiLe;//+58快乐
	int    nAttackType;//+8c 类型  b外功    c内功     a或d是均衡性或者无类型
	int    nPotential;//+108宠物剩余点
    //VAsmPetSkill vm_PetSkill;// +120指向技能列表的指针,这里用容器存储技能数组

	TMsPet()
	{
		szName = "";
		nLevel = 0;
		nKuaiLe = 0;
		nAttackType = 0;
		nMaxHP = 0;
		nCurHP = 0;
		dwObject = 0;
		nPetId = 0;
		nPotential = 0;
		nPetType = 0;
	};
};

typedef vector<TMsPet> VMsPet;

class CMsPet
{
public:
	CMsPet() {};
	~CMsPet() {};
public:

	VMsPet GetPetData();
	VMsPetSkillEX GetPetSkill();
	void PetFight(int PetObject);//宠物出战call
	void PetSkillCall(int nSkillId);
	void PetPotential(int PetObject, int nLiLiang, int nTiLi, int nDingLi, int nLingQi, int nShenFa);
};


