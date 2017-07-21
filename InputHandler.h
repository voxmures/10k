#ifndef __InputHandler
#define __InputHandler

#ifdef __linux__
    //linux code goes here
	#include <SDL2/SDL.h>
#elif _WIN32
	//windows code goes here
	#include <SDL.h>
#endif

#include <stdio.h>
#include <vector>
#include "Vector2D.h"

using namespace std;

class InputHandler {
    static InputHandler* s_pInstance;

public:
    static InputHandler* Instance() {
        if (s_pInstance == 0) {
            s_pInstance = new InputHandler();
        }
        return s_pInstance;
    }

    void initialiseJoysticks();

    int xvalue(int joy, int stick);
    int yvalue(int joy, int stick);

    bool joysticksInitialised() {
        return m_bJoysticksInitialised;
    }

    void update();
    void clean();

private:
    const int m_joystickDeadZone = 10000;

    InputHandler() {}
    ~InputHandler() {}

    vector<SDL_Joystick*> m_joysticks;
    vector< pair<Vector2D*, Vector2D*> > m_joystickValues;
    bool m_bJoysticksInitialised;
};

typedef InputHandler TheInputHandler;

#endif // __InputHandler
