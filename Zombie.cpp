#include "Zombie.h"
double Zombie::spawnRate = 5;
Zombie::Zombie() :LivingObject()
{
}
Zombie::Zombie(double xIn, double yIn, double speedIn, double damageIn, double hpIn, double attackCD, double attackRate) : LivingObject(xIn, yIn, speedIn, NULL, NULL) {

	/*
	this->objX = xIn;
	this->objY = yIn;
	this->speed = speedIn;
	*/
	this->damage = damageIn;
	this->hpMax = hpIn;
	this->hpCurrent = this->hpMax;
	this->attackCD = attackCD;
	this->attackrate = attackRate;
	//this->sprite = make_shared<olc::Sprite>("Sprites/zombie.png");
}

void Zombie::attack(Hero hero, float fElapsedTime)
{
	this->attackCD -= fElapsedTime;
	hero.hpCurrent -= this->damage;
	this->attackCD = this->attackrate;

}
void Zombie::move(Hero hero, float fElapsedTime) {
	this->dirX = hero.objX - this->objX;
	this->dirY = hero.objY - this->objY;
	double dist = sqrt((dirX * dirX) + (dirY * dirY));
	objX += dirX / dist * this->speed * fElapsedTime;
	objY += dirY / dist * speed * fElapsedTime;

}