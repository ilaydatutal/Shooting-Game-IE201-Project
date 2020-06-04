#pragma once

#include "olcSimpleEngine.h"
#include "olcPGEX_Graphics2D.h"
#include "vector"
#include "Hero.h"
#include "Bullet.h"
#include "Bonus.h"
#include "ArmorBonus.h"


using namespace std;

class ShootingGame : public olc::PixelGameEngine
{
	
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



public:
	ShootingGame();
	bool OnUserCreate();									//override
	
	double timeTick(double gameTime, float fElapsedTime);

	bool EndScreen(ShootingGame* game);

	bool OnUserUpdate(float fElapsedTime);					//override

	void DrawHPBar(LivingObject livingObj);

	double distance(double x1, double y1, double x2, double y2);
	
	bool isDead(LivingObject livingobj);

	bool checkCollision(Zombie* zombie, Hero* hero);			

	bool checkCollision(Zombie* zombie, Bullet* bullet);		

	bool checkCollision(Hero* hero, Bonus* bonus);

	Bullet shoot(Hero* hero);

};


