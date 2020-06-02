#pragma once
#include "Object.h"
using namespace std;

class LivingObject :
	public Object
{

protected:
	double hpMax;
	double hpCurrent;

private:
	LivingObject();
	LivingObject(double x, double y, double speed, double hpMax, double hpCurrent, double dirX = NULL, double dirY = NULL);

public:
	void sethpMax(double hpMaxIn);
	double gethpMax();
	void sethpCurrent(double  hpCurrentIn);
	double gethpCurrent();

};

