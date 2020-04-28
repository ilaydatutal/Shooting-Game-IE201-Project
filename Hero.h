#pragma once
#include "Bonus.h"
#include "ShootingGame.h"
using namespace std;

class Hero : public LivingObject
{

public:
	Hero(double x, double y, double speed, double hpMax);
	void move(ShootingGame* game, float fElapsedTime, olc::Key pressedKey);
	Bullet shoot(ShootingGame* game);
	void bonusPickUp(Bonus bonus);

};

