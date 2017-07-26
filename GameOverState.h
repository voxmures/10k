#ifndef __GameOverState__
#define __GameOverState__

#include <vector>

#include "MenuState.h"
#include "GameObject.h"

using namespace std;

class GameOverState : public MenuState {
public:
    bool onEnter();
    bool onExit();

    string getStateId() const { return s_gameOverId; }

private:
    static const string s_gameOverId;

    // callback functions for menu items
    static void s_gameOverToMain();
    static void s_retryPlay();
};

#endif // __GameOverState__


