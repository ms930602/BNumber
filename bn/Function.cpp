#include "stdafx.h"
#include "Function.h"
#include "Self.h"
extern CMessage* pMsg;

struct TFunScene
{
	char szName[20];
	int nSceneId;
};

TFunScene gScene_Array[]//地图场景数组
{
	{ "洛阳", 0 },
	{ "苏州", 1 },
	{ "大理", 2 },
	{ "嵩山", 3 },
	{ "太湖 ", 4 },
	{ "镜湖", 5 },
	{ "无量山", 6 },
	{ "剑阁", 7 },
	{ "敦煌", 8 },
	{ "少林寺", 9 },
	{ "丐帮总舵", 0xA },
	{ "光明殿", 0xB },
	{ "武当山", 0xC },
	{ "天龙寺", 0xD },
	{ "凌波洞", 0xE },
	{ "峨嵋山", 0xF },
	{ "星宿海", 0x10 },
	{ "天山", 0x11 },
	{ "雁南", 0x12 },
	{ "西湖", 0x1E },
	{ "洱海", 0x18 }
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
	if (tcurmap.szName == "洛阳")
		tcurmap.nSceneId = 0;
	//dbgPrint("%s %d %s",__FUNCTION__,tcurmap.nSceneId,tcurmap.szName);

	return tcurmap;
}

int CFunction::FUN_GetSceneID(const char * szSceneName)//通过名称获取地图场景ID
{
	size_t Count = sizeof(gScene_Array) / sizeof(gScene_Array[0]);
	for (size_t i = 0; i < Count; i++)
	{
		if (strcmp(gScene_Array[i].szName, szSceneName) == 0)//名称完全匹配
		{
			return gScene_Array[i].nSceneId;
		}
	}

	return -1;//没有就返回-1
}
