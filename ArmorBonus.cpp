#include "ArmorBonus.h"

using namespace std;

ArmorBonus::ArmorBonus() :Bonus() {

} 

ArmorBonus::ArmorBonus(double xIn, double yIn, double amount) :Bonus(xIn, yIn, 0) {
	
}

void ArmorBonus::bonusPicked(Hero* hero, float fElapsedTime) { //time i�eren method??
	hero->haveShield();
}
