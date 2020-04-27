#pragma once
#include "olcSimpleEngine.h"
using namespace std;

class Object
{
	double objX;
	double objY;
	double dirX;
	double dirY;
	double speed;
	static shared_ptr<olc::Sprite> sprite;

public:
	Object();
	void move(float elapsedTime, double directionX = NULL, double directionY = NULL, Hero hero = NULL);
	void draw();
};

