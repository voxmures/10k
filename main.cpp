#include <stdio.h>
#include "Game.h"

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Fixed FPS constants
const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* args[]) {

    Uint32 frameStart, frameTime;

    if(!TheGame::Instance()->init("10k", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN)) {
        printf("Unable to init the game! SDL Error: %s\n", SDL_GetError());
        return -1;
    }

    while(TheGame::Instance()->running()) {
        frameStart = SDL_GetTicks();

        TheGame::Instance()->handleEvents();
        TheGame::Instance()->update();
        TheGame::Instance()->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameTime < DELAY_TIME) {
            SDL_Delay((int)(DELAY_TIME - frameTime));
        }
    }
    TheGame::Instance()->clean();

	return 0;
}
