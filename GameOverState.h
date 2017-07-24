#ifndef __GameOverState__
#define __GameOverState__

#include <vector>

#include "GameState.h"
#include "GameObject.h"

using namespace std;

class GameOverState : public GameState {
public:
    GameOverState() {};

    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual string getStateId() const { return s_gameOverId; }

private:
    static const string s_gameOverId;

    vector<GameObject*> m_gameObjects;

    // callback functions for menu items
    static void s_gameOverToMain();
    static void s_retryPlay();
};

#endif // __GameOverState__


