#pragma once
#include "NonLivingObject.h"
#include "Hero.h"
class ArmorBonus : public Bonus
{
private:
	ArmorBonus();
	ArmorBonus(double xIn, double yIn, double amount);
public:
	void bonusPicked(Hero* hero);

};