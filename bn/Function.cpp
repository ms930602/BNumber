#include "stdafx.h"
#include "Function.h"
#include "Self.h"
extern CMessage* pMsg;

struct TFunScene
{
	char szName[20];
	int nSceneId;
};

TFunScene gScene_Array[]//��ͼ��������
{
	{ "����", 0 },
	{ "����", 1 },
	{ "����", 2 },
	{ "��ɽ", 3 },
	{ "̫�� ", 4 },
	{ "����", 5 },
	{ "����ɽ", 6 },
	{ "����", 7 },
	{ "�ػ�", 8 },
	{ "������", 9 },
	{ "ؤ���ܶ�", 0xA },
	{ "������", 0xB },
	{ "�䵱ɽ", 0xC },
	{ "������", 0xD },
	{ "�貨��", 0xE },
	{ "����ɽ", 0xF },
	{ "���޺�", 0x10 },
	{ "��ɽ", 0x11 },
	{ "����", 0x12 },
	{ "����", 0x1E },
	{ "����", 0x18 }
};
CFunction::CFunction()
{
}

CFunction::~CFunction()
{
}

TMsMap role_curmap()
{
	TMsMap tcurmap;
	tcurmap.bool_ret = TRUE;
	tcurmap.nSceneId = pMsg->msg_getnumber("g_GetValue = GetSceneID()");
	tcurmap.szName = pMsg->msg_getstring("mycurmapname", "mycurmapname = GetCurrentSceneName()").c_str();
	if (tcurmap.szName == "����")
		tcurmap.nSceneId = 0;
	//dbgPrint("%s %d %s",__FUNCTION__,tcurmap.nSceneId,tcurmap.szName);

	return tcurmap;
}

int CFunction::FUN_GetSceneID(const char * szSceneName)//ͨ�����ƻ�ȡ��ͼ����ID
{
	size_t Count = sizeof(gScene_Array) / sizeof(gScene_Array[0]);
	for (size_t i = 0; i < Count; i++)
	{
		if (strcmp(gScene_Array[i].szName, szSceneName) == 0)//������ȫƥ��
		{
			return gScene_Array[i].nSceneId;
		}
	}

	return -1;//û�оͷ���-1
}
