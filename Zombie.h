#pragma once
using namespace std;
#include "Hero.h"

class Zombie : public LivingObject
{
public:
	double damage;
	double attackCD;
	double attackrate;
	static double spawnRate;

	Zombie();
	Zombie(double xIn, double yIn, double speedIn, double damageIn, double hpIn, double attackCD, double attackRate);
	void attack(Hero* hero);
	void move(Hero hero, float fElapsedTime);
};

