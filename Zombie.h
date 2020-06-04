#pragma once
using namespace std;
#include "Hero.h"

class Zombie : public LivingObject
{
protected:
	double damage;
	double attackCD;
	double attackrate;
	static double spawnRate;
public:
	Zombie();
	Zombie(double xIn, double yIn, double speedIn, double damageIn, double hpIn, double attackCD, double attackRate);
	virtual void attack(Hero* hero);
	void move(Hero* hero, float fElapsedTime);
	void HereIsSpawnRate(double* sprate);
	void HereIsAttackCooldown(double* cooldown);
};

