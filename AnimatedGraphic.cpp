#include "AnimatedGraphic.h"

#ifdef __linux__
    //linux code goes here
	#include <SDL2/SDL.h>
#elif _WIN32
	//windows code goes here
	#include <SDL.h>
#endif

#include "InputHandler.h"

AnimatedGraphic::AnimatedGraphic() : SDLGameObject() {}

void AnimatedGraphic::load(const LoaderParams* pParams) {
    SDLGameObject::load(pParams);
    m_currentFrame = 0;
    m_animSpeed = pParams->getAnimSpeed();
}

void AnimatedGraphic::draw() {
    SDLGameObject::draw();
}

void AnimatedGraphic::update() {
    m_currentFrame = 0;
    //m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) % m_numFrames));
}

void AnimatedGraphic::clean() {
    SDLGameObject::clean();
}
