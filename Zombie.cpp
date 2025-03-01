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
	if (!hero->hasArmor()) {
		hero->decreaseHP(damage);
	}
	this->attackCD = this->attackrate;
}

void Zombie::move(Hero* hero, float fElapsedTime) {
	double heroObjX = NULL;
	hero->HereIsObjX(&heroObjX);
	double heroObjY = NULL;
	hero->HereIsObjY(&heroObjY);
	this->dirX = heroObjX - this->objX;
	this->dirY = heroObjY - this->objY;
	double dist = sqrt((dirX * dirX) + (dirY * dirY));
	objX += dirX / dist * speed * fElapsedTime;
	objY += dirY / dist * speed * fElapsedTime;

}

void Zombie::HereIsSpawnRate(double* sprate)
{
	*sprate = spawnRate;
}

void Zombie::HereIsAttackCooldown(double* cooldown)
{
	*cooldown = attackCD;
}
