#ifndef __MainMenuState__
#define __MainMenuState__

#include <vector>

#include "MenuState.h"
#include "GameObject.h"

using namespace std;

class MainMenuState : public MenuState {
public:
    bool onEnter();
    bool onExit();

    string getStateId() const { return s_menuId; }

private:
    static const string s_menuId;

    void setCallbacks(const vector<Callback>& callbacks);

    // callback functions for menu items
    static void s_menuToPlay();
    static void s_exitFromMenu();
};

#endif // __MainMenuState__
