#include "ExplodingZombie.h"
using namespace std;


ExplodingZombie::ExplodingZombie() :Zombie() {

}

ExplodingZombie::ExplodingZombie(double xIn, double yIn, double speedIn, double damageIn, double hpIn, double attackCD, double attackRate, double explosionDistance) : Zombie(xIn, yIn, speedIn, damageIn, hpIn, attackCD, attackRate) {
	this->explosionDistance = explosionDistance;
}


void ExplodingZombie::attack(LivingObject* lo) {
	lo->decreaseHP(damage);
	hpCurrent = 0;
}

void ExplodingZombie::HereIsExplosionDistance(double* ed)
{
	*ed = this->explosionDistance;
}
