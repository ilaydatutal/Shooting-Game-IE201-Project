#pragma once
#include "Zombie.h"
class ExplodingZombie :public Zombie
{
protected:
	double speed;

private:
	ExplodingZombie();
	ExplodingZombie(double xIn, double yIn, double speedIn, double damageIn, double hpIn, double attackCD, double attackRate);

public:
	void setSpeed(double speedIn);
	double getSpeed();
	void explode(LivingObject livingCreature);
};

