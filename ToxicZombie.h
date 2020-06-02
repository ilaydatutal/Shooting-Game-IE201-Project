#pragma once
using namespace std;
#include "Zombie.h"


class ToxicZombie : public Zombie
{
protected :
	double timeActive;
private:
	ToxicZombie();
	ToxicZombie(double xIn, double yIn, double speedIn, double damageIn, double hpIn, double attackCD, double attackRate, double timeActive);
public:
	void poison(Hero* hero, double timeActive);
	double gettimeActive();
	void settimeActive(double timeActiveIn);


};

