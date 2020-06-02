#include "ExplodingZombie.h"
using namespace std;


ExplodingZombie::ExplodingZombie() : Zombie() {

}

ExplodingZombie::ExplodingZombie(double xIn, double yIn, double speedIn, double damageIn, double hpIn, double attackCD, double attackRate) : Zombie() {
	this->speed = speedIn / 4;
}

void ExplodingZombie::setSpeed(double speedIn) {
	speed = speedIn;
}

double ExplodingZombie::getSpeed() {
	return speed;
}

void ExplodingZombie::explode(LivingObject livingCreature) {
		
	livingCreature.hpCurrent -= this->damage;
}