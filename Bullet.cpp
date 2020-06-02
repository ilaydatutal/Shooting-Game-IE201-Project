#include "Bullet.h"


using namespace std;

Bullet::Bullet():NonLivingObject()
{
}

Bullet::Bullet(double x, double y, double dirX, double dirY, double speed, double damage) : NonLivingObject(x, y, speed, dirX, dirY) {
	this->damage = damage;
}

void Bullet::setDamage(double damageIn) {
	damage = damageIn;
}

double Bullet::getDamage() {
	return damage;
}

void Bullet::hit(Zombie* zombie) {
	zombie->hpCurrent -= this->damage;
}

void Bullet::move(float fElapsedTime) {
	this->objX += this->dirX * this->speed * fElapsedTime;
	this->objY += this->dirY * this->speed * fElapsedTime;
}