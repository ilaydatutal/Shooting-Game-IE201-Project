#include "Bullet.h"


using namespace std;

Bullet::Bullet(double x, double y, double speed, double dirX, double dirY, double damage) : NonLivingObject(x, y, speed, dirX, dirY) {
	this->damage = damage;
}

void Bullet::hit(Zombie zombie) {
	zombie.hpCurrent -= this->damage;
}

void Bullet::move(float fElapsedTime) {
	this->objX += this->dirX * this->speed * fElapsedTime;
	this->objY += this->dirY * this->speed * fElapsedTime;
}