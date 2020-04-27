#include "Zombie.h"
Zombie::Zombie(double xIn, double yIn, double speedIn, double damageIn, double hpIn) :attackCD(0), attackrate(2) {
	this->objX = xIn;
	this->objY = yIn;
	this->speed = speedIn;
	this->damage = damageIn;
	this->hpMax = hpIn;
	this->hpCurrent = this->hpMax;
}

void Zombie::attack(Hero hero, float elapsedTime)
{

	this->attackCD -= elapsedTime;


	this->hpCurrent -= this->damage;
	this->attackCD = this->attackrate;

}
