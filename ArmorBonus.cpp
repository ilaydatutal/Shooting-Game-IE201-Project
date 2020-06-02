#include "ArmorBonus.h"

using namespace std;

bool isActive;
int ActiveTime;
ArmorBonus::ArmorBonus() :NonLivingObject() {

}

ArmorBonus::ArmorBonus(double xIn, double yIn) : NonLivingObject(xIn, yIn, 0) {
	this->objX = xIn;
	this->objY = yIn;
	isActive = false;
	ActiveTime = 0;
}
