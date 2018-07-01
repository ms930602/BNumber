#include "stdafx.h"
#include "ScriptSystem.h"
#include "Self.h"

extern CSelf* pMe;
extern CMessage* pMsg;

void CScriptSystem::LUA_ScriptSystemInitial()
{
	m_pSelfLua = new CSelfLua;
	pState = new LuaStateOwner(true);
	LuaObject objGlobal = (*pState)->GetGlobals();

	//注册全局函数

	objGlobal.Register("IsWindowShow", *m_pSelfLua,
		&CSelfLua::LUA_IsWindowShow);//Get_XParam_INT

	//-------------------------------------------------------------------------------------
	//注册DataBase函数对象//////////////////////////////////////////////////////////////////////
	LuaObject metatable_DataBase = objGlobal.CreateTable("MetaTableDataBase");
	metatable_DataBase.SetObject("__index", metatable_DataBase);

	metatable_DataBase.RegisterObjectFunctor("GetSceneID", &CSelfLua::LUA_GetSceneId);//获取场景id
}
