#include "AnimatedGraphic.h"

#ifdef __linux__
    //linux code goes here
	#include <SDL2/SDL.h>
#elif _WIN32
	//windows code goes here
	#include <SDL.h>
#endif

#include "InputHandler.h"

AnimatedGraphic::AnimatedGraphic(const LoaderParams* pParams) : SDLGameObject(pParams) {
    m_currentFrame = 0;
}

void AnimatedGraphic::draw() {
    SDLGameObject::draw();
}

void AnimatedGraphic::update() {}

void AnimatedGraphic::clean() {
    SDLGameObject::clean();
}
