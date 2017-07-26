#ifndef __MenuState__
#define __MenuState__

#include <vector>
#include "GameState.h"
#include "MenuButton.h"

using namespace std;

class MenuState : public GameState {
public:
    void update();
    void render();

    virtual bool onEnter();
    virtual bool onExit();

protected:
    typedef void(*Callback)();
    virtual void setCallbacks(const vector<Callback>& callbacks) = 0;
    vector<Callback> m_callbacks;

    vector<GameObject*> m_gameObjects;
    vector<string> m_textureIdList;

private:
    void initMenuButtons();

    vector<MenuButton*> m_menuButtons;
    int selectedIndex;

    bool m_bReleased;
    void handleInput();
};

#endif // __MenuState__
