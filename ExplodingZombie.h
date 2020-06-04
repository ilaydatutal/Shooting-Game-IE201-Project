#pragma once
#include "Zombie.h"
class ExplodingZombie :public Zombie
{
protected:
	double speed;

	ExplodingZombie();
	ExplodingZombie(double xIn, double yIn, double speedIn, double damageIn, double hpIn, double attackCD, double attackRate);

public:
	
	void attack(Hero* hero, Zombie* zombie);
};

