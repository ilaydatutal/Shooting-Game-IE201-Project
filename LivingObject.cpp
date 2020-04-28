#include "LivingObject.h"

using namespace std;

LivingObject::LivingObject(double x, double y, double speed, double hpMax, double hpCurrent, double dirX, double dirY) :Object(x, y, speed, dirX, dirY)
{
	this->hpMax = hpMax;
	this->hpCurrent = hpCurrent;
}

void LivingObject::DrawHPBar(ShootingGame* game)
{
	double ratio = (double)(this->hpCurrent) / (double)this->hpMax;
	for (int i = this->objX - 5; i < 5 + this->objX; ++i)
		if (i < this->objX - 5 + ratio * 10)
			game.DrawRect(i, this->objY + 14, 1, 1, olc::GREEN);
		else
			game.DrawRect(i, this->objY + 14, 1, 1, olc::RED);
}
