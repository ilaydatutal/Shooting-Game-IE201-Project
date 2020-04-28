//olcPixelGameEngine is being developed and shared for education purposes by javidx9 in OneLoneCoder Youtube Channel:
//https://www.youtube.com/channel/UC-yuWVUplUJZvieEligKBkA/about
//olcSimpleEngine is based on olcPixelGameEngine and simplified and modified by Bahadir Pamuk for IE201 course in Industrial Engineering Department of Bogazici University
//olcSimpleEngine.cpp is created in order to resolve object orientation issues, from now on sprites (from olc::Sprite) can be created inside other classes, independently
//Last Edit Date: 03.02.2020

#include "olcSimpleEngine.h"
#include "olcPGEX_Graphics2D.h"
#include "vector"
#include "Hero.h"
#include "Bullet.h"
#include "Bonus.h"
#include "ShootingGame.h"

using namespace std;




//struct Bullet{
//    double x;
//    double y;
//    double dirX;
//    double dirY;
//    double speed;
//    double damage;
//    Bullet(double xIn, double yIn, double dirXIn, double dirYIn, double speedIn, double damageIn)
//    {
//        x = xIn;
//        y = yIn;
//        dirX = dirXIn;
//        dirY = dirYIn;
//        speed = speedIn;
//        damage = damageIn;
//    }
//};

/*
struct Bonus {
	double x;
	double y;

	Bonus(double xIn, double yIn ) {

		x = xIn;
		y = yIn;
	}

};
*/

/*
struct Enemy {
	double x;
	double y;
	double speed;
	double damage;
	double hp;
	double hpmax;
	double attackCD;
	double attackrate;

	Enemy(double xIn, double yIn, double speedIn, double damageIn, double hpIn):attackCD(0),attackrate(2)
	{
		x = xIn;
		y = yIn;
		speed = speedIn;
		damage = damageIn;
		hpmax = hpIn;
		hp = hpmax;
	}
};
*/



int main()
{
	ShootingGame demo;
	if (demo.Construct(240, 240, 3, 3))
		demo.Start();

	return 0;
}