#include "ArmorBonus.h"

using namespace std;

ArmorBonus::ArmorBonus() :Bonus() {

} 

ArmorBonus::ArmorBonus(double xIn, double yIn) :Bonus(xIn, yIn, -1) {
	
}

void ArmorBonus::bonusPicked(Hero* hero) { 
	hero->activateArmor();
}
