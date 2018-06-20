#pragma once
#include "MsIndex.h"

using namespace std;

//����
//+8��� id   ����ͬһ������ʱ���ֵ�� - 1
//+ c�ǳ���id
//+ 18���������
//+ 38������
//+ 40�ȼ�
//+ 50���Ѫֵ
//+ 54���Ѫ
//+ 58����ֵ
//+ 5c���������

struct TMsTeam
{
	int nPlayerId = -1;//���id
	short nSceneId = -1; //����
	char* Name = "";//�������
	int nMenPai = -1;//����
	int nLevel = 0;//�ȼ�
	float fPlayerX = 0;
	float fPlayerY = 0;
	int nCurHp = 0;//��ǰѪ
	int nMaxHp = 0;//���Ѫ
	int nCurMp = 0;//��ǰ����ֵ
	int nMaxMp = 0;//�������ֵ
};

typedef vector<TMsTeam> VMsTeam;//��������


class CMsTeam
{
public:
	CMsTeam();
	~CMsTeam();
public:

	VMsTeam GetTeamData();
	int  FollowState(); //����״̬�������5���Ǹ���
	BOOL InvitationLetter();//���뺯
							   //Dd[[[[0x9FEF28] + 0x74] + 0x1EC] + 0x4] + 0x908   //�Ƿ��Ƕӳ�
	bool IsTeamLeader(); //�Ƿ�ӳ�
							//Dd[[[[0x9FEF28] + 0x74] + 0x1EC] + 0x4] + 0x904   //�Ƿ��ж���
	BOOL IsHaveTeam();//�Ƿ��ж���
};
