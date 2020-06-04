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
	void setobjX(double objXIn);
	double getobjX();
	void HereIsObjX(double objX);
	void HereIsObjY(double objY);
	void setobjY(double objYIn);
	double getobjY();
	void setSpeed(double dirXIn);
	double getdirX();
	void setdirY(double dirYIn);
	double getdirY();
	void setSpeed(double speedIn);
	double getSpeed();


};

