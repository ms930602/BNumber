#include "MsSkill.h"

CMsSkill::CMsSkill()
{
}

CMsSkill::~CMsSkill()
{
}

VMsSkill CMsSkill::GetSkillData()
{
	return VMsSkill();
}

int CMsSkill::HaveMasterySkill(UINT Tree)
{
	return 0;
}

int CMsSkill::GetSkillTime(UINT SkillTimeId)
{
	return 0;
}

void CMsSkill::UseSkillCall(int MonsterId, int SkillId)
{
}

void CMsSkill::UseSkillCallByPoint(int SkillId, float fx, float fy)
{
}

void CMsSkill::SkillTraverse(TMsTree * pTree, VMsSkill & vm_Skill, DWORD * pCount)
{
}

void CMsSkill::GetSkillInfo(TMsTree * pTree, VMsSkill & vm_Skill)
{
}
