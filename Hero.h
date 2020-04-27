#pragma once
using namespace std;
#include "LivingObject.h"
#include "main.cpp"


class Hero: public LivingObject
{
	
public:
	Hero();
	Bullet shoot(ShootingGame game);
	void bonusPickUp(Bonus bonus);

};

