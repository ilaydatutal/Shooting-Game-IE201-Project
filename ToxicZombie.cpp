#include "ToxicZombie.h"
#include "Zombie.h"
#include "windows.h"

ToxicZombie::ToxicZombie() :Zombie()
{
}

ToxicZombie :: ToxicZombie(double xIn, double yIn, double speedIn, double damageIn, double hpIn, double attackCD, double attackRate, double timeActive) : Zombie(xIn, yIn, speedIn, damageIn, hpIn, attackCD, attackRate){
	this->damage = damageIn / 2;
	this->timeActive = timeActive;
}

void ToxicZombie::attack(Hero* hero, double currentTime)		//time içeren methodlar?
{
	double herohp = NULL;
	hero->HereIshpCurrent(&herohp);
	hero->decreaseHp(damage);
	this->attackCD = this->attackrate;
	int i;
	for (i = currentTime; i < currentTime + 10; i++) {
		herohp = herohp - 1;
		Sleep(1000);
	};
}
		
	



