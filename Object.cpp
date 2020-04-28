#include "Object.h"
#include "Hero.h"
using namespace std;

Object::Object(double x, double y, double speed, double dirX = NULL, double dirY = NULL) {
	this->objX = x;
	this->objY = y;
	this->speed = speed;
	this->dirX = dirX;
	this->dirY = dirY;
}



