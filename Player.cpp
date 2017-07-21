#include "Player.h"

#ifdef __linux__
    //linux code goes here
	#include <SDL2/SDL.h>
#elif _WIN32
	//windows code goes here
	#include <SDL.h>
#endif

#include "InputHandler.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::draw() {
    SDLGameObject::draw();
}

void Player::update() {
    m_velocity.setX(0);
    m_velocity.setY(0);

    handleInput();

    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

    SDLGameObject::update();
}

void Player::clean() {}

void Player::handleInput() {
    if (TheInputHandler::Instance()->joysticksInitialised()) {
        if (TheInputHandler::Instance()->xvalue(0, 1) > 0 ||
            TheInputHandler::Instance()->xvalue(0, 1) < 0) {
                m_velocity.setX(1 * TheInputHandler::Instance()->xvalue(0, 1));
            }

        if (TheInputHandler::Instance()->yvalue(0, 1) > 0 ||
            TheInputHandler::Instance()->yvalue(0, 1) < 0) {
                m_velocity.setY(1 * TheInputHandler::Instance()->yvalue(0, 1));
            }

        if (TheInputHandler::Instance()->xvalue(0, 2) > 0 ||
            TheInputHandler::Instance()->xvalue(0, 2) < 0) {
                m_velocity.setX(1 * TheInputHandler::Instance()->xvalue(0, 2));
            }

        if (TheInputHandler::Instance()->yvalue(0, 2) > 0 ||
            TheInputHandler::Instance()->yvalue(0, 2) < 0) {
                m_velocity.setY(1 * TheInputHandler::Instance()->yvalue(0, 2));
            }
    }
}
