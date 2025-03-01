#include "Bullet.h"


using namespace std;

Bullet::Bullet():NonLivingObject()
{
}

Bullet::Bullet(double x, double y, double dirX, double dirY, double speed, double damage) : NonLivingObject(x, y, speed, dirX, dirY) {
	this->damage = damage;
}


void Bullet::hit(Zombie* zombie) {
	zombie->decreaseHP(damage);
}

void Bullet::move(float fElapsedTime) {
	this->objX += this->dirX * this->speed * fElapsedTime;
	this->objY += this->dirY * this->speed * fElapsedTime;
}