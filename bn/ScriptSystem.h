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
	CSelfLua* m_pSelfLua;//��������
	LuaStateOwner* pState;//��ʼ��lua�Ļ����⣬���ܵ���lua����
};