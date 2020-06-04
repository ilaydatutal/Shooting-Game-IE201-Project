#pragma once
#include "Zombie.h"
class ExplodingZombie :public Zombie
{
private:
	double explosionDistance;

public:

	ExplodingZombie();
	ExplodingZombie(double xIn, double yIn, double speedIn, double damageIn, double hpIn, double attackCD, double attackRate, double explosionDistance);
	void attack(LivingObject* lo);
	void HereIsExplosionDistance(double* ed);
};

