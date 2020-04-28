#include "ShootingGame.h"

#define PI 3.14159265359

ShootingGame::ShootingGame()
{
}

bool ShootingGame::OnUserCreate()
{

	hero = Hero(ScreenWidth() / 2, ScreenHeight() / 2, 100, 100);
	manSprite = make_shared<olc::Sprite>("Sprites/ManTrans.png");
	deadSprite = make_shared<olc::Sprite>("Sprites/Dead.png");
	zombieSprite = make_shared<olc::Sprite>("Sprites/zombie.png");
	bonusSprite = make_shared<olc::Sprite>("Sprites/firstaid.png");

	/*x = ScreenWidth() / 2;
	y = ScreenHeight() / 2;
	heroSpeed = 100;
	*/
	/*
	  spawnRate = 5; //zombie spawn rate
	  spawnCD = 0;
	  */
	  /*  hpmax = 100;
		hpcurr = 50;*/

	gameTime = 0;
	gameEnd = false;

	for (int i = 0; i < 7; ++i)
		levelSprites.push_back(make_shared<olc::Sprite>("Sprites/Level" + to_string(i + 1) + ".png"));

	srand(NULL);
	return true;

}

bool ShootingGame::OnUserUpdate(float fElapsedTime)
{

	if (gameEnd) {
		DrawSprite(0, 0, deadSprite, 1);
		DrawString(ScreenWidth() / 2 - 38, ScreenHeight() / 2 - 10, "GAME OVER", olc::DARK_RED);
		DrawString(ScreenWidth() / 2 - 38, ScreenHeight() / 2, "Try again?", olc::BLACK);
		DrawString(ScreenWidth() / 2 - 35, ScreenHeight() / 2 + 10, "Press Y", olc::BLACK);
		DrawString(ScreenWidth() / 2 - 55, ScreenHeight() / 2 + 20, "Press N to exit", olc::BLACK);


		if (GetKey(olc::Y).bPressed)
		{
			OnUserCreate();
		}

		if (GetKey(olc::Key::N).bPressed)
			return false;

		return true;
	}


	gameTime += fElapsedTime;
	level = int(gameTime / 10) % 7 + 1;


	//ZOMBIE SPAWNS   //class shooting game
	Zombie::spawnCooldown -= fElapsedTime;
	if (Zombie::spawnCooldown <= 0)
	{
		double degree = rand() * 360;
		zombies.push_back(Zombie((cos(degree) * ScreenWidth()) + (ScreenWidth() / 2), (sin(degree) * ScreenHeight()) + (ScreenHeight() / 2), 50, 10, 10));
		Zombie::spawnCooldown = Zombie::spawnRate;
	}
	//ZOMBIE SPAWNS


	//SHOOTING  //hero'da
	if (GetKey(olc::SPACE).bPressed)
	{
		bullets.push_back(shoot(&hero));
	}
	//SHOOTING


	//UPDATE VARIABLES   
	double screenWidth = ScreenWidth();
	double screenHeight = ScreenHeight();
	if (GetKey(olc::W).bHeld)
		hero.move(screenHeight, screenWidth, fElapsedTime, olc::W);
	if (GetKey(olc::S).bHeld)
		hero.move(screenHeight, screenWidth, fElapsedTime, olc::S);
	if (GetKey(olc::D).bHeld)
		hero.move(screenHeight, screenWidth, fElapsedTime, olc::D);
	if (GetKey(olc::A).bHeld)
		hero.move(screenHeight, screenWidth, fElapsedTime, olc::A);
	//UPDATE VARIABLES

	////KEEP HERO IN WINDOW   // hero'da
	//if (y <= 0) { y = 0; }
	//if (x <= 0) { x = 0; }
	//if (y >= ScreenHeight()-1) { y = ScreenHeight()-1; }
	//if (x >= ScreenWidth()-1) { x = ScreenWidth()-1; }
	////KEEP HERO IN WINDOW


	//BULLETS



	//bullet'da
	for (int i = 0; i < bullets.size(); ++i)
	{
		/*
		bullets[i].objX += bullets[i].dirX * bullets[i].speed * fElapsedTime;
		bullets[i].objY += bullets[i].dirY * bullets[i].speed * fElapsedTime;
		*/
		bullets[i].move(fElapsedTime);

		if (bullets[i].objX < 0 || bullets[i].objX > ScreenWidth() || bullets[i].objY < 0 || bullets[i].objY > ScreenHeight())
		{
			bullets.erase(bullets.begin() + i);
			i--;
		}
	}
	//BULLETSMOVE


	//BULLETSHIT 
	for (int i = 0; i < bullets.size(); ++i)
	{
		for (int j = 0; j < zombies.size(); ++j)
		{
			if (distance(bullets[i].objX, bullets[i].objY, zombies[j].objX, zombies[j].objY) < 10)
			{
				zombies[j].hpCurrent -= bullets[i].damage;
				bullets.erase(bullets.begin() + i);
				i--;
				if (zombies[j].hpCurrent <= 0)
				{
					//RANDOM BONUS CREATION

					if (rand() % 5 < 1) {

						bonuses.push_back(Bonus(zombies[j].objX, zombies[j].objY, 20));
					}
					//RANDOM BONUS CREATION

					zombies.erase(zombies.begin() + j);
					j--;
				}
				break;
			}
		}
	}
	//BULLETSHIT

	//BONUS PICK UP 

	for (int i = 0; i < bonuses.size(); i++)
	{

		if (distance(hero.objX, hero.objY, bonuses[i].objX, bonuses[i].objY) <= 10)
		{

			hero.bonusPickUp(bonuses[i]);

			bonuses.erase(bonuses.begin() + i);
			i--;

		}

	}

	//BONUS PICK UP








	//ENEMIESMOVE  //zombie'de
	for (int i = 0; i < zombies.size(); ++i)
	{
		/*       double dirX =  x - enemies[i].objX;
			   double dirY =  y - enemies[i].objY;
			   double dist = sqrt((dirX * dirX) + (dirY * dirY));
			   enemies[i].objX += dirX / dist * enemies[i].speed * fElapsedTime;
			   enemies[i].objY += dirY / dist * enemies[i].speed * fElapsedTime;
			   */

		if (zombies[i].hpCurrent <= 0)
		{
			zombies.erase(zombies.begin() + i);
			i--;
		}
	}
	//ENEMIESMOVE

	//ENEMIESATTACK
	for (int i = 0; i < zombies.size(); i++)
	{
		zombies[i].attackCD -= fElapsedTime;

		if ((distance(zombies[i].objX, zombies[i].objY, hero.objX, hero.objY) <= 8) && (zombies[i].attackCD <= 0))
		{
			hero.hpCurrent -= zombies[i].damage;
			zombies[i].attackCD = zombies[i].attackrate;
		}
	}

	//ENEMIESATTACK

	//CHECKGAMEOVER


	// If HP is less than 0 or if you press E end game
	if (hero.hpCurrent <= 0 || GetKey(olc::E).bReleased)
	{

		for (int i = 0; i < zombies.size(); i++)
		{
			zombies.erase(zombies.begin());
			i--;
		}

		for (int i = 0; i < bullets.size(); i++)
		{
			bullets.erase(bullets.begin());
			i--;
		}


		for (int i = 0; i < bonuses.size(); i++)
		{
			bonuses.erase(bonuses.begin());
			i--;
		}

		gameEnd = true;


	}


	//TO BE IMPLEMENTED
//CHECKGAMEOVER


//DRAWING

//THE PLAYER
	Clear(olc::BLACK);
	DrawSprite(0, 0, levelSprites[level - 1], 1);
	SetPixelMode(olc::Pixel::ALPHA);
	olc::GFX2D::Transform2D t;
	t.Translate(-manSprite->width / 2, -manSprite->height / 2);
	t.Rotate(atan2((GetMouseX() - hero.objX), (GetMouseY() - hero.objY)) - PI / 2);
	t.Translate(hero.objX, hero.objY);
	olc::GFX2D::DrawSprite(manSprite.get(), t);


	//CROSSHAIR
	DrawLine(GetMouseX() - 5, GetMouseY(), GetMouseX() + 5, GetMouseY(), olc::RED);
	DrawLine(GetMouseX(), GetMouseY() - 5, GetMouseX(), GetMouseY() + 5, olc::RED);
	//CROSSHAIR

	//DRAW BULLETS
	for (auto a : bullets)
		DrawCircle(a.objX, a.objY, 1, olc::YELLOW);

	//DRAW ENEMIES
	for (auto a : zombies) {
		DrawSprite(a.objX - 12, a.objY - 12, zombieSprite, 1);
		//DrawCircle(a.x, a.y, 1, olc::RED);
		DrawHPBar(a);
		//DrawHPBar(a.x, a.y, a.hpmax, a.hp);
	}

	//DRAW BONUSES
	for (auto a : bonuses)
	{
		DrawSprite(a.objX - 10, a.objY - 10, bonusSprite, 1);
	}

	//DRAW HP BAR
	DrawHPBar(hero);

	//DRAWING
	return true;
}

void ShootingGame::DrawHPBar(LivingObject livingObj)
{

	double ratio = (double)(livingObj.hpCurrent) / (double)livingObj.hpMax;
	for (int i = livingObj.objX - 5; i < 5 + livingObj.objX; ++i)
		if (i < livingObj.objX - 5 + ratio * 10)
			DrawRect(i, livingObj.objY + 14, 1, 1, olc::GREEN);
		else
			DrawRect(i, livingObj.objY + 14, 1, 1, olc::RED);


}

double distance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

Bullet ShootingGame::shoot(Hero* hero) {

	double dirX = GetMouseX() - hero->objX;
	double dirY = GetMouseY() - hero->objY;
	double dist = sqrt((dirX * dirX) + (dirY * dirY));
	return Bullet(hero->objX, hero->objY, dirX / dist, dirY / dist, 200, 1);
}