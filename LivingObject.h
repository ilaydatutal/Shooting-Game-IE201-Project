#pragma once
//#include "olcSimpleEngine.h"
#include "Object.h""
using namespace std;

class LivingObject: public Object
{
public:
	double hpMax;
	double hpCurrent;

public:
	LivingObject();
	void DrawHPBar(int x, int y, int HPMax, int HPCurrent);
};

