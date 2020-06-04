#include "ShootingGame.h"

#define PI 3.14159265359

ShootingGame::ShootingGame()
{
}

bool ShootingGame::OnUserCreate()
{
	hero = Hero(ScreenWidth() / 2, ScreenHeight() / 2, 100, 100);   //set yerine ne yapmalýyýz?
	manSprite = make_shared<olc::Sprite>("Sprites/ManTrans.png");
	deadSprite = make_shared<olc::Sprite>("Sprites/Dead.png");
	zombieSprite = make_shared<olc::Sprite>("Sprites/zombie.png");
	bonusSprite = make_shared<olc::Sprite>("Sprites/firstaid.png");

	spawnCooldown = 0;

	gameTime = 0;
	gameEnd = false;

	for (int i = 0; i < 7; ++i)
		levelSprites.push_back(make_shared<olc::Sprite>("Sprites/Level" + to_string(i + 1) + ".png"));

	srand(NULL);
	return true;

}

double ShootingGame::timeTick(double gameTime, float fElapsedTime){
	gameTime += fElapsedTime;
	return gameTime;
}

bool ShootingGame::EndScreen(ShootingGame* game){
	DrawSprite(0, 0, deadSprite, 1);
	DrawString(ScreenWidth() / 2 - 38, ScreenHeight() / 2 - 10, "GAME OVER", olc::DARK_RED);
	DrawString(ScreenWidth() / 2 - 38, ScreenHeight() / 2, "Try again?", olc::BLACK);
	DrawString(ScreenWidth() / 2 - 35, ScreenHeight() / 2 + 10, "Press Y", olc::BLACK);
	DrawString(ScreenWidth() / 2 - 55, ScreenHeight() / 2 + 20, "Press N to exit", olc::BLACK);


	if (GetKey(olc::Y).bPressed){
		OnUserCreate();
	}

	if (GetKey(olc::Key::N).bPressed)
		return false;

	return true;
}

