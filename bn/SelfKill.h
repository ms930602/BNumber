#pragma once
#include "UI.h"
#include "Self.h"
#include "Function.h"

enum EBackCity
{
	用户无血药 = 1,
	用户无蓝药 = 2,
	用户无口粮 = 3,
	用户无驯养 = 4,
	用户道具满 = 5,
	用户材料满 = 6,
	用户帮战时 = 7
};

typedef vector<int> VMeGroundParcelId;