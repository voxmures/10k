#include <stdio.h>
#include "Game.h"

// Our game object
Game* g_game = 0;

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]) {
    g_game = new Game();

    g_game->init("10k", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    while(g_game->running()) {
        g_game->handleEvents();
        g_game->update();
        g_game->render();
    }
    g_game->clean();

	return 0;
}
