#ifndef __GameState__
#define __GameState__

#include <string>

using namespace std;

class GameState {
public:
    virtual void update() = 0;
    virtual void render() = 0;

    virtual bool onEnter() = 0;
    virtual bool onExit() = 0;

    virtual string getStateId() const = 0;
};

#endif // __GameState__
