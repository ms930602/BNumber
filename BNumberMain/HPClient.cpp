#include "stdafx.h"
#include "HPClient.h"

CHPClient::CHPClient()
{
}

CHPClient::~CHPClient()
{
}

void CHPClient::HPInit()
{
}

void CHPClient::HPRelease()
{
}

EnHandleResult CHPClient::OnConnect(IClient * pClient)
{
	return EnHandleResult();
}

EnHandleResult CHPClient::OnSend(IClient * pClient, const BYTE * pData, int iLength)
{
	return EnHandleResult();
}

EnHandleResult CHPClient::OnReceive(IClient * pClient, int iLength)
{
	return EnHandleResult();
}

EnHandleResult CHPClient::OnClose(IClient * pClient)
{
	return EnHandleResult();
}

EnHandleResult CHPClient::OnError(IClient * pClient, EnSocketOperation enOperation, int iErrorCode)
{
	return EnHandleResult();
}

void CHPClient::MySendPackets(DWORD dwpacketID, int body_len, char * Socketbody)
{
}

void CHPClient::HandlePacket(DWORD dwPacketID, CBufferPtr & buffer)
{
}

void CHPClient::SendValidateInfo(SocketValidate * _Validate, INT body_len)
{
}
