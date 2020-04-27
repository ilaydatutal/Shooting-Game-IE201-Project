#include "Object.h"
Object::Object() {

}

void Object::move(float elapsedTime, double directionX = NULL, double directionY = NULL, Hero hero = NULL) {

    this->objX += this->dirX * this->speed * elapsedTime;
    this->objY += this->dirY * this->speed * elapsedTime;
}

