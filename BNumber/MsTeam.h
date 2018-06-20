#pragma once
#include "MsIndex.h"

using namespace std;

//队伍
//+8玩家 id   不在同一个场景时这个值是 - 1
//+ c是场景id
//+ 18是玩家名字
//+ 38是门派
//+ 40等级
//+ 50玩家血值
//+ 54最大血
//+ 58真气值
//+ 5c是最大真气

struct TMsTeam
{
	int nPlayerId = -1;//玩家id
	short nSceneId = -1; //场景
	char* Name = "";//玩家名字
	int nMenPai = -1;//门派
	int nLevel = 0;//等级
	float fPlayerX = 0;
	float fPlayerY = 0;
	int nCurHp = 0;//当前血
	int nMaxHp = 0;//最大血
	int nCurMp = 0;//当前真气值
	int nMaxMp = 0;//最大真气值
};

typedef vector<TMsTeam> VMsTeam;//队伍数组


class CMsTeam
{
public:
	CMsTeam();
	~CMsTeam();
public:

	VMsTeam GetTeamData();
	int  FollowState(); //跟随状态，如果是5就是跟随
	BOOL InvitationLetter();//邀请函
							   //Dd[[[[0x9FEF28] + 0x74] + 0x1EC] + 0x4] + 0x908   //是否是队长
	bool IsTeamLeader(); //是否队长
							//Dd[[[[0x9FEF28] + 0x74] + 0x1EC] + 0x4] + 0x904   //是否有队伍
	BOOL IsHaveTeam();//是否有队伍
};
