#pragma once
#include "NonLivingObject.h"
class Bonus : public NonLivingObject
{
public:
	double amount;
	Bonus(double xIn, double yIn);
};

