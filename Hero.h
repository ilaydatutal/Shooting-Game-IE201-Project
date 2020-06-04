#pragma once
#include "LivingObject.h"

using namespace std;

class Hero : public LivingObject
{
protected:
	bool shieldActive = false;

public:
	Hero();
	Hero(double x, double y, double speed, double hpMax);
	void increaseHp(double quantity);
	void decreaseHp(double quantity);
	void haveShield();
	void move(double screenHeight, double screenWidth, float fElapsedTime, olc::Key pressedKey);
	
	

};

