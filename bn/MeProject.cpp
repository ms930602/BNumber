#include "stdafx.h"
#include "MeProject.h"
#include "Self.h"

extern CMessage* pMsg;
//extern UI* pUI;
extern CSelf* pMe;
extern CMsRole* pAsmRole;
extern CMsItem* pAsmItem;
extern CMsPet* pAsmPet;
extern CUser* pUser;
extern CMsSkill* pAsmSkill;
extern CCriticalSection* pCriticalSection;
extern CCriticalSection* pCriticalSection2;
static DWORD PT_HP = 0;
static DWORD TS_HP = 0;
static DWORD PT_MP = 0;
static DWORD TS_MP = 0;
INT g_CurPet = 0;
INT g_CurPetCanUseSkill = 0;

void SendToCtrl(TSelfMapFile tMeMapFile)
{
	if (!pMe->hMapFile)
	{
		CString MapName;
		MapName.Format("Global\\WUYAN_ASM_EVNET%d", GetCurrentProcessId());
		//申请创建虚拟内存 名字是 ↑面的名字 返回新建文件映射对象的句柄
		pMe->hMapFile = ::CreateFileMapping((HANDLE)0xFFFFFFFF, NULL, PAGE_READWRITE, 0, 0x10000, (char*)(LPCSTR)MapName);
	}

	if (pMe->hMapFile)
	{
		//将一个文件映射对象映射到当前应用程序的地址空间。
		LPVOID Mem = ::MapViewOfFile(pMe->hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, 0);
		if (Mem)
		{
			memcpy(Mem, &tMeMapFile, sizeof(tMeMapFile));
			UnmapViewOfFile(Mem);
		}
	}
}
