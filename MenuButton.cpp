#include "MenuButton.h"
#include "InputHandler.h"

MenuButton::MenuButton() : SDLGameObject() {}

void MenuButton::load(const LoaderParams* pParams) {
    SDLGameObject::load(pParams);
    m_callbackId = pParams->getCallbackId();
    m_currentFrame = pParams->selected();
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


