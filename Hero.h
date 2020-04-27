#pragma once
using namespace std;
#include "LivingObject.h"

class Hero: public LivingObject
{
	
public:
	Hero();
	Bullet shoot(ShootingGame game);
	void bonusPickUp();

};

