#include "Hero.h"
#include "olcSimpleEngine.cpp"
#include "main.cpp"
#include "Bonus.h"



Hero::Hero() {

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
    removeObject(bonus);
}
