#pragma once
#include "Object.h"
#include "ShootingGame.h"

using namespace std;

class LivingObject :
	public Object
{

public:
	double hpMax;
	double hpCurrent;

public:
	LivingObject(double x, double y, double speed, double hpMax, double hpCurrent, double dirX = NULL, double dirY = NULL);
	void DrawHPBar(ShootingGame* game);
};

