#include "MenuButtonContainer.h"
#include "InputHandler.h"

void MenuButtonContainer::addButton(MenuButton* button) {
    m_menuButtons.push_back(button);
}

void MenuButtonContainer::update() {
    int tempSelectedIndex = selectedIndex;
    handleInput();

    if (tempSelectedIndex != selectedIndex) {
        m_menuButtons[tempSelectedIndex]->setState(false);
        m_menuButtons[selectedIndex]->setState(true);
    }
}

void MenuButtonContainer::draw() {
    for (int i = 0; i < m_menuButtons.size(); ++i) {
        m_menuButtons[i]->draw();
    }
}

void MenuButtonContainer::clean() {
    for (int i = 0; i < m_menuButtons.size(); ++i) {
        m_menuButtons[i]->clean();
    }
}

void MenuButtonContainer::handleInput() {
    if (TheInputHandler::Instance()->joysticksInitialised()) {
        if (TheInputHandler::Instance()->yvalue(0, 1) > 0) {
            selectedIndex += 1;
            if (selectedIndex == m_menuButtons.size()) {
                selectedIndex = 0;
            }
        }
        if (TheInputHandler::Instance()->yvalue(0, 1) < 0) {
            selectedIndex -= 1;
            if (selectedIndex < 0) {
                selectedIndex = m_menuButtons.size() - 1;
            }
        }
    }

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN) && m_bReleased) {
        m_menuButtons[selectedIndex]->doAction();
        m_bReleased = false;
    }
    else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP) && m_bReleased) {
        selectedIndex -= 1;
        if (selectedIndex < 0) {
            selectedIndex = m_menuButtons.size() - 1;
        }
        m_bReleased = false;
    }
    else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN) && m_bReleased) {
        selectedIndex += 1;
        if (selectedIndex == m_menuButtons.size()) {
            selectedIndex = 0;
        }
        m_bReleased = false;
    }
    else if (!TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN) &&
             !TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP) &&
             !TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
        m_bReleased = true;
    }
}
