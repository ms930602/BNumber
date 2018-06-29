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
	objGlobal.Register("Script", *m_pSelfLua,
		&CSelfLua::LUA_Script);
}
