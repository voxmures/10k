#include "Enemy.h"
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>

#ifdef __linux__
    //linux code goes here
	#include <SDL2/SDL.h>
#elif _WIN32
	//windows code goes here
	#include <SDL.h>
#endif

Enemy::Enemy() : SDLGameObject() {}

void Enemy::draw() {
    SDLGameObject::draw();
}

void Enemy::update() {
    m_velocity.setX(0);
    m_velocity.setY(0);

    nextAction();

    m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));

    SDLGameObject::update();
}

void Enemy::clean() {
    SDLGameObject::clean();
}

void Enemy::load(const LoaderParams* pParams) {
    SDLGameObject::load(pParams);
}

void Enemy::nextAction() {

    //Heuristic: Manhattan distance to the player
    vector<float>scores(5);
    scores[0] = fabs(playerPos->getX() - m_position.getX()) + fabs(playerPos->getY() - m_position.getY()-2.0); //UP
    scores[1] = fabs(playerPos->getX() - m_position.getX()) + fabs(playerPos->getY() - m_position.getY()+2.0); //DOWN
    scores[2] = fabs(playerPos->getX() - m_position.getX()-2.0) + fabs(playerPos->getY() - m_position.getY()); //LEFT
    scores[3] = fabs(playerPos->getX() - m_position.getX()+2.0) + fabs(playerPos->getY() - m_position.getY()); //RIGHT
    scores[4] = fabs(playerPos->getX() - m_position.getX()) + fabs(playerPos->getY() - m_position.getY()); //UP

    int action = 0;

    for(int i=0; i<scores.size();++i) {
        if(scores[i] < scores[action])
            action = i;
    }
    /* Print positions for debug
    printf("================\n");
    printf("%f", playerPos->getX() - m_position.getX() + playerPos->getY() - m_position.getY()-2);
    printf("scores %f %f %f %f %f \n" , scores[0], scores[1], scores[2], scores[3], scores[4]);
    printf("player %f %f \n", playerPos->getX(), playerPos->getY());
    printf("enemy %f %f \n", m_position.getX(), m_position.getY());
    printf("Action %i \n", action);*/
    switch(action) {
        case 0:
            m_velocity.setY(2);
            break;
        case 1:
            m_velocity.setY(-2);
            break;
        case 2:
            m_velocity.setX(2);
            break;
        case 3:
            m_velocity.setX(-2);
            break;
        default:
            m_velocity.setX(0);
            break;
    }
}

void Enemy::setPlayerPos(Vector2D& pos) {
    playerPos = &pos;
}
