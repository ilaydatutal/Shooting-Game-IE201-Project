#include "ToxicZombie.h"
#include "Zombie.h"

ToxicZombie::ToxicZombie() :Zombie()
{
}

ToxicZombie::ToxicZombie(double xIn, double yIn, double speedIn, double damageIn, double hpIn, double attackCD, double attackRate, double timeActive) : Zombie(xIn, yIn, speedIn, damageIn, hpIn, attackCD, attackRate) {
	this->timeActive = timeActive;
}

void ToxicZombie::attack(Hero* hero, double currentTime)
{
	hero->getToxicated(damage, timeActive);
}





