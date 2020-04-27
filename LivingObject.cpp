#include "LivingObject.h"
#include "main.cpp"

LivingObject::LivingObject() {

}

void DrawHPBar(int x, int y, int HPMax, int HPCurrent, ShootingGame game) {
    double ratio = (double)(HPCurrent) / (double)HPMax;
    for (int i = x - 5; i < 5 + x; ++i)
        if (i < x - 5 + ratio * 10)
            game.DrawRect(i, y + 14, 1, 1, olc::GREEN);
        else
            game.DrawRect(i, y + 14, 1, 1, olc::RED);
}