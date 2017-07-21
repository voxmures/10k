#ifndef __PlayState__
#define __PlayState__

#include "GameState.h"

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
};

#endif // __PlayState__
