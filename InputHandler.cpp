#include "InputHandler.h"
#include "Game.h"

InputHandler* InputHandler::s_pInstance = 0;

void InputHandler::initialiseJoysticks() {
    if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0) {
        SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    }

    m_bJoysticksInitialised = false;

    if (SDL_NumJoysticks() > 0) {
        for (int i = 0; i < SDL_NumJoysticks(); i++) {
            SDL_Joystick* joy = SDL_JoystickOpen(i);
            if (joy) {
                m_joysticks.push_back(joy);
                m_joystickValues.push_back(make_pair(new Vector2D(0, 0), new Vector2D(0, 0)));

                vector<bool> tempButtons;
                for (int j = 0; j < SDL_JoystickNumButtons(joy); j++) {
                    tempButtons.push_back(false);
                }
                m_buttonStates.push_back(tempButtons);
            } else {
                printf("Unable to open the joystick with index %i! SDL Error: %s\n", i, SDL_GetError());
            }
        }

        printf("Initialised %i joystick(s)", m_joysticks.size());

        SDL_JoystickEventState(SDL_ENABLE);
        m_bJoysticksInitialised = true;
    }
}

int InputHandler::xvalue(int joy, int stick) {
    if (m_joystickValues.size() > 0) {
        if (stick == 1) {
            return m_joystickValues[joy].first->getX();
        }
        else if (stick == 2) {
            return m_joystickValues[joy].second->getX();
        }
    }
    return 0;
}

int InputHandler::yvalue(int joy, int stick) {
    if (m_joystickValues.size() > 0) {
        if (stick == 1) {
            return m_joystickValues[joy].first->getY();
        }
        else if (stick == 2) {
            return m_joystickValues[joy].second->getY();
        }
    }
    return 0;
}

bool InputHandler::getButtonState(int joy, int buttonNumber) {
    if (m_buttonStates.size() > 0) {
        return m_buttonStates[joy][buttonNumber];
    }
    return false;
}

bool InputHandler::isKeyDown(SDL_Scancode key) {
    if (m_keystates != 0) {
        return m_keystates[key];
    }
    return false;
}

void InputHandler::update() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        m_keystates = SDL_GetKeyboardState(0);
        switch(e.type) {
            case SDL_QUIT:
                TheGame::Instance()->quit(); break;

            case SDL_JOYAXISMOTION:
                onJoystickAxisMove(e); break;

            case SDL_JOYBUTTONDOWN:
                onJoystickButtonDown(e); break;

            case SDL_JOYBUTTONUP:
                onJoystickButtonUp(e); break;

            case SDL_KEYDOWN:
                onKeyDown(); break;

            case SDL_KEYUP:
                onKeyUp(); break;

            default:
                break;
        }
    }
}

void InputHandler::clean() {
    if (m_bJoysticksInitialised) {
        for (int i = 0; i < SDL_NumJoysticks(); i++) {
            SDL_JoystickClose(m_joysticks[i]);
        }
    }
}

void InputHandler::onKeyUp() {

}

void InputHandler::onKeyDown() {

}

void InputHandler::onJoystickAxisMove(SDL_Event& e) {
    int whichOne = e.jaxis.which;

    // Left stick move left or right
    if (e.jaxis.axis == 0) {
        if (e.jaxis.value > m_joystickDeadZone)
            m_joystickValues[whichOne].first->setX(1);
        else if (e.jaxis.value < -m_joystickDeadZone)
            m_joystickValues[whichOne].first->setX(-1);
        else
            m_joystickValues[whichOne].first->setX(0);
    }

    // Left stick move up or down
    if (e.jaxis.axis == 1) {
        if (e.jaxis.value > m_joystickDeadZone)
            m_joystickValues[whichOne].first->setY(1);
        else if (e.jaxis.value < -m_joystickDeadZone)
            m_joystickValues[whichOne].first->setY(-1);
        else
            m_joystickValues[whichOne].first->setY(0);
    }

    // Right stick move left or right
    if (e.jaxis.axis == 3) {
        if (e.jaxis.value > m_joystickDeadZone)
            m_joystickValues[whichOne].second->setX(1);
        else if (e.jaxis.value < -m_joystickDeadZone)
            m_joystickValues[whichOne].second->setX(-1);
        else
            m_joystickValues[whichOne].second->setX(0);
    }

    // Right stick move up or down
    if (e.jaxis.axis == 4) {
        if (e.jaxis.value > m_joystickDeadZone)
            m_joystickValues[whichOne].second->setY(1);
        else if (e.jaxis.value < -m_joystickDeadZone)
            m_joystickValues[whichOne].second->setY(-1);
        else
            m_joystickValues[whichOne].second->setY(0);
    }
}

void InputHandler::onJoystickButtonDown(SDL_Event& e) {
    int whichOne = e.jaxis.which;
    m_buttonStates[whichOne][e.jbutton.button] = true;
}

void InputHandler::onJoystickButtonUp(SDL_Event& e) {
    int whichOne = e.jaxis.which;
    m_buttonStates[whichOne][e.jbutton.button] = false;
}
