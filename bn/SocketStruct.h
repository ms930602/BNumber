#pragma once

#ifndef _STRURCT_SOCKET
#define _STRURCT_SOCKET

#include "../HPSocket/Src/HPSocket.h"
#include "../HPSocket/Common/Src/BufferPtr.h"
#include "../HPSocket/Common/Src/STLHelper.h"

#define SOCKET_GAME_启动游戏 1
#define SOCKET_GAME_单独登录 2
#define SOCKET_GAME_批量登录 3

#define SOCKET_LINK 10 //连接服务端消息
#define SOCKET_USERINFO 11 //客户端->服务端 发送角色信息
#define SOCEKT_LOGIN_INFO 16 //登录信息
#define SOCKET_LOGIN_ACTION 18 //登录游戏命令
#define SOCKET_GAME_INFO	19 //游戏信息
#define SOCKET_GAME_SCRIPT_INFO	20 //执行游戏脚本
#define SOCKET_GAME_PAUSE_SCRIPT 22 //暂定当前脚本
#define SOCKET_GAME_LOGIN_INI_OK 23 //游戏通知到了账号输入界面
#define SOCKET_GAME_START_SCRIPT 24 //继续当前脚本
#define SOCKET_GAME_VALIDATE 25 //验证码
#define SOCKET_GAME_VALIDATE_RESULT 26 //验证码结果
#define SOCKET_GAME_SECURITY 27 //密保
#define SOCKET_LINK_重连 28 //连接服务端消息
#define SOCKET_GAME_STOP_SCRIPT 29 //停止脚本


#define SOCKET_客户端接受主控_答题结果 49
#define SOCKET_客户端发送主控_答题信息 50

//----------------------------------------------------------------------
//定义通讯结构体
//----------------------------------------------------------------------
#pragma pack(push)//定义字节对齐方式为1字节
#pragma pack(1)

struct SocketBind
{
	CONNID dwConnID;//连接ID
	DWORD dwGmae;
	char Account[50];//游戏账号
};

struct TPkgHeader
{
	DWORD dwpacketID;
	int   body_len;
};

struct TPkgInfo
{
	bool   is_header;				//当前数据是否是包头
	int    length;					//当前需要数据长度
	DWORD  dwpacketID;				//数据ID

	TPkgInfo(bool header = true, int nID = 0, int len = sizeof(TPkgHeader)) : is_header(header), dwpacketID(nID), length(len) {}
	void Reset() { is_header = true, dwpacketID = 0, length = sizeof(TPkgHeader); }
	~TPkgInfo() {}
};

/*
*连接成功后，发送来的用户名和密码
*/
struct SocketLoginInfo
{
	char GameName[30];//账号
	char GameNameHouZhui[20];//账号后缀
	char GamePWD[50];//密码
	char GameServerName[15];//小区(服务器)名字
	char RoleName[20];//角色名
	char MiBao[98];//角色名
	int IsLoginIndex;//登录索引
	int isCreateRole;//无角色时是否创建
	int IsErJiMiBao;//是否有二级密保
	char _GameScript[100];//默认脚本名
};


/*
*游戏角色信息,(进入游戏成功后发送)
*/
struct SocketGameRoleInfo
{
	char RoleName[30];//角色名
	unsigned int RoleLevel;//角色等级
	unsigned int RoleMenPai;//角色门派
	unsigned int RoleTi;//体
	unsigned int RoleFa;//法
	char GameMap[20];//所在地图
	int PointX;//X坐标
	int PointY;//Y坐标
	unsigned int NoBindGold;//金钱
	unsigned int BindGold;//交子
	unsigned int YuanBap;//元宝
	unsigned int RoleStatus;//角色状态
};

/*
*游戏日志信息
*/
struct SocketGameInfo
{
	char _Message[150];//信息
};

/*
*执行脚本结构
*/
struct SocketGameScript
{
	char _GameScript[100];//脚本名称（不含路径）
};


/*
*验证码结构体绑定控件
*/
struct SocketValidate
{
	CONNID dwConnID;
	DWORD dwCtrl;//控件
	CONNID dwDllConnID;
	DWORD dwTimeCount;//超时时间
	DWORD dwStartTime;//开始记录时间
	char _Answer[40];//图片名称（不含路径）
	char _ImageName[MAX_PATH];//图片名称（不含路径）
	unsigned int _ValidateType;//验证类型(0,数字 1，选择)
};

/*
*验证结果
*/
struct SocketValidateResult
{
	CONNID dwDllConnID;
	unsigned int _ValidateType;//验证类型(0,数字 1，选择)
	char _Result[20];//验证结果
};

/*
*密保结构体
*/
struct SocketSecurity
{
	char _Security1[6];//1
	char _Security2[6];//2
	char _Security3[6];//3
};

#pragma pack(pop)

#endif