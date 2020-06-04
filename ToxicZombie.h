#pragma once
using namespace std;
#include "Zombie.h"


class ToxicZombie : public Zombie
{
protected :
	double timeActive;

	ToxicZombie();
	ToxicZombie(double xIn, double yIn, double speedIn, double damageIn, double hpIn, double attackCD, double attackRate, double timeActive);
public:
	void attack(Hero* hero, double timeActive);
	


};

