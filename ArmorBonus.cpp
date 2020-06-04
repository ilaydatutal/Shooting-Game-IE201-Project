#include "ArmorBonus.h"
#include "Bonus.h"

using namespace std;

ArmorBonus::ArmorBonus() :Bonus() {

} 

ArmorBonus::ArmorBonus(double xIn, double yIn, double amount) :Bonus(xIn, yIn, 0) {
	
}

void ArmorBonus::bonusPicked(Hero* hero) { //time içeren method??
	hero->haveShield();
}
