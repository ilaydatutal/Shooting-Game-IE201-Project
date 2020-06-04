#pragma once
#include "olcSimpleEngine.h"
using namespace std;

class Object
{
protected:
	double objX;
	double objY;
	double dirX;
	double dirY;
	double speed;

private:
	Object();
	Object(double x, double y, double speed, double dirX = NULL, double dirY = NULL);

public:
	void HereIsObjX(double objX);
	void HereIsObjY(double objY);
};

