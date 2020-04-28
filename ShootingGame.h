#pragma once

#include "olcSimpleEngine.h"
#include "olcPGEX_Graphics2D.h"
#include "vector"
#include "Hero.h"
#include "Bullet.h"
#include "Bonus.h"

using namespace std;

class ShootingGame : public olc::PixelGameEngine
{
	/*
	double x;
	double y;
	double heroSpeed;
	double hpmax;
	double hpcurr;
	double spawnRate;
	double spawnCD;
	*/



	vector<Bullet> bullets;
	vector<Zombie> zombies;
	vector<Bonus> bonuses;

	shared_ptr<olc::Sprite> bonusSprite;
	shared_ptr<olc::Sprite> manSprite;
	vector<shared_ptr<olc::Sprite>> levelSprites;
	shared_ptr<olc::Sprite> deadSprite;
	shared_ptr<olc::Sprite> zombieSprite;
	Hero hero;


	int level;
	double gameTime;
	bool gameEnd;
	double spawnCooldown;

	/*
	void DrawHPBar(int x, int y, int HPMax, int HPCurrent)
	{
		double ratio = (double)(HPCurrent) / (double)HPMax;
		for (int i = x - 5; i < 5 + x; ++i)
			if (i < x - 5 + ratio * 10)
				DrawRect(i, y + 14, 1,1, olc::GREEN);
			else
				DrawRect(i, y + 14, 1,1, olc::RED);
	}
	*/



public:
	ShootingGame();
	bool OnUserCreate(); //override
	

	bool OnUserUpdate(float fElapsedTime); //override

	void DrawHPBar(LivingObject livingObj);

	double distance(double x1, double y1, double x2, double y2);

	Bullet shoot(Hero hero);
	


};


