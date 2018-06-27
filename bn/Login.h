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
	/*tcp/ip�ͻ���ͨ�ź���ʵ��
	/*
	/************************************************************************/
	void HPInit();
	void HPRelease();
	void MySendPID();
	void MySendReconnection();//���������п�
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
	bool GetMibao(CString args, CString& strMiBao);//�ܱ�
	void MySendPackets(DWORD dwpacketID, int body_len, char* Socketbody);
private:
	TPkgInfo m_pkgInfo;
	CTcpPullClientPtr m_Client;
	SocketLoginInfo __SocketLoginInfo;
	CString CurrnetRunScript;//��ǰ���еĽű�
public:
	void MyReconnection();   //���ͨ�Ŷ��ߵĺ���
	UINT SendRoleInfo();	//����������Ϣ�����ص��߳�
	UINT Login_Thread();    //��¼�̺߳���
	UINT bmp_thread(SocketValidate _Validate);//�����̺߳���
	UINT anser_thread(SocketValidateResult __SocketValidateResult);//��֤�����̺߳���
	UINT LUA_thread(CString file);
};