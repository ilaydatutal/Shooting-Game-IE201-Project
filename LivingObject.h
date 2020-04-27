#pragma once
#include "olcSimpleEngine.h"
#include "Object.h""
using namespace std;

class LivingObject: public Object
{
	double hpMax;
	double hpCurrent;

public:
	void DrawHPBar(int x, int y, int HPMax, int HPCurrent);
};

