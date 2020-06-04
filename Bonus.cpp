#include "Bonus.h"
#include "Hero.h"

Bonus::Bonus():NonLivingObject(){
}

Bonus::Bonus(double xIn, double yIn, double amount) : NonLivingObject(xIn, yIn, 0){
	this->amount = amount;
}

void Bonus::bonusPicked(Hero* hero) {
	hero->increaseHp(amount);
}