bool ShootingGame::OnUserUpdate(float fElapsedTime)
{

	if (gameEnd) {
		return EndScreen(this);
	}

	gameTime = timeTick(gameTime, fElapsedTime);
	
	level = int(gameTime / 10) % 7 + 1;


	//ZOMBIE SPAWNS   
	spawnCooldown -= fElapsedTime;
	Zombie zombietemp;
	double zombieSpawnRate;
	zombietemp.HereIsSpawnRate(zombieSpawnRate);
	if (spawnCooldown <= 0)
	{
		double degree = rand() * 360;
		zombies.push_back(Zombie((cos(degree) * ScreenWidth()) + (ScreenWidth() / 2), (sin(degree) * ScreenHeight()) + (ScreenHeight() / 2), 50, 10, 10, 0, 2));
		spawnCooldown = zombieSpawnRate;
	}
	//ZOMBIE SPAWNS


	//SHOOTING  //hero'da
	if (GetKey(olc::SPACE).bPressed)
	{
		bullets.push_back(shoot(hero));
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

	//BULLETS
	for (int i = 0; i < bullets.size(); ++i)
	{
		bullets[i].move(fElapsedTime);
		double x, y;
		bullets[i].HereIsObjX(x);
		bullets[i].HereIsObjY(y);

		if (x < 0 || x > ScreenWidth() || y < 0 || y > ScreenHeight())
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
			if (checkCollision(&zombies[i], &bullets[j])){
				bullets[i].hit(&zombies[j]);
				bullets.erase(bullets.begin() + i);
				i--;
				if (isDead(zombies[j])==true)
				{
					//RANDOM BONUS CREATION
					double zx, zy;
						zombies[j].HereIsObjX(zx);
						zombies[j].HereIsObjY(zy);
					if (rand() % 5 < 1) {
						bonuses.push_back(Bonus(zx, zy, 20));
					}
					else if (rand() % 5 < 1) {
						bonuses.push_back(ArmorBonus(zx, zy, 20));
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
		if (checkCollision(&hero, &bonuses[i])){
			bonuses[i].bonusPicked(&hero);

			bonuses.erase(bonuses.begin() + i);
			i--;
		}
	}

	//BONUS PICK UP

	//ENEMIESMOVE  //zombie'de
	for (int i = 0; i < zombies.size(); ++i)
	{
		zombies[i].move(&hero, fElapsedTime);

		if (isDead(zombies[i])==true)
		{
			zombies.erase(zombies.begin() + i);
			i--;
		}
	}
	//ENEMIESMOVE


	//ENEMIESATTACK
	for (int i = 0; i < zombies.size(); i++)
	{
		double cooldown;
		zombies[i].HereIsAttackCooldown(cooldown);
		cooldown -= fElapsedTime;

		if ((checkCollision(&zombies[i], &hero)) && (cooldown <= 0))
		{
			zombies[i].attack(&hero);
		}
	}

	//ENEMIESATTACK
	//CHECKGAMEOVER


	// If HP is less than 0 or if you press E end game
	if (isDead(hero) == true || GetKey(olc::E).bReleased)
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
	double hx, hy;
	hero.HereIsObjX(hx);
	hero.HereIsObjY(hy);
	Clear(olc::BLACK);
	DrawSprite(0, 0, levelSprites[level - 1], 1);
	SetPixelMode(olc::Pixel::ALPHA);
	olc::GFX2D::Transform2D t;
	t.Translate(-manSprite->width / 2, -manSprite->height / 2);
	t.Rotate(atan2((GetMouseX() - hx), (GetMouseY() - hy)) - PI / 2);
	t.Translate(hx, hy);
	olc::GFX2D::DrawSprite(manSprite.get(), t);


	//CROSSHAIR
	DrawLine(GetMouseX() - 5, GetMouseY(), GetMouseX() + 5, GetMouseY(), olc::RED);
	DrawLine(GetMouseX(), GetMouseY() - 5, GetMouseX(), GetMouseY() + 5, olc::RED);
	//CROSSHAIR

	//DRAW BULLETS
	
	for (auto a : bullets) {
		double bx, by;
		a.HereIsObjX(bx);
		a.HereIsObjY(by);
		DrawCircle(bx, by, 1, olc::YELLOW);
	}

	//DRAW ENEMIES
	for (auto a : zombies) {
		double zx, zy;
		a.HereIsObjX(zx);
		a.HereIsObjY(zy);
		DrawSprite(zx - 12, zy - 12, zombieSprite, 1);
		DrawCircle(zx, zy, 1, olc::RED);
		DrawHPBar(a);
	}

	//DRAW BONUSES
	for (auto a : bonuses){
		double bx, by;
		a.HereIsObjX(bx);
		a.HereIsObjY(by);
		DrawSprite(bx - 10, by - 10, bonusSprite, 1);
	}

	//DRAW HP BAR
	DrawHPBar(hero);

	//DRAWING
	return true;
}

void ShootingGame::DrawHPBar(LivingObject livingObj)
{
	double lx, ly, lHpC, lHpM;
	livingObj.HereIsObjX(lx);
	livingObj.HereIsObjY(ly);
	livingObj.HereIshpCurrent(lHpC);
	livingObj.HereIshpMax(lHpM);

	double ratio = (double)(lHpC) / (double)lHpM;
	for (int i = lx - 5; i < 5 + lx; ++i)
		if (i < lx - 5 + ratio * 10)
			DrawRect(i, ly + 14, 1, 1, olc::GREEN);
		else
			DrawRect(i, ly + 14, 1, 1, olc::RED);


}

double ShootingGame::distance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

bool ShootingGame::isDead(LivingObject livingobj)
{
	double hpC;
	livingobj.HereIshpCurrent(hpC);
	if (hpC <= 0) return true;
	else return false;
}



bool ShootingGame::checkCollision(Zombie* zombie, Hero* hero) {
	
	double zx, zy, hx, hy;
	zombie->HereIsObjX(zx);
	zombie->HereIsObjY(zy);
	hero->HereIsObjX(hx);
	hero->HereIsObjY(hy);

	if ((distance(hx,hy,zx,zy) <= 8)) {
		return true;
	}

}

bool ShootingGame::checkCollision(Zombie* zombie, Bullet* bullet) {
	
	double zx, zy, bx, by;
	zombie->HereIsObjX(zx);
	zombie->HereIsObjY(zy);
	bullet->HereIsObjX(bx);
	bullet->HereIsObjY(by);
	
	if (distance(bx, by, zx, zy) < 10) {
		return true;
	}

}

bool ShootingGame::checkCollision(Hero* hero, Bonus* bonus) {
	double hx, hy, bx, by;
	hero->HereIsObjX(hx);
	hero->HereIsObjY(hy);
	bonus->HereIsObjX(bx);
	bonus->HereIsObjY(by);
	if (distance(hx, hy, bx, by) <= 10) {
		return true;
	}
}

Bullet ShootingGame::shoot(Hero* hero) {
	double hx, hy;
	hero->HereIsObjX(hx);
	hero->HereIsObjY(hy);

 	double dirX = GetMouseX() - hx;
	double dirY = GetMouseY() - hy;
	double dist = sqrt((dirX * dirX) + (dirY * dirY));
	return Bullet(hx, hy, dirX / dist, dirY / dist, 200, 1);
}