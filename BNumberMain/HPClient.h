#pragma once

#include "../HPSocket/Src/HPSocket.h"
#include "../HPSocket/Common/Src/BufferPtr.h"
#include "SocketStruct.h"
#include <vector>
#include <string>
#include <queue>

using namespace std;

class CHPClient : public CTcpPullClientListener
{
public:
	CHPClient();
	~CHPClient();
private:
	static TPkgInfo* FindPkgInfo(ITcpServer* pSender, CONNID dwConnID);
	static void RemovePkgInfo(ITcpServer* pSender, CONNID dwConnID);
public:
	void HPInit();
	void HPRelease();
	void MySendPackets(DWORD dwpacketID, int body_len, char* Socketbody);
	void HandlePacket(DWORD dwPacketID, CBufferPtr& buffer);
	void SendValidateInfo(SocketValidate* _Validate, INT body_len);//发送验证码名字，和类型
public:
	//准备监听
	virtual EnHandleResult OnPrepareListen(ITcpServer* pSender, SOCKET soListen);
	//接受连接
	virtual EnHandleResult OnAccept(ITcpServer* pSender, CONNID dwConnID, SOCKET soClient);
	//数据已发送
	virtual EnHandleResult OnSend(ITcpServer* pSender, CONNID dwConnID, const BYTE* pData, int iLength);
	//数据到达
	virtual EnHandleResult OnReceive(ITcpServer* pSender, CONNID dwConnID, int iLength);
	//连接关闭
	virtual EnHandleResult OnClose(ITcpServer* pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode);
	//关闭组件
	//virtual EnHandleResult OnShutdown(ITcpServer* pSender);

	CTcpPullClientPtr m_Client;

	CString m_strAddress;
};