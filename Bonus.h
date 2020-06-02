#pragma once
#include "NonLivingObject.h"
class Bonus : public NonLivingObject
{
protected:
	double amount;

private:
	Bonus();
	Bonus(double xIn, double yIn, double amount);

public:
	void setAmount(double amountIn);
	double getAmount();
};

