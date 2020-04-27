#include "Hero.h"
#include "olcSimpleEngine.cpp"
#include "main.cpp"


Hero::Hero() {

}

Bullet Hero::shoot(ShootingGame game) {

	double dirX = game.GetMouseX() - this->objX;
	double dirY = game.GetMouseY() - this->objY;
	double dist = sqrt((dirX * dirX) + (dirY * dirY));
	return Bullet(this->objX, this->objY, dirX / dist, dirY / dist, 200, 1);
}

void bonusPickUp(Bonus bonus) {
    if (this.hpcurr + bonus.amount < this.hpmax)
    {
        this.hpcurr += bonus.amount;
    }
    else
    {
        this.hpcurr = this.hpmax;
    }
    removeObject(bonus);
}
