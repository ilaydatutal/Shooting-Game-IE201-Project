#include "Hero.h"
using namespace std;

Hero::Hero() :LivingObject()
{
}

Hero::Hero(double x, double y, double speed, double hpMax) : LivingObject(x, y, speed, hpMax, hpMax / 2) {
}

void Hero::move(double screenHeight, double screenWidth, float fElapsedTime, olc::Key pressedKey) {
	if (olc::W == pressedKey)
		this->objY -= fElapsedTime * this->speed;
	if (olc::S == pressedKey)
		this->objY += fElapsedTime * this->speed;
	if (olc::D == pressedKey)
		this->objX += fElapsedTime * this->speed;
	if (olc::A == pressedKey)
		this->objX -= fElapsedTime * this->speed;

	if (this->objY <= 0) { this->objY = 0; }
	if (this->objX <= 0) { this->objX = 0; }
	if (this->objY >= screenHeight - 1) { this->objY = screenHeight - 1; }
	if (this->objX >= screenWidth - 1) { this->objX = screenWidth - 1; }
}

void Hero::bonusPickUp(Bonus bonus) {
	if (this->hpCurrent + bonus.getAmount() < this->hpMax)
	{
		this->hpCurrent += bonus.getAmount();
	}
	else
	{
		this->hpCurrent = this->hpMax;
	}
}

void Hero::Shield(float currentTime) {
	double temp;
	temp = hpCurrent;
	int i;
	for (i = 0; i < 5; i++) {
		this->hpCurrent = temp;
		Sleep(1000);
	}
}
