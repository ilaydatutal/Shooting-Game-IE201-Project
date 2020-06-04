#pragma once
#include "Object.h"
using namespace std;

class LivingObject :
	public Object
{

protected:
	double hpMax;
	double hpCurrent;
	LivingObject();
	LivingObject(double x, double y, double speed, double hpMax, double hpCurrent, double dirX = NULL, double dirY = NULL);

public:
	void HereIshpCurrent(double* hp);
	void HereIshpMax(double* hp);

};

