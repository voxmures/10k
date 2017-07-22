#include "Game.h"

#ifdef __linux__
    //linux code goes here
	#include <SDL2/SDL_image.h>
#elif _WIN32
	//windows code goes here
	#include <SDL_image.h>
#endif

#include <stdio.h>

#include "MenuState.h"
#include "PlayState.h"
#include "Player.h"
#include "Enemy.h"
#include "TextureManager.h"
#include "InputHandler.h"

Game* Game::s_pInstance = 0;

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

//    if(!TheTextureManager::Instance()->load("img/sonic_spritesheet.png", "sonic", m_pRenderer)) {
//        printf("Unable to load media!");
//        return false;
//    }

//    m_gameObjects.push_back(new Player(new LoaderParams(300, 300, 24, 38, "sonic")));
//    m_gameObjects.push_back(new Enemy(new LoaderParams(0, 0, 24, 38, "sonic")));

    TheInputHandler::Instance()->initialiseJoysticks();

    m_pGameStateMachine = new GameStateMachine();
    m_pGameStateMachine->changeState(new MenuState());

    m_bRunning = true;
    return true;
}

void Game::render() {
    SDL_RenderClear(m_pRenderer); // Clear the renderer to the draw color

    m_pGameStateMachine->render();

    SDL_RenderPresent(m_pRenderer); // Draw to the screen
}

void Game::update() {
    m_pGameStateMachine->update();
}

void Game::handleEvents() {
    TheInputHandler::Instance()->update();
}

void Game::clean() {
    TheInputHandler::Instance()->clean();

    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    IMG_Quit();
    SDL_Quit();
}

void Game::quit() {
    m_bRunning = false;
}
