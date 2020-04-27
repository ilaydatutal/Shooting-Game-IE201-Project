#pragma once
#include "NonLivingObject.h"
#include "Zombie.h"
class Bullet: public NonLivingObject
{
public:
    double damage;

    Bullet(double xIn, double yIn, double dirXIn, double dirYIn, double speedIn, double damageIn);
    void hit(Zombie zombie);
};

