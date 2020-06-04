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

void Object::HereIsObjX(double objX)
{
	objX = this->objX;
}
void Object::HereIsObjY(double objY)
{
	objY = this->objY;
}