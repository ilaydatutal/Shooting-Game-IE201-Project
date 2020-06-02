#include "LivingObject.h"

using namespace std;

LivingObject::LivingObject() : Object()
{
}

LivingObject::LivingObject(double x, double y, double speed, double hpMax, double hpCurrent, double dirX, double dirY) :Object(x, y, speed, dirX, dirY)
{
	this->hpMax = hpMax;
	this->hpCurrent = hpCurrent;
}

void LivingObject::sethpMax(double hpMaxIn)
{
	hpMax = hpMaxIn;
}

double LivingObject::gethpMax()
{
	return hpMax;
}

void LivingObject::sethpCurrent(double  hpCurrentIn)
{
	hpCurrent = hpCurrentIn;
}

double LivingObject::gethpCurrent()
{
	return  hpCurrent;
}

