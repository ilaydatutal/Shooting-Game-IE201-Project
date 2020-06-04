#include "Object.h"
using namespace std;

Object::Object()
{
}

Object::Object(double x, double y, double speed, double dirX, double dirY) {
	this->objX = x;
	this->objY = y;
	this->speed = speed;
	this->dirX = dirX;
	this->dirY = dirY;
}

void Object::setobjX(double objXIn) {
	objX = objXIn;
}

double Object::getobjX() {
	return objX;
}

void Object::setobjY(double objYIn) {
	objY = objYIn;
}

double Object::getobjY() {
	return objY;
}

void Object::setSpeed(double dirXIn) {
	dirX = dirXIn;
}

double Object::getdirX() {
	return dirX;
}

void Object::setdirY(double dirYIn) {
	dirY = dirY;
}

double Object::getdirY() {
	return dirY;
}

void Object::setSpeed(double speedIn) {
	speed = speedIn;
}

double Object::getSpeed() {
	return speed;
}

void Object::HereIsObjX(double objX)
{
	objX = this->objX;
}
void Object::HereIsObjY(double objY)
{
	objY = this->objY;
}