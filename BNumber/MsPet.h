#pragma once
#include "MsIndex.h"

using namespace std;

struct TMsPetSkill //���＼��
{
	unsigned unObject;//���ܶ���
	int nPetIndex;//�����ڼ�������
	int nLevel;
	int nSkillId;
	int nCoolTimeID;//��ȴʱ��ID
	char* szName;
	int nSkillType;//+64   0���ֶ���1���Զ�
	int nSkillType1;//+80  1���ֶ���0���Զ�
	int	nStandFlag;	//+A8 ����Ǽ��ܵ�������ǣ�-1����������Ŀ�꣬0�����ԣ�1�Ǽ�����ǿĿ��

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
	PCHAR  szName;//+3C��������
	VMsPetSkill vm_PetSkill;// +120ָ�����б��ָ��,�����������洢��������

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
	PCHAR  szName;//+3C��������
	int    nPetType;//+34�������� 6����ʳ������  a�ǲ�ʳ������ ����ţ����
	int    nLevel;//+24�ȼ�	
	int    nMaxHP;//+48���Ѫ
	int    nCurHP;//+4C��ǰѪ
	int    nKuaiLe;//+58����
	int    nAttackType;//+8c ����  b�⹦    c�ڹ�     a��d�Ǿ����Ի���������
	int    nPotential;//+108����ʣ���
    //VAsmPetSkill vm_PetSkill;// +120ָ�����б��ָ��,�����������洢��������

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
	void PetFight(int PetObject);//�����սcall
	void PetSkillCall(int nSkillId);
	void PetPotential(int PetObject, int nLiLiang, int nTiLi, int nDingLi, int nLingQi, int nShenFa);
};


