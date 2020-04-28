#include "Bonus.h"

Bonus::Bonus():NonLivingObject()
{
}

Bonus::Bonus(double xIn, double yIn, double amount) : NonLivingObject(xIn, yIn, 0) {
	this->amount = amount;
	//this->sprite = MakeSelfRelativeSD
}
