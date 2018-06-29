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
		//���봴�������ڴ� ������ ��������� �����½��ļ�ӳ�����ľ��
		pMe->hMapFile = ::CreateFileMapping((HANDLE)0xFFFFFFFF, NULL, PAGE_READWRITE, 0, 0x10000, (char*)(LPCSTR)MapName);
	}

	if (pMe->hMapFile)
	{
		//��һ���ļ�ӳ�����ӳ�䵽��ǰӦ�ó���ĵ�ַ�ռ䡣
		LPVOID Mem = ::MapViewOfFile(pMe->hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, 0);
		if (Mem)
		{
			memcpy(Mem, &tMeMapFile, sizeof(tMeMapFile));
			UnmapViewOfFile(Mem);
		}
	}
}
