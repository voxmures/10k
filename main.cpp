// Using SDL and standard IO
#ifdef __linux__ 
    //linux code goes here
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_image.h>
#elif _WIN32
	//windows code goes here 
	#include <SDL.h>
	#include <SDL_image.h>
#endif

#include <stdio.h>
#include <string>

//#include "ltexture.hpp"
#include "player.hpp"

using namespace std;

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Loads individual image as texture
SDL_Texture* loadTexture(string path);

// The window we'll be rendering to
SDL_Window* gWindow = NULL;

// The window renderer
SDL_Renderer* gRenderer = NULL;

// Player
Player player;

// Sprite texture
LTexture gSpriteSheetTexture;

// Current animation frame
int frame = 0;

const int IDLE_ANIMATION_FRAMES = 6;
SDL_Rect gSpriteClips[IDLE_ANIMATION_FRAMES];

bool init() {
    // Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

    // Create window
    gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(gWindow == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    // Create renderer for window
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (gRenderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    // Initialize renderer color
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    // Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return false;
    }

    return true;
}

bool loadMedia() {

    // Set renderer to LTexture object
    gSpriteSheetTexture.setRenderer(gRenderer);

    // Load Spritesheet texture
    if (!gSpriteSheetTexture.loadFromFile("img/sonic_spritesheet.png")) {
        printf("Failed to load texture image\n");
        return false;
    }


    player.setTexture(gSpriteSheetTexture);

    int acum = 0;
    for (int i = 0; i < IDLE_ANIMATION_FRAMES; i++) {
        gSpriteClips[i].x = acum;
        gSpriteClips[i].y = 0;
        gSpriteClips[i].w = player.SPRITE_WIDTH;
        gSpriteClips[i].h = player.SPRITE_HEIGHT;

        acum += player.SPRITE_WIDTH + i;
    }

    return true;
}

void close() {
    // Free loaded images
    player.getTexture().free();
    //player.setTexture();

    // Destroy window
    SDL_DestroyRenderer(gRenderer);
    gRenderer = NULL;
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    // Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

void paint() {
    // Clear screen
	SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear(gRenderer);

    //Render current frame
    SDL_Rect* currentClip = &gSpriteClips[frame / 6];
    player.getTexture().render(player.getPosX(), player.getPosY(), currentClip);

    //Update screen
    SDL_RenderPresent(gRenderer);

    // Go to next frame
    ++frame;

    //Cycle animation
    if (frame / 6 >= IDLE_ANIMATION_FRAMES) {
        frame = 0;
    }

	//SDL_UpdateWindowSurface(gWindow);
	//printf("Update frame");

}

int main(int argc, char* args[]) {
    // Start up SDL and create window
    if (!init()) {
        printf("Failed to initialize!\n");
        return 1;
    }

    // Load media
    if (!loadMedia()) {
        printf("Failed to load media!\n");
        return 1;
    }

    bool alive = true;

    // Event handler
    SDL_Event e;

    while (alive) {

        // Handle events on queue
        while(SDL_PollEvent(&e) != 0) {
            // Users requests quit
            if (e.type == SDL_QUIT) {
                alive = false;
            }
        }

        // Paint the scene
        paint();
    }

	close();

	return 0;
}
