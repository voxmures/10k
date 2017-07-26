#include "GameOverState.h"

#include <stdio.h>
#include "Game.h"
#include "TextureManager.h"

#include "MainMenuState.h"
#include "PlayState.h"
#include "SDLGameObject.h"
#include "AnimatedGraphic.h"
#include "MenuButton.h"
#include "MenuButtonContainer.h"

const string GameOverState::s_gameOverId = "GAMEOVER";

void GameOverState::update() {
    int nObjects = m_gameObjects.size();
    int i = 0;
    while(i < nObjects) {
        m_gameObjects[i]->update();
        nObjects = m_gameObjects.size();
        ++i;
    }
}

void GameOverState::render() {
    for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
        m_gameObjects[i]->draw();
    }
}

bool GameOverState::onEnter() {
//    if (!TheTextureManager::Instance()->load("assets/gameover.png",
//        "gameover", TheGame::Instance()->getRenderer())) {
//            return false;
//        }
//
//    if (!TheTextureManager::Instance()->load("assets/main_menu.png",
//        "mainbutton", TheGame::Instance()->getRenderer())) {
//            return false;
//        }
//
//    if (!TheTextureManager::Instance()->load("assets/retry.png",
//        "retrybutton", TheGame::Instance()->getRenderer())) {
//            return false;
//        }
//
//    GameObject* gameover = new AnimatedGraphic(new LoaderParams(70, 100, 485, 67, "gameover", 0));
//
//    m_gameObjects.push_back(gameover);
//
//    MenuButton* button1 = new MenuButton(new LoaderParams(100, 180, 400, 100, "mainbutton"), s_gameOverToMain);
//    button1->setState(true);
//    MenuButton* button2 = new MenuButton(new LoaderParams(100, 300, 400, 100, "retrybutton"), s_retryPlay);
//
//    MenuButtonContainer* menuButtonContainer = new MenuButtonContainer();
//
//    menuButtonContainer->addButton(button1);
//    menuButtonContainer->addButton(button2);
//
//    m_gameObjects.push_back(menuButtonContainer);

    printf("Entering GameOverState\n");
    return true;
}

bool GameOverState::onExit() {
    for (int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();

    TheTextureManager::Instance()->clearFromTextureMap("gameover");
    TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
    TheTextureManager::Instance()->clearFromTextureMap("retrybutton");

    printf("Exiting GameOverState\n");
    return true;
}

void GameOverState::s_gameOverToMain() {
    TheGame::Instance()->getGameStateMachine()->changeState(new MainMenuState());
}

void GameOverState::s_retryPlay() {
    TheGame::Instance()->getGameStateMachine()->changeState(new PlayState());
}


