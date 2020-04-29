#pragma once
#include "NonLivingObject.h"
#include "Zombie.h"
using namespace std;
class Bullet: public NonLivingObject
{
public:
    double damage;

    Bullet();
    Bullet(double x, double y, double dirX, double dirY, double speed, double damage);
    void hit(Zombie* zombie);
    void move(float fElapsedTime);
};

