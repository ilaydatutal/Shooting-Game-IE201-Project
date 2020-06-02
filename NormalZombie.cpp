#include "NormalZombie.h"

NormalZombie::NormalZombie() : Zombie()
{
}
NormalZombie::NormalZombie(double xIn, double yIn, double speedIn, double damageIn, double hpIn, double attackCD, double attackRate) : Zombie(xIn, yIn, speedIn, damageIn, hpIn, attackCD, attackRate){
	this->damage = damageIn;
	this->hpMax = hpIn;
	this->hpCurrent = this->hpMax;
	this->attackCD = attackCD;
	this->attackrate = attackRate;
}

void NormalZombie::attack(Hero* hero)
{
	hero->gethpCurrent -= this->damage;
	this->attackCD = this->attackrate;
}
