#include "Object.h"
#include "main.cpp"
#include "Hero.h"
Object::Object(double x, double y, double speed, double dirX = NULL, double dirY = NULL) {
	this->objX = x;
	this->objY = y;
	this->speed = speed;
	this->dirX = dirX;
	this->dirY = dirY;
}

void Object::move(float elapsedTime, double directionX = NULL, double directionY = NULL, Hero hero = NULL) {

	this->objX += this->dirX * this->speed * elapsedTime;
	this->objY += this->dirY * this->speed * elapsedTime;
}

void Object::draw(ShootingGame game) {
}

