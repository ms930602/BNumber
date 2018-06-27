#pragma once
#include "SocketStruct.h"

class CHPInit : public CTcpPullClientListener
{
public:
	CHPInit(): m_Client(this) { ZeroMemory(&__SocketLoginInfo, sizeof(__SocketLoginInfo)); };
	~CHPInit();
public:
	/************************************************************************/
	/*
	/*tcp/ip客户端通信函数实现
	/*
	/************************************************************************/
	void HPInit();
	void HPRelease();
	void MySendPID();
	void MySendReconnection();//发送重连中控
	void MySendGameInfo(const char* message);
	void MySendValidate(SocketValidate _Validate);
	void MySendRoleInfo(int body_len, char* Socketbody);
private:
	void HandlePacket(DWORD dwPacketID, CBufferPtr& buffer);
	virtual EnHandleResult OnSend(ITcpClient* pSender, CONNID dwConnID, const BYTE* pData, int iLength);
	virtual EnHandleResult OnReceive(ITcpClient* pSender, CONNID dwConnID, int iLength);
	virtual EnHandleResult OnClose(ITcpClient* pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode);
	virtual EnHandleResult OnConnect(ITcpClient* pSender, CONNID dwConnID);
private:
	bool GetMibao(CString args, CString& strMiBao);//密保
	void MySendPackets(DWORD dwpacketID, int body_len, char* Socketbody);
private:
	TPkgInfo m_pkgInfo;
	CTcpPullClientPtr m_Client;
	SocketLoginInfo __SocketLoginInfo;
	CString CurrnetRunScript;//当前运行的脚本
public:
	void MyReconnection();   //检测通信断线的函数
	UINT SendRoleInfo();	//传递人物信息给主控的线程
	UINT Login_Thread();    //登录线程函数
	UINT bmp_thread(SocketValidate _Validate);//窗口线程函数
	UINT anser_thread(SocketValidateResult __SocketValidateResult);//验证窗口线程函数
	UINT LUA_thread(CString file);
};