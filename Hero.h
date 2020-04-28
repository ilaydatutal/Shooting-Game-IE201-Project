#pragma once
using namespace std;
#include "LivingObject.h"
#include "main.cpp"
#include "Bonus.h"


class Hero : public LivingObject
{

public:
	Hero(double x, double y, double speed, double hpMax);
	void move(ShootingGame* game, float fElapsedTime, olc::Key pressedKey);
	Bullet shoot(ShootingGame game);
	void bonusPickUp(Bonus bonus);
	
};

