#include "Player.h"

#ifdef __linux__
    //linux code goes here
	#include <SDL2/SDL.h>
#elif _WIN32
	//windows code goes here
	#include <SDL.h>
#endif

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::draw() {
    SDLGameObject::draw();
}

void Player::update() {
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

    m_acceleration.setX(1);

    SDLGameObject::update();
}

void Player::clean() {}
