#pragma once
#include "Self.h"

void SendToCtrl(TSelfMapFile tMeMapFile);
BOOL use_item_hp();
BOOL use_item_mp();
BOOL use_item_kouliang(TMsPet tAsmPet);
BOOL use_item_kuaile(DWORD Object);
BOOL role_buji(double hp, double mp);
BOOL pet_buji(double ku, int kl);
BOOL get_pet_xinxi(TMsPet* FightPet);