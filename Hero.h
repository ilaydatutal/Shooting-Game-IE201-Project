#pragma once
#include "LivingObject.h"

using namespace std;

class Hero : public LivingObject
{
private:
	static double armorCooldown;
	double armorTimeLeft;
	double toxicTimeLeft;
	double toxicDamage;
protected:
	bool armorActive = false;

public:
	Hero();
	Hero(double x, double y, double speed, double hpMax);
	void increaseHp(double quantity);
	bool hasArmor();
	void activateArmor();
	void getToxicated(double toxicRate, double toxicTime);
	void update(float fElapsedTime);
	void move(double screenHeight, double screenWidth, float fElapsedTime, olc::Key pressedKey);
	
};

