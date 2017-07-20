#include "Enemy.h"

#ifdef __linux__
    //linux code goes here
	#include <SDL2/SDL.h>
#elif _WIN32
	//windows code goes here
	#include <SDL.h>
#endif

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Enemy::draw() {
    SDLGameObject::draw();
}

void Enemy::update() {
    m_position.setX(m_position.getX() + 1);
    m_position.setY(m_position.getY() + 1);
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::clean() {}
