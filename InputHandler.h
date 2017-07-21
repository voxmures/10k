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

    bool getButtonState(int joy, int buttonNumber);

    bool joysticksInitialised() {
        return m_bJoysticksInitialised;
    }

    bool isKeyDown(SDL_Scancode key);

    void update();
    void clean();

private:
    InputHandler() {}
    ~InputHandler() {}

    const int m_joystickDeadZone = 10000;

    vector<SDL_Joystick*> m_joysticks;
    vector< pair<Vector2D*, Vector2D*> > m_joystickValues;
    vector< vector<bool> > m_buttonStates;
    bool m_bJoysticksInitialised;

    const Uint8* m_keystates;

    // Keyboard handlers
    void onKeyDown();
    void onKeyUp();

    // Joystick handlers
    void onJoystickAxisMove(SDL_Event& e);
    void onJoystickButtonDown(SDL_Event& e);
    void onJoystickButtonUp(SDL_Event& e);
};

typedef InputHandler TheInputHandler;

#endif // __InputHandler
