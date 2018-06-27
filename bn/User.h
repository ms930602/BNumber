#pragma once
#include "FileSystem.h"
#include "MsSkill.h"
#include "MsPet.h"
#include <vector>
#include <queue>
using namespace std;

struct TUserPos
{
	int nSceneId;//场景ID
	int nPosX;//x坐标
	int nPosY;//Y坐标
	int nPosR;//半径

	TUserPos()
	{
		nSceneId = 0;
		nPosX = 0;
		nPosY = 0;//Y坐标
		nPosR = 0;//半径
	}
};

struct TUserTime
{
	DWORD BeginTime;//这一点开始时间
	DWORD CurTime;//这一点当前时间
	DWORD ChangeTime;//多点轮换的时间间隔

	TUserTime()
	{
		BeginTime = 0;
		CurTime = 0;
		ChangeTime = 0;
	};
};

struct TUserChiYao//吃药
{
	int hp;
	int mp;
	int kou;
	int kuai;

	TUserChiYao()
	{
		hp = 0;
		mp = 0;
		kou = 0;
		kuai = 0;
	};
};

struct TUserBuyDrug//买药
{
	int hpdurg;
	int mpdurg;
	int koudurg;
	int happydurg;

	TUserBuyDrug()
	{
		hpdurg = 0;
		mpdurg = 0;
		koudurg = 0;
		happydurg = 0;
	};
};

struct TUserShiQu
{
	CString CstrItemName;
	CString CstrItemType;
	int nSHIQU;
	int nCHuSHou;

	TUserShiQu()
	{
		CstrItemName = "";
		CstrItemType = "";
		nSHIQU = 0;
		nCHuSHou = 0;
	};
};
struct TMA_ZEI_Scene
{
	_tstring strName;
	DWORD dwTime;
};

struct TBuyShopMoney
{
	CString CstrName;
	INT dwMoney;
};

struct TUSERItem
{
	CString CstrItemName;
	CString CstrItemType;
};

typedef vector<CString> VUserSkillName;
typedef vector<CString> VUserCollectName;
typedef vector<_tstring> VUserMonsterName;
typedef vector<_tstring> VUserSkillSetup;
typedef vector<CString> VUserEMeiJiaXueName;
typedef vector<TUserPos> VUserPos;
typedef vector<TUserShiQu> VUserShiQu;
typedef vector<TMA_ZEI_Scene> VShuMaSceneName;
typedef vector<TBuyShopMoney> VBuyShopMoney;

_tstring Os_stringOferase(_tstring& strSource, _tstring strErase);//移除指定字符或者字符串
VUserMonsterName UserSubMonsterName(_tstring& strSource, TCHAR strErase);
TUserChiYao UserGetHp();//获取吃药设置

typedef vector<int> VMeGroundParcelId;

