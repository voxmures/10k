#include "MenuState.h"
#include "PlayState.h"
#include "Game.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include "MenuButtonContainer.h"
#include <stdio.h>

const string MenuState::s_menuId = "MENU";

void MenuState::update() {
    for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
        m_gameObjects[i]->update();
    }
}

void MenuState::render() {
    for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
        m_gameObjects[i]->draw();
    }
}

bool MenuState::onEnter() {
    if (!TheTextureManager::Instance()->load("assets/play.png",
        "playbutton", TheGame::Instance()->getRenderer())) {
            return false;
        }

    if (!TheTextureManager::Instance()->load("assets/exit.png",
        "exitbutton", TheGame::Instance()->getRenderer())) {
            return false;
        }


    MenuButton* button1 = new MenuButton(new LoaderParams(100, 100, 400, 100, "playbutton"), s_menuToPlay);
    button1->setState(true);
    MenuButton* button2 = new MenuButton(new LoaderParams(100, 300, 400, 100, "exitbutton"), s_exitFromMenu);

    MenuButtonContainer* menuButtonContainer = new MenuButtonContainer();

    menuButtonContainer->addButton(button1);
    menuButtonContainer->addButton(button2);

    m_gameObjects.push_back(menuButtonContainer);

    printf("Entering MenuState\n");
    return true;
}

bool MenuState::onExit() {
    for (int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();

    TheTextureManager::Instance()->clearFromTextureMap("playbutton");
    TheTextureManager::Instance()->clearFromTextureMap("exitbutton");
    printf("Exiting MenuState\n");
    return true;
}

void MenuState::s_menuToPlay() {
    printf("Play button pressed!\n");
    TheGame::Instance()->getGameStateMachine()->changeState(new PlayState());
}

void MenuState::s_exitFromMenu() {
    printf("Exit button pressed!\n");
    TheGame::Instance()->quit();
}
