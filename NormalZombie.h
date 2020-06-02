#pragma once
#include "Zombie.h"
class NormalZombie : public Zombie
{

private:
	NormalZombie();
	NormalZombie(double xIn, double yIn, double speedIn, double damageIn, double hpIn, double attackCD, double attackRate);

public:
	void attack(Hero* hero);

};

