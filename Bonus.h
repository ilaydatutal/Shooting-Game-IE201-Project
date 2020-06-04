#pragma once
#include "NonLivingObject.h"
#include "Hero.h"
class Bonus : public NonLivingObject
{
protected:
	double amount;
public:
	Bonus();
	Bonus(double xIn, double yIn, double amount);
	void HereIsAmount(double* amount);
	virtual void bonusPicked(Hero* hero);
};

