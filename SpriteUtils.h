#pragma once
#include "olcSimpleEngine.h"
#include "Hero.h"
#include "Zombie.h"
using namespace std;
class SpriteUtils
{

public:
	static shared_ptr<olc::Sprite> bonusSprite = make_shared<olc::Sprite>("Sprites/firstaid.png");
	static shared_ptr<olc::Sprite> manSprite = make_shared<olc::Sprite>("Sprites/ManTrans.png");
	static shared_ptr<olc::Sprite> deadSprite = make_shared<olc::Sprite>("Sprites/Dead.png");
	static shared_ptr<olc::Sprite> zombieSprite = make_shared<olc::Sprite>("Sprites/zombie.png");


};

