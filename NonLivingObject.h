#pragma once
#include "Object.h"
class NonLivingObject: public Object
{
public:
	NonLivingObject(double x, double y, double speed, double dirX = NULL, double dirY = NULL);
};

