#pragma once
#include "SelfLua.h"

class CScriptSystem
{
public:
	CScriptSystem() {};
	~CScriptSystem()
	{
		delete pState;
		delete MeLua;
	};
public:
	void LUA_ScriptSystemInitial();
	void LUA_DoFile(const char* fileName)
	{
		(*pState)->DoFile(fileName);
	}
private:
	CSelfLua* m_pSelfLua;//声明对象
	LuaStateOwner* pState;//初始化lua的基本库，才能调用lua函数
};