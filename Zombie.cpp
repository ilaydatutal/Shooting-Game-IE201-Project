#include "Zombie.h"
Zombie::Zombie(double xIn, double yIn, double speedIn, double damageIn, double hpIn) :LivingObject(xIn, yIn, speedIn, NULL, NULL) {
	
	/*
	this->objX = xIn;
	this->objY = yIn;
	this->speed = speedIn;
	*/
	this->damage = damageIn;
	this->hpMax = hpIn;
	this->hpCurrent = this->hpMax;
	this->sprite = make_shared<olc::Sprite>("Sprites/zombie.png");
}

void Zombie::attack(Hero hero, float elapsedTime)
{

	this->attackCD -= elapsedTime;
	this->hpCurrent -= this->damage;
	this->attackCD = this->attackrate;

}
