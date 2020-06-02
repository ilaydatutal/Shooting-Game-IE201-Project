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
	void attack(Hero* hero);
	void move(Hero hero, float fElapsedTime);
	double getdamage();
	void setdamage(double damageIn);
	double getattackCD();
	void setattackCD(double attackCDIn);
	double getattackrate();
	void setattackrate(double attackrateeIn);
	double getspawnRate();
	void setspawnRate(double spawnRateIn);
};

