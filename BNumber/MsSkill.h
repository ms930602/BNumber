#pragma once
#include "MsIndex.h"

using namespace std;

//������Ϣ�ṹ
struct  TMsSkill
{
	unsigned  unTree;//�������ڵ㣺��ǰ���ܶ�Ӧ�Ķ������ڵ�ָ��
	unsigned  unObject;//���ܶ��󣺵�ǰ���ܶ�Ӧ�ļ��ܶ���

	int nSkillId;// +0���ܱ��
	int	nMenPai;//  +8���ɱ��
	char* szName;//	+C��������
	int nXinFaLevel;// +14�ķ��ȼ�Ҫ��
	int nSkillType; // +3c 0�������� 1�������� 2ֱ��ʹ�ü��� 
	int nCoolTimeID;// +40 ��ȴʱ��ID
	int nSubType; // +98 ���������� 0����ǿ����  4����Χ  5���幥��������ǿ���� 7���δ���
	float fMin;	//+A0 �ǹ�����������
	float fMax;	//+A4 �ǹ�����������
	int	nStandFlag;	//+A8 ����Ǽ��ܵ�������ǣ�-1����������Ŀ�꣬0�����ԣ�1�Ǽ�����ǿĿ��
	int	nfriend;//+AC:  0: Ŀ���ʹ����Ӧ�����Ѻù�ϵ 1:Ŀ���ʹ����Ӧ���ǵжԹ�ϵ
	int	nAutoShot;//+BC 1:�Զ������ͷż���
	float fRadius; //+D0 Ⱥ���İ뾶
	float fAngle; //+D4 Ⱥ���ķ�Χ 360�ܱ�
	int nTargetType; //+DC 0: Ŀ���������� 1:Ŀ������ǳ��� 2:Ŀ������ǹ���
	char* szDescription; //+150 ����������Ϣ
	int	nPassiveFlag;	// +154 0:��������,1:��������;

	TMsSkill()
	{
		unTree = 0;
		unObject = 0;
		nSkillId = 0;
		nMenPai = 0;
		szName = "";
		nXinFaLevel = 0;
		nSkillType = 0;
		nCoolTimeID = 0;
		nSubType = 0;
		fMin = 0;
		fMax = 0;
		nStandFlag = 0;
		nfriend = 0;
		nAutoShot = 0;
		fRadius = 0;
		fAngle = 0;
		nTargetType = 0;
		szDescription = "";
		nPassiveFlag = 0;
	};
};

typedef 	vector<TMsSkill> VMsSkill;

class CMsSkill//����������
{
public:
	CMsSkill();
	~CMsSkill();
public:
	VMsSkill GetSkillData();//ȡ��ɫ������Ϣ
	int  HaveMasterySkill(UINT Tree);//�Ѿ����յļ���
	int  GetSkillTime(UINT SkillTimeId);//��ȡ������ȴʱ��
	void UseSkillCall(int MonsterId, int SkillId);//ʹ�ü���CALL
	void UseSkillCallByPoint(int SkillId, float fx, float fy);//ͨ���������ĳһ���ͷż���
private:
	void SkillTraverse(TMsTree* pTree, VMsSkill& vm_Skill, DWORD* pCount);//���ܱ���
	void GetSkillInfo(TMsTree* pTree, VMsSkill& vm_Skill);//����������Ϣ
public:
	//VAsmSkill vm_Skill;//��������
};

//$ - 18 > 00000192
//$ - 14 > FFFFFFFF
//$ - 10 > FFFFFFFF
//$ - C >  FFFFFFFF
//$ - 8 >  432265C1
//$ - 4 >  42BCA08A
//$ == > > BF800000

