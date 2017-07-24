#include "AgentsHub.h"
#include "Vector2D.h"
#include <stdio.h>

void AgentsHub::init(Player* p, Enemy* e) {
    player = p;
    enemy = e;
}

void AgentsHub::updateInformation() {
    enemy->setPlayerPos(player->getPosition());
}

bool AgentsHub::checkCollision() {
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = player->getPosition().getX();
    rightA = leftA + player->getWidth();
    topA = player->getPosition().getY();
    bottomA = topA + player->getHeight();

    leftB = enemy->getPosition().getX();
    rightB = leftB + enemy->getWidth();
    topB = enemy->getPosition().getY();
    bottomB = topB + enemy->getHeight();

    if (bottomA <= topB) return false;
    if (topA >= bottomB) return false;
    if (rightA <= leftB) return false;
    if (leftA >= rightB) return false;

    return true;
}
