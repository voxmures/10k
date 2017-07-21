#ifndef __MenuState__
#define __MenuState__

#include <vector>

#include "GameState.h"
#include "GameObject.h"

using namespace std;

class MenuState : public GameState {
public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual string getStateId() const { return s_menuId; }

private:
    static const string s_menuId;

    vector<GameObject*> m_gameObjects;
};

#endif // __MenuState__
