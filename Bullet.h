#pragma once
#include "NonLivingObject.h"
#include "Zombie.h"
class Bullet: public NonLivingObject
{
public:
    double damage;

    Bullet(double x, double y, double speed, double dirX, double dirY, double damage);
    void hit(Zombie zombie);
    void move(float fElapsedTime);
};

