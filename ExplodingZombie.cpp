#include "ExplodingZombie.h"
using namespace std;


ExplodingZombie::ExplodingZombie() : Zombie() {

}

ExplodingZombie::ExplodingZombie(double xIn, double yIn, double speedIn, double damageIn, double hpIn, double attackCD, double attackRate) : Zombie() {
	this->speed = speedIn / 4;
}


void ExplodingZombie::attack(Hero* hero, Zombie* zombie) {
		
	hero->decreaseHp(3*damage);
	zombie->decreaseHP(3*damage);
	hpCurrent = 0;

}