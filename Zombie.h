#pragma once
using namespace std;
#include "LivingObject.h"
#include "Hero.h"

class Zombie : public LivingObject
{
public:
	double damage;
	double attackCD;
	double attackrate;
	double spawnRate;
	double spawnCD;

	Zombie(double xIn, double yIn, double speedIn, double damageIn, double hpIn);
	void attack(Hero hero, float elapsedTime);
};

