#pragma once
#include "olcSimpleEngine.h"
using namespace std;

class Object
{
public :
	double objX;
	double objY;
	double dirX;
	double dirY;
	double speed;
	static shared_ptr<olc::Sprite> sprite;

public:
	Object();
	Object(double x, double y, double speed, double dirX = NULL, double dirY = NULL);
	

};

