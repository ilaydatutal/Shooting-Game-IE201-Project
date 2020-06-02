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

void ToxicZombie::poison(Hero* hero, double currentTime)
{

	hero->gethpCurrent -= this->damage;
	this->attackCD = this->attackrate;
	int i;
	for (i = currentTime; i < currentTime + 10; i++) {
		hero->gethpCurrent = hero->gethpCurrent - 1;
		Sleep(1000);
	};
}
		
double ToxicZombie::gettimeActive()
{
		return timeActive;
}

void ToxicZombie::settimeActive(double timeActiveIn) 
{
		timeActive = timeActiveIn;
}
	



