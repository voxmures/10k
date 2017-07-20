#ifndef __Game__
#define __Game__

#include <vector>
#include "Player.h"
#include "Enemy.h"

using namespace std;

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

    GameObject* m_go;
    Player* m_player;
    Enemy* m_enemy;

    vector<GameObject*> m_gameObjects;

    bool m_bRunning;
};

#endif // __Game__
