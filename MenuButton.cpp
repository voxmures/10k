#include "MenuButton.h"
#include "InputHandler.h"

MenuButton::MenuButton(const LoaderParams* pParams, void (*callback)()) : SDLGameObject(pParams), m_callback(callback) {
    m_currentFrame = IDLE;
}

void MenuButton::draw() {
    SDLGameObject::draw();
}

void MenuButton::update() {
    SDLGameObject::update();
}

void MenuButton::clean() {
    SDLGameObject::clean();
}

void MenuButton::setState(bool selected) {
    m_currentFrame = (int)selected;
}


