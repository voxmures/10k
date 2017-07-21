#ifndef __GameStateMachine__
#define __GameStateMachine__

#include "GameState.h"
#include <vector>

using namespace std;

class GameStateMachine {
public:
    void update();
    void render();

    void pushState(GameState* pState);
    void changeState(GameState* pState);
    void popState();

private:
    vector<GameState*> m_gameStates;
};

#endif // __GameStateMachine__
