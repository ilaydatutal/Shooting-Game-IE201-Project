#include "Hero.h"
using namespace std;
double Hero::armorCooldown = 5;

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


void Hero::increaseHp(double quantity) {
	hpCurrent += quantity;
}
bool Hero::hasArmor() {
	return armorActive;
}

void Hero::activateArmor()
{
	armorActive = true;
	armorTimeLeft = armorCooldown;
}
void Hero::getToxicated(double toxicDamage, double toxicTime) {
	this->toxicDamage = toxicDamage;
	this->toxicTimeLeft = toxicTime;
}

void Hero::update(float fElapsedTime)
{
	if (armorTimeLeft > 0) {
		armorTimeLeft -= fElapsedTime;
	}
	else {
		armorTimeLeft = 0;
		armorActive = false;
	}

	if (toxicTimeLeft > 0) {
		toxicTimeLeft -= fElapsedTime;
		this->decreaseHP(fElapsedTime * toxicDamage);
	}
	else {
		toxicTimeLeft = 0;
	}
}
