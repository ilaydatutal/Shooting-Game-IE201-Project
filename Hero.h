#pragma once
#include "LivingObject.h"
#include "Bonus.h"

using namespace std;

class Hero : public LivingObject
{

private:
	Hero();
	Hero(double x, double y, double speed, double hpMax);

public:
	void move(double screenHeight, double screenWidth, float fElapsedTime, olc::Key pressedKey);
	void bonusPickUp(Bonus bonus);
	void Shield(float currentTime);

};

