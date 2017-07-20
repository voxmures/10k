#include <stdio.h>
#include "Game.h"

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]) {

    if(!TheGame::Instance()->init("10k", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN)) {
        printf("Unable to init the game! SDL Error: %s\n", SDL_GetError());
        return -1;
    }

    while(TheGame::Instance()->running()) {
        TheGame::Instance()->handleEvents();
        TheGame::Instance()->update();
        TheGame::Instance()->render();

        SDL_Delay(10);
    }
    TheGame::Instance()->clean();

	return 0;
}
