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

	//ע��ȫ�ֺ���

	objGlobal.Register("IsWindowShow", *m_pSelfLua,
		&CSelfLua::LUA_IsWindowShow);//Get_XParam_INT

	//-------------------------------------------------------------------------------------
	//ע��DataBase��������//////////////////////////////////////////////////////////////////////
	LuaObject metatable_DataBase = objGlobal.CreateTable("MetaTableDataBase");
	metatable_DataBase.SetObject("__index", metatable_DataBase);

	metatable_DataBase.RegisterObjectFunctor("GetSceneID", &CSelfLua::LUA_GetSceneId);//��ȡ����id
}
