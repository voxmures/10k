#include "MenuButton.h"
#include "InputHandler.h"

MenuButton::MenuButton(const LoaderParams* pParams) : SDLGameObject(pParams) {
    m_currentFrame = IDLE;
}

void MenuButton::draw() {
    SDLGameObject::draw();
}

void MenuButton::update() {
    handleInput();

    SDLGameObject::update();
}

void MenuButton::clean() {
    SDLGameObject::clean();
}

void MenuButton::handleInput() {
    if (TheInputHandler::Instance()->joysticksInitialised()) {
        if (TheInputHandler::Instance()->yvalue(0, 1) > 0) {
            nextButton->setSelected();
            m_currentFrame = IDLE;
        }
        if (TheInputHandler::Instance()->yvalue(0, 1) < 0) {
            prevButton->setSelected();
            m_currentFrame = IDLE;
        }
    }

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
        prevButton->setSelected();
        m_currentFrame = IDLE;
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
        nextButton->setSelected();
        m_currentFrame = IDLE;
    }
}
