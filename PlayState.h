#ifndef __PlayState__
#define __PlayState__

#include <vector>

#include "GameObject.h"
#include "GameState.h"
#include "AgentsHub.h"
#include "Level.h"

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
    vector<string> m_textureIdList;
    AgentsHub hub;

    Level* pLevel;
};

#endif // __PlayState__
