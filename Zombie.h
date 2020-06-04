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
private:
	Zombie();
	Zombie(double xIn, double yIn, double speedIn, double damageIn, double hpIn, double attackCD, double attackRate);
public:
	virtual void attack(Hero* hero);
	void move(Hero* hero, float fElapsedTime);
	void decreaseHP(double quantity);
	void HereIsSpawnRate(double sprate);
	void HereIsAttackCooldown(double cooldown);
};

