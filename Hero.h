#pragma once
#include "LivingObject.h"
#include "Bonus.h"

using namespace std;

class Hero : public LivingObject
{

public:
	Hero(double x, double y, double speed, double hpMax);
	void move(double screenHeight, double screenWidth, float fElapsedTime, olc::Key pressedKey);
	void bonusPickUp(Bonus bonus);

};

