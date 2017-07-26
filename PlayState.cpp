#include "PlayState.h"

#include <stdio.h>

#include "InputHandler.h"
#include "TextureManager.h"
#include "Game.h"

#include "PauseState.h"
#include "GameOverState.h"
#include "Player.h"
#include "Enemy.h"
#include "Vector2D.h"

const string PlayState::s_playId = "PLAY";

void PlayState::update() {
//    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
//        TheGame::Instance()->getGameStateMachine()->pushState(new PauseState());
//    }
//
//    hub.updateInformation();
//    for (int i = 0; i < m_gameObjects.size(); i++) {
//        m_gameObjects[i]->update();
//    }
//
//    if (hub.checkCollision()) {
//        TheGame::Instance()->getGameStateMachine()->changeState(new GameOverState());
//    }
}

void PlayState::render() {
    for (int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->draw();
    }
}

bool PlayState::onEnter() {
//    if (!TheTextureManager::Instance()->load("assets/sonic_spritesheet.png", "sonic",
//        TheGame::Instance()->getRenderer())) {
//            return false;
//        }
//
//    if (!TheTextureManager::Instance()->load("assets/robotnic.png", "robotnic",
//        TheGame::Instance()->getRenderer())) {
//            return false;
//        }
//
//    GameObject* player = new Player(new LoaderParams(100, 100, 26, 35, "sonic"));
//
//    GameObject* enemy = new Enemy(new LoaderParams(200, 200, 90, 55, "robotnic"));
//
//    hub.init(dynamic_cast<Player*>(player), dynamic_cast<Enemy*>(enemy));
//
//    m_gameObjects.push_back(player);
//    m_gameObjects.push_back(enemy);

    printf("Entering PlayState\n");
    return true;
}

bool PlayState::onExit() {
    for(int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();
    TheTextureManager::Instance()->clearFromTextureMap("sonic");

    printf("Exiting PlayState\n");
    return true;
}

