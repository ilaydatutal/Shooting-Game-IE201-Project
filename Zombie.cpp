#include "Zombie.h"
double Zombie::spawnRate = 5;

Zombie::Zombie() :LivingObject()
{
}
Zombie::Zombie(double xIn, double yIn, double speedIn, double damageIn, double hpIn, double attackCD, double attackRate) : LivingObject(xIn, yIn, speedIn, NULL, NULL) {

	this->damage = damageIn;
	this->hpMax = hpIn;
	this->hpCurrent = this->hpMax;
	this->attackCD = attackCD;
	this->attackrate = attackRate;
}

void Zombie::attack(Hero* hero)
{
	hero->gethpCurrent -= this->damage;
	this->attackCD = this->attackrate;
}

void Zombie::move(Hero hero, float fElapsedTime) {
	this->dirX = hero.getobjX() -this->objX;
	this->dirY = hero.getobjY() - this->objY;
	double dist = sqrt((dirX * dirX) + (dirY * dirY));
	objX += dirX / dist * this->speed * fElapsedTime;
	objY += dirY / dist * speed * fElapsedTime;

}

double Zombie::getdamage()
{
	return damage;
}

void Zombie::setdamage(double damageIn)
{
	damage = damageIn;
}

double Zombie::getattackCD()
{
	return attackCD;
}

void Zombie::setattackCD(double attackCDIn)
{
	attackCD = attackCDIn;
}
double Zombie::getattackrate()
{
	return attackrate;
}

void Zombie::setattackrate(double attackrateIn)
{
	attackrate = attackrateIn;
}

double Zombie::getspawnRate()
{
	return spawnRate;
}

void Zombie::setspawnRate(double spawnRateIn)
{
	spawnRate = spawnRateIn;
}
