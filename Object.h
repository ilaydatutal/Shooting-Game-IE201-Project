#pragma once
#include "olcSimpleEngine.h"
#include "main.cpp"
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
	Object(double x, double y, double speed, double dirX = NULL, double dirY = NULL);
	

};

