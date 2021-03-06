#pragma once

#include "../HPSocket/Src/HPSocket.h"
#include "../HPSocket/Common/Src/BufferPtr.h"
#include "SocketStruct.h"
#include <vector>
#include <string>
#include <queue>

using namespace std;

class CServerCtrl:public CTcpPullServerListener
{
public:
	CServerCtrl();
	~CServerCtrl();
public:
	void start();
	void stop();
	void Disconnect();
private:
	virtual EnHandleResult OnPrepareListen(ITcpServer* pSender, SOCKET soListen);
	virtual EnHandleResult OnAccept(ITcpServer* pSender, CONNID dwConnID, SOCKET soClient);
	virtual EnHandleResult OnSend(ITcpServer* pSender, CONNID dwConnID, const BYTE* pData, int iLength);
	virtual EnHandleResult OnReceive(ITcpServer* pSender, CONNID dwConnID, int iLength);
	virtual EnHandleResult OnClose(ITcpServer* pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode);
	virtual EnHandleResult OnShutdown(ITcpServer* pSender);
private:
	static TPkgInfo* FindPkgInfo(ITcpServer* pSender, CONNID dwConnID);
	static void RemovePkgInfo(ITcpServer* pSender, CONNID dwConnID);
	//HpSocket 回调
	void HandlePacket(CONNID dwConnID, DWORD dwPacketID, CBufferPtr pbuffer);
private:
	void OnReceiveStrMessage(CONNID dwConnid, CBufferPtr pbuffer);
	void OnReceivePlayerInfo(CONNID dwConnid, CBufferPtr pbuffer);
private:
	static const USHORT PORT;
	static const LPCTSTR ADDRESS;
	CTcpPullServerPtr m_Server;
	CString m_strAddress;
private:
	//组装封包结构体
	void MySendPackets(CONNID dwConnID, DWORD dwpacketID, int body_len, char* Socketbody);
public:
	std::queue<SocketLoginInfo> m_vLoginInfo;//要登陆的帐号信息
	std::vector<SocketBind> m_vClient;//要登陆的帐号信息
	//////////////////////////////////////////////////////////////////////////
	//主控向dll发消息
	void MySendLoginInfo(CONNID dwConnID, CBufferPtr pbuffer);
	//主控向dll发执行脚本消息
	void MySendGameScript(SocketBind _SocketBind, CString Script);
	//主控向dll发停止脚本消息
	void MySendStopScript(SocketBind _SocketBind);
	//主控向dll发继续脚本消息
	void MySendContinueScript(SocketBind _SocketBind);
	//主控向dll发答题结果消息
	void SendValidateAnswer(SocketValidateResult* _Validate, INT body_len);//发送验证码名字，和类型
public:
	INT MyDelClient(CONNID dwConnID);//移除绑定链接的帐号名
	INT MyDelClient(SocketBind _SocketBind);//移除绑定链接的帐号名
	INT MyAddClient(CONNID dwConnID, SocketBind _SocketBind);//添加绑定链接的帐号名
	BOOL MyGetClientConnID(CONNID* dwConnID, SocketBind _SocketBind);//获取绑定帐号名链接的ID
	BOOL MyGetClientBind(CONNID dwConnID, SocketBind* _SocketBind);//获取绑定链接的帐号名
	vector<SocketBind> MyGetAllClient();//获取所有帐号
										//////////////////////////////////////////////////////////////////////////
	BOOL MyAddLoginInfo(SocketLoginInfo _SocketLoginInfo);//添加一个登录帐号信息数据
	BOOL MyGetLoginInfo(SocketLoginInfo* pSocketLoginInfo);//获取一个登录信息数据
	BOOL MyLoginInfoIsEmpty();//获取登录信息数据是否为空
};

extern  CCriticalSection g_State;
extern  CCriticalSection g_State_Queue;
void 状况信息(SocketBind _SocketBind, const char* _Message);