#include "PlayState.h"

#include <stdio.h>

#include "TextureManager.h"
#include "Game.h"

#include "Player.h"

const string PlayState::s_playId = "PLAY";

void PlayState::update() {
    printf("HOLA QUE PASA!");
    for (int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->update();
    }
}

void PlayState::render() {
    for (int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->draw();
    }
}

bool PlayState::onEnter() {
    if (!TheTextureManager::Instance()->load("assets/sonic_spritesheet.png", "sonic",
        TheGame::Instance()->getRenderer())) {
            return false;
        }

    GameObject* player = new Player(new LoaderParams(100, 100, 26, 35, "sonic"));

    m_gameObjects.push_back(player);

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

