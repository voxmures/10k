#ifndef __PauseState__
#define __PauseState__

#include <vector>

#include "GameState.h"
#include "GameObject.h"

using namespace std;

class PauseState : public GameState {
public:
    PauseState() {};

    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual string getStateId() const { return s_pauseId; }

private:
    static const string s_pauseId;

    vector<GameObject*> m_gameObjects;

    // callback functions for menu items
    static void s_pauseToMain();
    static void s_resumePlay();
};

#endif // __PauseState__

