#ifndef __Game__
#define __Game__

#ifdef __linux__
    //linux code goes here
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_image.h>
#elif _WIN32
	//windows code goes here
	#include <SDL.h>
	#include <SDL_image.h>
#endif

#include <vector>
#include "GameObject.h"

using namespace std;

class Game {
    static Game* s_pInstance;

public:
    static Game* Instance() {
        if (s_pInstance == 0) {
            s_pInstance = new Game();
            return s_pInstance;
        }
        return s_pInstance;
    }

    // Simply set the running variable to true
    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);

    void render();
    void update();
    void handleEvents();
    void clean();

    bool running() { return m_bRunning; }

    SDL_Renderer* getRenderer() const { return m_pRenderer; }

private:
    Game() {}

    // The window we'll be rendering to and its renderer
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;

    vector<GameObject*> m_gameObjects;

    bool m_bRunning;
};

typedef Game TheGame;

#endif // __Game__
