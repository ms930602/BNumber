#pragma once
#include "FileSystem.h"
#include "MsSkill.h"
#include "MsPet.h"
#include <vector>
#include <queue>
using namespace std;

struct TUserPos
{
	int nSceneId;//����ID
	int nPosX;//x����
	int nPosY;//Y����
	int nPosR;//�뾶

	TUserPos()
	{
		nSceneId = 0;
		nPosX = 0;
		nPosY = 0;//Y����
		nPosR = 0;//�뾶
	}
};

struct TUserTime
{
	DWORD BeginTime;//��һ�㿪ʼʱ��
	DWORD CurTime;//��һ�㵱ǰʱ��
	DWORD ChangeTime;//����ֻ���ʱ����

	TUserTime()
	{
		BeginTime = 0;
		CurTime = 0;
		ChangeTime = 0;
	};
};

struct TUserChiYao//��ҩ
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

struct TUserBuyDrug//��ҩ
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

_tstring Os_stringOferase(_tstring& strSource, _tstring strErase);//�Ƴ�ָ���ַ������ַ���
VUserMonsterName UserSubMonsterName(_tstring& strSource, TCHAR strErase);
TUserChiYao UserGetHp();//��ȡ��ҩ����

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
	_tstring strXIAO;//������С
public:
	void UserSystemInitial();//��ʼ���û����ý���
	int nUserRoleID;
	int nBuShouSkillID;//
	int nYinShenSkillID;//������
	TMsSkill tPuTongSkill;
public:
	VUserSkillName UserGetSkillName();//��ȡ���ɼ���
	VUserSkillName UserGetPetSkillName();//��ȡ���＼������
	VUserMonsterName UserGetMonsterName();//�û���ȡ��������
	VUserPos UserGetPos();//�û���ȡ�һ�������
	VUserEMeiJiaXueName UserGetEMeiJiaXueName();//��ü��Ѫ����
	VUserScriptName UserGetScriptName();//��ȡ�ű�����
	int UserWantInMenPai();//�û�Ҫ���������
	int UserCollectCaiYao();//�û��ɼ���ҩ
	int UserCollectCaiKuang();//�û��ɼ��ɿ�
	int UserCollectZhiDing();//�û��ɼ���ѡ��ָ����Ʒ
	VUserCollectName UserGetCollectName();//�ɼ���Ʒ������
public:
	VMeGroundParcelId vm_GroundParcelId;
	TUserTime tLingQUTime;//��ȡ���ֽ�����ʱ��
	TUserTime tSkillTime;//���＼��ʱ��
	TUserTime tPetSkillTime;//���＼��ʱ��
	TUserTime tXuejiPetSkillTime;//���＼��ʱ��
	TUserTime tGongShengPetSkillTime;//���＼��ʱ��
									 //TUserTime tShiQuTime;//����ʰȡ״̬Ǭ�������ʱ��
	TMsSkill tLXUSkill;
	VUserSkillName vtPKName;//��PK���浽���������
public:
	VUserMonsterName vtAddItemName;//�û���ӵ���Ʒ����
	vector<TUSERItem> vtAddItemType;//�û���ӵ���Ʒ����
public:
	VUserSkillName   vtUserSetUpSceneName;
	VUserSkillName   UserGetMaZeiName(); //��������
	VShuMaSceneName  vtShuMaSceneName;//ˢ����ͼ��
