#pragma once
using namespace std;
#include "Zombie.h"


class ToxicZombie : public Zombie
{
public :
	double timeActive;

	ToxicZombie();
	ToxicZombie(double xIn, double yIn, double speedIn, double damageIn, double hpIn, double attackCD, double attackRate, double timeActive);
	void poison(Hero* hero, double timeActive);

};

