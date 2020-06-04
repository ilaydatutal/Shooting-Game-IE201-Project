#pragma once
#include "LivingObject.h"
#include "Bonus.h"
#include "Zombie.h"

using namespace std;

class Hero : public LivingObject
{
private:
	bool shieldActive = false;
	Hero();
	Hero(double x, double y, double speed, double hpMax);

public:
	void increaseHp(double quantity);
	void decreaseHp(double quantity);
	void haveShield();
	void move(double screenHeight, double screenWidth, float fElapsedTime, olc::Key pressedKey);
	
	

};