public:
	/************************************************************************/
	/* ���ܽ���                                                                     */
	/************************************************************************/
	VUserSkillName vtSkillName;//��ȡ���ɼ���
	VUserSkillName vtPetSkillName;//��ȡ���＼������
	VMsSkill vUserSkill;//��ȡ�û����ü���
	VMsSkill UserGetSkill();//��ȡ����
	VMsPetSkillEX vPetSkillEX;
	//VAsmPetSkillEX UserGetPetSkill();//��ȡ����
	//VAsmPetSkill  vUserPetSkill;
	/************************************************************************/
	/* �һ�����                                                                     */
	/************************************************************************/
	int nKillType_dlg2_radio;//�û���ַ�ʽ
	int nKillByName_dlg2_check;//�û���ָ�����ƵĹ���
	VUserMonsterName vtMonsterName;//�û���ȡ��������
	/************************************************************************/
	/* ����ѡ��                                                                     */
	/************************************************************************/
	int nCityBUJI_dlg2_check;//�û����ڲ���
	int nPetFight_dlg2_check;//�û������ս
	int nDaTi_dlg2_check;//�û��Զ�����
	int nHeCheng_dlg2_check;//�û��Զ��ϳ�
	int nSELL_dlg2_check;//�û������ҩ
	int nCaiKuang_dlg2_check;//�û������ҩ
	int nHuiDian_dlg2_check;//�û������ص�
	int nTuLingZhu_dlg2_check;//�û�ʹ��������
	int nShouFei_dlg2_check;//�û��շ�ͨ��
	int nShiQu_dlg2_check;//�û��Զ�ʰȡ
	int nShengJi_dlg2_check;//�û��Զ�����
	int nDaTiBaoJing_dlg2_check;//���ⱨ��
	int nSiWangChuQiao_dlg2_check;//��������
	/************************************************************************/
	/* �س�ѡ��                                                                  */
	/************************************************************************/
	int nWuXueYao_dlg2_check;//�û���Ѫҩ
	int nWuLanYao_dlg2_check;//�û�����ҩ
	int nWuKouLiang_dlg2_check;//�û��޿���
	int nWuXunYang_dlg2_check;//�û���ѱ��
	int nDaoJuMan_dlg2_check;//�û�������
	int nCaiLiaoMan_dlg2_check;//�û�������
	int nBangZhanShi_dlg2_check;//�û���սʱ
	int nHuLueShaGuaiShu_dlg2_check;//�û�����ɱ����
	int nShaGuaiShu_dlg2_check;//�û�ɱ����
	int nSiWangShu_dlg2_check;//�û�������
	int nShaGuaiShu_dlg2_edit;//�û���ȡɱ����
	int nSiWangShu_dlg2_edit;//�û���ȡ������
	/************************************************************************/
	/* �һ�����                                                                     */
	/************************************************************************/
	int nKillBanJing_dlg2_check;//�û��һ��뾶
	int nDuoDianLunHuan_dlg2_check;//�û�����ֻ�
	int nBanJingTime_dlg2_edit;//�û���ȡ�뾶���ʱ��
	int nLunHuanTime_dlg2_edit;//�û���ȡ�ֻ�ʱ��
	int nBanJing_dlg2_edit;//�û���ȡ�뾶��С
	VUserPos vtKillPos;//�û���ȡ�һ�������
	/************************************************************************/
	/* ʰȡ����                                                                     */
	/************************************************************************/
	VUserShiQu UserGetItem();
	int UserWantItem(CString CstrName);//ָ����Ʒ�Ƿ�Ҫʰȡ
	VUserShiQu vtShiQu;
	int nAllShiQu;
	int nYUAN_SHIQU_ITEM;
	/************************************************************************/
	/* ��������                                                                   */
	/************************************************************************/
	int nHpVal;//hp����
	int nMpVal;//mp����
	int nPetHpVal;//����Ѫֵ
	int nHappyVal;//����ֵ
	int nHpDurgNum;//����Ѫҩ����
	int nMpDurgNum;//������ֵ����
	int nPetHpDurgNum;//����HPҩ����
	int nHappyDurgNum;//����ѱ������
	/************************************************************************/
	/* ��������                                                                     */
	/************************************************************************/
	int nFollowLeader;//����ӳ�
	int nAssistAttack;//Э������
	int nAcceptInvitation;//��������
	int nfreeKillMonster;//���ɴ��ѡ��
	int nLiKaiTeam;//�뿪����
	int nPassFollow;//��ͼ����
	int nMaxLevel;//���ȼ�
	int nMinLevel;//��С�ȼ�
	CString teamGuolv;
	//VUserMonsterName vtTeamGuolvName;//�û���ӹ�������
	/************************************************************************/
	/* ��ü��Ѫ����                                                                     */
	/************************************************************************/
	int nTeamerBlood;//���Ҷ��Ѽ�Ѫ
	int nDesignatedPlayerBlood;//���ҷǶ��Ѽ�Ѫ
	int nPotentialUp;//�����Զ��ӵ����Ǳ��
	int nRepairEquipment;//�־õ��Զ�����
	int nEMeiBlood;//���Ҽ�Ѫ�༭����ֵ
	VUserEMeiJiaXueName vtEMeiJiaXueName;//��ü��Ѫ���
	/************************************************************************/
	/* ��������                                                                     */
	/************************************************************************/
	CString CstrFightPetName;//��ȡս��������
	CString CstrXueJiPetName;//��ȡѪ��������
	CString CstrGongShengPetName;//��ȡ����������
	TMsPet tFightPet;//Ѫ������
	TMsPet tXueJIPet;//Ѫ������
	TMsPet tGongShengPet;//��������
	/************************************************************************/
	/* ���Ƚ���                                                         */
	/************************************************************************/
	VUserScriptName vtScriptName;//��ȡ�ű�����
	/************************************************************************/
	/* �������                                                                     */
	/************************************************************************/
	int nTaskType;//�û���������
	int nWantInMenPai;//�û�Ҫ���������
	int nShiMenCount;//ʦ�Ż���
	int nBaiHuaCount;//�ٻ�Ե����
	int nTianJieLou;//���¥
	/************************************************************************/
	/* �ɼ�����                                                                     */
	/************************************************************************/
	int nSHengHuoType;
	int nCollectCaiLiaoMan_dlg9_check;//�û��ɼ�������
	int nCollectDaoJuMan_dlg9_check;//�û��ɼ�������
	int nCollectWuHp_dlg9_check;//�û��ɼ��޲�Ѫ
	int nCollectWuMp_dlg9_check;//�û��ɼ��޲���
	int nCollectCaiYao_dlg9_check;//�û��ɼ���ҩ
	int nCollectCaiKuang_dlg9_check;//�û��ɼ��ɿ�
	int nCollectAutoHeCheng_dlg9_check;//�û��ɼ��Զ��ϳ�
	int nCollectCityBuJi_dlg9_check;//�û��ɼ��س�ʱ����
	int nCollectYinShen_dlg9_check;//�û��ɼ�ʱ����
	int nCollectBuJiQingBao_dlg9_check;//�û��ɼ�����ʱ���
	int nCollectZhiDing_dlg9_check;//�û��ɼ���ѡ��ָ����Ʒ
	CString CStrCollectSceneName;//�ɼ�����������
	VUserCollectName vtCollectName;//��ȡ�ɼ���Ʒ����
	/************************************************************************/
	/* ��ֲ����                                                                     */
	/************************************************************************/
	int nQiangzhong_dlg9_check;//��������
	int nZhaoDi_dlg9_check;//�Զ��ҵ�
	int nCaiLiaoManEixt_dlg9_check;//�û�������
	int nJingLiBuZu_dlg9_check;//�û���������
	int nCurPos_dlg9_check;//��ǰλ����ֲ
	_tstring strZuoWu;//��ֲ��������
	_tstring strTimeType;//��ֲʱ������
	_tstring strDiTu;//��ֲ��ͼ
	int nJingLI;//��ֲ����
	/************************************************************************/
	/* ��ͼ����                                                                     */
	/************************************************************************/
	int nCaiLiaoMan_dlg7_check;//�û���ͼ������
	int nDaoJuMan_dlg7_check;//�û���ͼ������
	int nWuHp_dlg7_check;//�û���ͼ�޲�Ѫ
	int nWuMp_dlg7_check;//�û���ͼ�޲���
	int nWuPet_dlg7_check;//�û���ͼ�޲���
	int nAnser_dlg7_check;//�û��Զ�����
	int nCity_dlg7_check;//�û����ڲ���
	int nPetChuZhan_dlg7_check;//�û������ս
	int nTuLingZhu_dlg7_check;//�û�������
	int nDATU_NUM;//��ͼ����Ŀ
	int nDATU_TYPE;//��ͼ������
	int nDATU_ZHILIAO;//����
	/************************************************************************/
	/* ���˽���                                                               */
	/***********************************************************************/
	int nStallType;//���˽��������
	VBuyShopMoney UserGetShopMoney();//��ȡҪ��ĵ�̯��Ʒ�۸�
	VBuyShopMoney vBuyShopMoney;//��ȡ��Ʒ�ļ۸�
	CString CstrBuyShopScene;//ɨ̯�ĳ���
	VBuyShopMoney UserGetShopMoney2();//��ȡҪ���ĵ�̯��Ʒ�۸�
	VBuyShopMoney vSellShopMoney;//��ȡ��Ʒ�ļ۸�
	CString CstrSellShopScene;//��̯�ĳ���
};