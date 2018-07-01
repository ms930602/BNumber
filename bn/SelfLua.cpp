#include "stdafx.h"
#include "SelfLua.h"
#include "Self.h"

extern CMessage* pMsg;

int CSelfLua::LUA_Script(LuaState * pState)
{
	LuaStack args(pState);
	int nScript = args[1].GetInteger();
	
	if (nScript == 778899)
	{
		BuyShop_DiTan();
	}
	else if (nScript == 667788)
	{
		SellShop_DiTan();
	}
	else if (nScript == 112233)
	{
		HaoYouZhuFu();
	}

	return 0;
}

int CSelfLua::LUA_IsWindowShow(LuaState * pState)
{
	LuaStack args(pState);

	_tstring nOne = args[1].GetString();//获取传入的值

	int nVal = pMsg->msg_getnumber("g_GetValue = myIsWindowShow(\"%s\")", nOne.c_str());

	if (nVal == 1)
		pState->PushBoolean(true);
	else
		pState->PushBoolean(false);

	return 1;
}

/************************************************************************/
/////////////////////////////寻路相关的函数封装//////////////
/************************************************************************/
int CSelfLua::LUA_GetSceneId(LuaState * pState)//参数怪物名称杀怪
{
	LuaStack args(pState);

	_tstring strName = args[2].GetString();
	int nSceneId = FUN_GetSceneID(strName.c_str());

	dbgPrint(_T("LUA_GetSceneId %s %x"), strName.c_str(), nSceneId);

	pState->PushInteger(nSceneId);
	return 1;
}
