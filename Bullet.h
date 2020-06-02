#pragma once
#include "NonLivingObject.h"
#include "Zombie.h"
using namespace std;
class Bullet: public NonLivingObject
{
protected:
    double damage;

private:
    Bullet();
    Bullet(double x, double y, double dirX, double dirY, double speed, double damage);

public:
    void setDamage(double damageIn);
    double getDamage();
    void hit(Zombie* zombie);
    void move(float fElapsedTime);

};

