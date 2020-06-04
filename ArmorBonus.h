#pragma once
#include "Bonus.h"
#include "Hero.h"
class ArmorBonus : public Bonus
{
public:
	ArmorBonus();
	ArmorBonus(double xIn, double yIn, double amount);
	void bonusPicked(Hero* hero, float fElapsedTime);

};