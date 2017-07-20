#ifndef __Game__
#define __Game__

#include "TextureManager.h"

class Game {
public:
    Game() {}
    ~Game() {}

    // Simply set the running variable to true
    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);

    void render();
    void update();
    void handleEvents();
    void clean();

    bool running() { return m_bRunning; }

private:

    // The window we'll be rendering to and its renderer
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;

    // Texture Manager instance
    int m_currentFrame;

    bool m_bRunning;
};

#endif // __Game__
