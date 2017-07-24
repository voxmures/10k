#include "PauseState.h"

#include <stdio.h>
#include "Game.h"
#include "TextureManager.h"

#include "MenuState.h"
#include "MenuButton.h"
#include "MenuButtonContainer.h"

const string PauseState::s_pauseId = "PAUSE";

void PauseState::update() {
    int nObjects = m_gameObjects.size();
    int i = 0;
    while(i < nObjects) {
        m_gameObjects[i]->update();
        nObjects = m_gameObjects.size();
        ++i;
    }
}

void PauseState::render() {
    for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
        m_gameObjects[i]->draw();
    }
}

bool PauseState::onEnter() {
    if (!TheTextureManager::Instance()->load("assets/main_menu.png",
        "mainbutton", TheGame::Instance()->getRenderer())) {
            return false;
        }

    if (!TheTextureManager::Instance()->load("assets/resume.png",
        "resumebutton", TheGame::Instance()->getRenderer())) {
            return false;
        }


    MenuButton* button1 = new MenuButton(new LoaderParams(100, 100, 400, 100, "mainbutton"), s_pauseToMain);
    button1->setState(true);
    MenuButton* button2 = new MenuButton(new LoaderParams(100, 300, 400, 100, "resumebutton"), s_resumePlay);

    MenuButtonContainer* menuButtonContainer = new MenuButtonContainer();

    menuButtonContainer->addButton(button1);
    menuButtonContainer->addButton(button2);

    m_gameObjects.push_back(menuButtonContainer);

    printf("Entering PauseState\n");
    return true;
}

bool PauseState::onExit() {
    for (int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();

    TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
    TheTextureManager::Instance()->clearFromTextureMap("resumebutton");

    printf("Exiting PauseState\n");
    return true;
}

void PauseState::s_pauseToMain() {
    TheGame::Instance()->getGameStateMachine()->changeState(new MenuState());
}

void PauseState::s_resumePlay() {
    TheGame::Instance()->getGameStateMachine()->popState();
}

