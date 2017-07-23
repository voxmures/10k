#include "AgentsHub.h"
#include "Vector2D.h"
#include <stdio.h>

void AgentsHub::init(Player* p, Enemy* e) {
    player = p;
    enemy = e;
}

void AgentsHub::updateInformation() {
    Vector2D* pos = player->getPlayerPos();
    enemy->setPlayerPos(pos);
}