class CUser
{
public:
	CUser();
	~CUser();
public:
	int nWorkType;
public:
	HWND hwnd_6_3 = nullptr;
	HWND hwnd = nullptr;
	_tstring strXIAO;//江湖宵小
public:
	void UserSystemInitial();//初始化用户设置界面
	int nUserRoleID;
	int nBuShouSkillID;//
	int nYinShenSkillID;//隐身技能
	TMsSkill tPuTongSkill;
public:
	VUserSkillName UserGetSkillName();//获取门派技能
	VUserSkillName UserGetPetSkillName();//获取宠物技能名称
	VUserMonsterName UserGetMonsterName();//用户获取怪物名单
	VUserPos UserGetPos();//用户获取挂机点总数
	VUserEMeiJiaXueName UserGetEMeiJiaXueName();//峨眉加血名单
	VUserScriptName UserGetScriptName();//获取脚本名字
	int UserWantInMenPai();//用户要加入的门派
	int UserCollectCaiYao();//用户采集采药
	int UserCollectCaiKuang();//用户采集采矿
	int UserCollectZhiDing();//用户采集勾选的指定物品
	VUserCollectName UserGetCollectName();//采集物品的名字
public:
	VMeGroundParcelId vm_GroundParcelId;
	TUserTime tLingQUTime;//领取新手奖励的时间
	TUserTime tSkillTime;//人物技能时间
	TUserTime tPetSkillTime;//宠物技能时间
	TUserTime tXuejiPetSkillTime;//宠物技能时间
	TUserTime tGongShengPetSkillTime;//宠物技能时间
									 //TUserTime tShiQuTime;//人物拾取状态乾坤壶检测时间
	TMsSkill tLXUSkill;
	VUserSkillName vtPKName;//被PK保存到这个容器里
public:
	VUserMonsterName vtAddItemName;//用户添加的物品名称
	vector<TUSERItem> vtAddItemType;//用户添加的物品类型
public:
	VUserSkillName   vtUserSetUpSceneName;
	VUserSkillName   UserGetMaZeiName(); //马贼名称
	VShuMaSceneName  vtShuMaSceneName;//刷马点地图名
public:
	/************************************************************************/
	/* 技能界面                                                                     */
	/************************************************************************/
	VUserSkillName vtSkillName;//获取门派技能
	VUserSkillName vtPetSkillName;//获取宠物技能名称
	VMsSkill vUserSkill;//获取用户设置技能
	VMsSkill UserGetSkill();//获取技能
	VMsPetSkillEX vPetSkillEX;
	//VAsmPetSkillEX UserGetPetSkill();//获取技能
	//VAsmPetSkill  vUserPetSkill;
	/************************************************************************/
	/* 挂机界面                                                                     */
	/************************************************************************/
	int nKillType_dlg2_radio;//用户打怪方式
	int nKillByName_dlg2_check;//用户打指定名称的怪物
	VUserMonsterName vtMonsterName;//用户获取怪物名单
	/************************************************************************/
	/* 常规选项                                                                     */
	/************************************************************************/
	int nCityBUJI_dlg2_check;//用户城内补给
	int nPetFight_dlg2_check;//用户宠物出战
	int nDaTi_dlg2_check;//用户自动答题
	int nHeCheng_dlg2_check;//用户自动合成
	int nSELL_dlg2_check;//用户允许采药
	int nCaiKuang_dlg2_check;//用户允许采药
	int nHuiDian_dlg2_check;//用户死亡回点
	int nTuLingZhu_dlg2_check;//用户使用土灵珠
	int nShouFei_dlg2_check;//用户收费通道
	int nShiQu_dlg2_check;//用户自动拾取
	int nShengJi_dlg2_check;//用户自动升级
	int nDaTiBaoJing_dlg2_check;//答题报警
	int nSiWangChuQiao_dlg2_check;//死亡出鞘
	/************************************************************************/
	/* 回城选项                                                                  */
	/************************************************************************/
	int nWuXueYao_dlg2_check;//用户无血药
	int nWuLanYao_dlg2_check;//用户无蓝药
	int nWuKouLiang_dlg2_check;//用户无口粮
	int nWuXunYang_dlg2_check;//用户无驯养
	int nDaoJuMan_dlg2_check;//用户道具满
	int nCaiLiaoMan_dlg2_check;//用户材料满
	int nBangZhanShi_dlg2_check;//用户帮战时
	int nHuLueShaGuaiShu_dlg2_check;//用户忽略杀怪数
	int nShaGuaiShu_dlg2_check;//用户杀怪数
	int nSiWangShu_dlg2_check;//用户死亡数
	int nShaGuaiShu_dlg2_edit;//用户获取杀怪数
	int nSiWangShu_dlg2_edit;//用户获取死亡数
	/************************************************************************/
	/* 挂机中心                                                                     */
	/************************************************************************/
	int nKillBanJing_dlg2_check;//用户挂机半径
	int nDuoDianLunHuan_dlg2_check;//用户多点轮换
	int nBanJingTime_dlg2_edit;//用户获取半径检测时间
	int nLunHuanTime_dlg2_edit;//用户获取轮换时间
	int nBanJing_dlg2_edit;//用户获取半径大小
	VUserPos vtKillPos;//用户获取挂机点总数
	/************************************************************************/
	/* 拾取界面                                                                     */
	/************************************************************************/
	VUserShiQu UserGetItem();
	int UserWantItem(CString CstrName);//指定物品是否要拾取
	VUserShiQu vtShiQu;
	int nAllShiQu;
	int nYUAN_SHIQU_ITEM;
	/************************************************************************/
	/* 保护界面                                                                   */
	/************************************************************************/
	int nHpVal;//hp下限
	int nMpVal;//mp下限
	int nPetHpVal;//宠物血值
	int nHappyVal;//快乐值
	int nHpDurgNum;//人物血药数量
	int nMpDurgNum;//人物蓝值数量
	int nPetHpDurgNum;//宠物HP药数量
	int nHappyDurgNum;//宠物驯养数量
	/************************************************************************/
	/* 队伍数据                                                                     */
	/************************************************************************/
	int nFollowLeader;//跟随队长
	int nAssistAttack;//协助攻击
	int nAcceptInvitation;//接受邀请
	int nfreeKillMonster;//自由打怪选怪
	int nLiKaiTeam;//离开队伍
	int nPassFollow;//跨图跟随
	int nMaxLevel;//最大等级
	int nMinLevel;//最小等级
	CString teamGuolv;
	//VUserMonsterName vtTeamGuolvName;//用户组队过滤名单
	/************************************************************************/
	/* 峨眉加血数据                                                                     */
	/************************************************************************/
	int nTeamerBlood;//峨嵋队友加血
	int nDesignatedPlayerBlood;//峨嵋非队友加血
	int nPotentialUp;//宠物自动加点分配潜能
	int nRepairEquipment;//持久低自动修理
	int nEMeiBlood;//峨嵋加血编辑框数值
	VUserEMeiJiaXueName vtEMeiJiaXueName;//峨眉加血表格
	/************************************************************************/
	/* 宠物数据                                                                     */
	/************************************************************************/
	CString CstrFightPetName;//获取战斗宠物名
	CString CstrXueJiPetName;//获取血祭宠物名
	CString CstrGongShengPetName;//获取共生宠物名
	TMsPet tFightPet;//血祭宠物
	TMsPet tXueJIPet;//血祭宠物
	TMsPet tGongShengPet;//共生宠物
	/************************************************************************/
	/* 调度界面                                                         */
	/************************************************************************/
	VUserScriptName vtScriptName;//获取脚本名字
	/************************************************************************/
	/* 任务界面                                                                     */
	/************************************************************************/
	int nTaskType;//用户任务类型
	int nWantInMenPai;//用户要加入的门派
	int nShiMenCount;//师门环数
	int nBaiHuaCount;//百花缘环数
	int nTianJieLou;//天劫楼
	/************************************************************************/
	/* 采集界面                                                                     */
	/************************************************************************/
	int nSHengHuoType;
	int nCollectCaiLiaoMan_dlg9_check;//用户采集材料满
	int nCollectDaoJuMan_dlg9_check;//用户采集道具满
	int nCollectWuHp_dlg9_check;//用户采集无补血
	int nCollectWuMp_dlg9_check;//用户采集无补气
	int nCollectCaiYao_dlg9_check;//用户采集采药
	int nCollectCaiKuang_dlg9_check;//用户采集采矿
	int nCollectAutoHeCheng_dlg9_check;//用户采集自动合成
	int nCollectCityBuJi_dlg9_check;//用户采集回程时补给
	int nCollectYinShen_dlg9_check;//用户采集时隐身
	int nCollectBuJiQingBao_dlg9_check;//用户采集补给时清包
	int nCollectZhiDing_dlg9_check;//用户采集勾选的指定物品
	CString CStrCollectSceneName;//采集场景的名字
	VUserCollectName vtCollectName;//获取采集物品名称
	/************************************************************************/
	/* 种植界面                                                                     */
	/************************************************************************/
	int nQiangzhong_dlg9_check;//允许抢种
	int nZhaoDi_dlg9_check;//自动找地
	int nCaiLiaoManEixt_dlg9_check;//用户材料满
	int nJingLiBuZu_dlg9_check;//用户精力不足
	int nCurPos_dlg9_check;//当前位置种植
	_tstring strZuoWu;//种植作物名字
	_tstring strTimeType;//种植时间类型
	_tstring strDiTu;//种植地图
	int nJingLI;//种植精力
	/************************************************************************/
	/* 打图界面                                                                     */
	/************************************************************************/
	int nCaiLiaoMan_dlg7_check;//用户开图材料满
	int nDaoJuMan_dlg7_check;//用户打图道具满
	int nWuHp_dlg7_check;//用户打图无补血
	int nWuMp_dlg7_check;//用户打图无补气
	int nWuPet_dlg7_check;//用户打图无补气
	int nAnser_dlg7_check;//用户自动答题
	int nCity_dlg7_check;//用户城内补给
	int nPetChuZhan_dlg7_check;//用户宠物出战
	int nTuLingZhu_dlg7_check;//用户土灵珠
	int nDATU_NUM;//打图的数目
	int nDATU_TYPE;//打图的类型
	int nDATU_ZHILIAO;//治疗
	/************************************************************************/
	/* 商人界面                                                               */
	/***********************************************************************/
	int nStallType;//商人界面的类型
	VBuyShopMoney UserGetShopMoney();//获取要买的地摊商品价格
	VBuyShopMoney vBuyShopMoney;//获取商品的价格
	CString CstrBuyShopScene;//扫摊的场景
	VBuyShopMoney UserGetShopMoney2();//获取要卖的地摊商品价格
	VBuyShopMoney vSellShopMoney;//获取商品的价格
	CString CstrSellShopScene;//卖摊的场景
};