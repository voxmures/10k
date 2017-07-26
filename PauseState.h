#ifndef __PauseState__
#define __PauseState__

#include <vector>
#include "MenuState.h"
#include "GameObject.h"

using namespace std;

class PauseState : public MenuState {
public:
    bool onEnter();
    bool onExit();

    string getStateId() const { return s_pauseId; }

private:
    static const string s_pauseId;

    // callback functions for menu items
    static void s_pauseToMain();
    static void s_resumePlay();
};

#endif // __PauseState__

