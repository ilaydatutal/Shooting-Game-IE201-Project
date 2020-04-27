#include "Bullet.h"


using namespace std;

Bullet::Bullet(double xIn, double yIn, double dirXIn, double dirYIn, double speedIn, double damageIn) {
    this->objX = xIn;
    this->objY = yIn;
    this->dirX = dirXIn;
    this->dirY = dirYIn;
    this->speed = speedIn;
    this->damage = damageIn;
}

void Bullet::hit(Zombie zombie) {
    zombie.hpCurrent -= this->damage;
    removeObject(this);
    if (zombie.hpCurrent <= 0)
    {
        //RANDOM BONUS CREATION

        if (rand() % 5 < 1) {

            bonuses.push_back(Bonus(zombie.objX, zombie.objY));
        }
        //RANDOM BONUS CREATION

        removeObject(zombie);
    }
}