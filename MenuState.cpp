#include "MenuState.h"

#include <iostream>
#include "InputHandler.h"
#include "TextureManager.h"

int selectedIndex = 0;
bool m_bReleased = false;

void MenuState::update() {
    int tempSelectedIndex = selectedIndex;
    handleInput();

    if (tempSelectedIndex != selectedIndex) {
        m_menuButtons[tempSelectedIndex]->setState(false);
        m_menuButtons[selectedIndex]->setState(true);
    }

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN) && m_bReleased) {
        m_menuButtons[selectedIndex]->doAction();
        m_bReleased = false;
    }
}

void MenuState::render() {
    for (int i = 0; i != m_gameObjects.size(); i++) {
        m_gameObjects[i]->draw();
    }
}

bool MenuState::onEnter() {
    initMenuButtons();
    return true;
}

bool MenuState::onExit() {
    for (int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();
    m_menuButtons.clear();

    for (int i = 0; i < m_textureIdList.size(); i++) {
        TheTextureManager::Instance()->clearFromTextureMap(m_textureIdList[i]);
    }
    m_textureIdList.clear();

    m_callbacks.clear();

    return true;
}

void MenuState::initMenuButtons() {
    for (int i = 0; i < m_gameObjects.size(); i++) {
        if (dynamic_cast<MenuButton*>(m_gameObjects[i])) {
            MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
            pButton->setCallback(m_callbacks[pButton->getCallbackId()]);
            m_menuButtons.push_back(pButton);
        }
    }
}

void MenuState::handleInput() {
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

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP) && m_bReleased) {
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
