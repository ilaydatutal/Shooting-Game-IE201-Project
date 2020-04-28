#pragma once
#include "Object.h"
using namespace std;
class NonLivingObject: public Object
{
public:
	NonLivingObject(double x, double y, double speed, double dirX = NULL, double dirY = NULL);
};

