#pragma once

#include "../HPLib/HPSocket.h"
#include "../HPLib/bufferptr.h"
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

	void HPInit();
	void HPRelease();
	virtual EnHandleResult OnConnect(IClient* pClient);
	virtual EnHandleResult OnSend(IClient* pClient, const BYTE* pData, int iLength);
	virtual EnHandleResult OnReceive(IClient* pClient, int iLength);
	virtual EnHandleResult OnClose(IClient* pClient);
	virtual EnHandleResult OnError(IClient* pClient, EnSocketOperation enOperation, int iErrorCode);
	void MySendPackets(DWORD dwpacketID, int body_len, char* Socketbody);
	void HandlePacket(DWORD dwPacketID, CBufferPtr& buffer);
	void SendValidateInfo(SocketValidate* _Validate, INT body_len);//发送验证码名字，和类型
	TPkgInfo m_pkgInfo;
	CTcpPullClientPtr m_Client;

};