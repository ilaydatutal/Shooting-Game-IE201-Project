#pragma once
#include "NonLivingObject.h"
#include "Zombie.h"
class Bullet: public NonLivingObject
{
public:
    double damage;
    void hit(Zombie zombie);
};

