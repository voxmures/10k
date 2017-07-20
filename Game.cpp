#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {
    // Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

    // Create window
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if(m_pWindow == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    // Create renderer for window
    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (m_pRenderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    // Initialize renderer color
    SDL_SetRenderDrawColor(m_pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    // Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return false;
    }

    if(!m_textureManager.load("img/sonic_spritesheet.png", "sonic", m_pRenderer)) {
        printf("Unable to load media!");
        return false;
    }

    m_bRunning = true;
    return true;
}

void Game::render() {
    SDL_RenderClear(m_pRenderer); // Clear the renderer to the draw color

    m_textureManager.draw("sonic", 0, 0, 24, 38, m_pRenderer);
    m_textureManager.drawFrame("sonic", 100, 100, 24, 38, 1, m_currentFrame, m_pRenderer);

    SDL_RenderPresent(m_pRenderer); // Draw to the screen
}

void Game::update() {
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Game::handleEvents() {
    SDL_Event e;
    if(SDL_PollEvent(&e)) {
        // Users requests quit
        if (e.type == SDL_QUIT) {
            m_bRunning = false;
        }
    }
}

void Game::clean() {
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    IMG_Quit();
    SDL_Quit();
}