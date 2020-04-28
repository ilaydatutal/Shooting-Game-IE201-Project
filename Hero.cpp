#include "Hero.h"
using namespace std;

Hero::Hero(double x, double y, double speed, double hpMax) :LivingObject(x, y, speed, hpMax, hpMax / 2) {

	this->sprite = make_shared<olc::Sprite>("Sprites/ManTrans.png");
}

void Hero::move(ShootingGame* game, float fElapsedTime, olc::Key pressedKey) {
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
	if (this->objY >= game->ScreenHeight() - 1) { this->objY = game->ScreenHeight() - 1; }
	if (this->objX >= game->ScreenWidth() - 1) { this->objX = game->ScreenWidth() - 1; }
}

Bullet Hero::shoot(ShootingGame game) {

	double dirX = game.GetMouseX() - this->objX;
	double dirY = game.GetMouseY() - this->objY;
	double dist = sqrt((dirX * dirX) + (dirY * dirY));
	return Bullet(this->objX, this->objY, dirX / dist, dirY / dist, 200, 1);
}

void Hero::bonusPickUp(Bonus bonus) {
	if (this->hpCurrent + bonus.amount < this->hpMax)
	{
		this->hpCurrent += bonus.amount;
	}
	else
	{
		this->hpCurrent = this->hpMax;
	}
}
