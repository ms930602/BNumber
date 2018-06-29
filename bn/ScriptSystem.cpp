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

	//×¢²áÈ«¾Öº¯Êý
	objGlobal.Register("Script", *m_pSelfLua,
		&CSelfLua::LUA_Script);
}
