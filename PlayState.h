#ifndef __PlayState__
#define __PlayState__

#include <vector>

#include "GameObject.h"
#include "GameState.h"
#include "AgentsHub.h"

using namespace std;

class PlayState : public GameState {
public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual string getStateId() const { return s_playId; }

private:
    static const string s_playId;

    vector<GameObject*> m_gameObjects;
    AgentsHub hub;
};

#endif // __PlayState__
