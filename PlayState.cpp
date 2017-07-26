#include "PlayState.h"

#include <stdio.h>

#include "InputHandler.h"
#include "TextureManager.h"
#include "Game.h"
#include "StateParser.h"

#include "PauseState.h"
#include "GameOverState.h"
#include "Player.h"
#include "Enemy.h"
#include "Vector2D.h"
#include "AgentsHub.h"

const string PlayState::s_playId = "PLAY";

void PlayState::update() {
    hub.updateInformation();
    for (int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->update();
    }

    if (hub.checkCollision()) {
        TheGame::Instance()->getGameStateMachine()->changeState(new GameOverState());
    }

    else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
        TheGame::Instance()->getGameStateMachine()->pushState(new PauseState());
    }
}

void PlayState::render() {
    for (int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->draw();
    }
}

bool PlayState::onEnter() {
    StateParser stateParser;
    stateParser.parseState("config.xml", s_playId, &m_gameObjects, &m_textureIdList);

    // Setting agents hub
    Player* player;
    Enemy* enemy;
    for(int i = 0; i < m_gameObjects.size(); i++) {
        if (dynamic_cast<Player*>(m_gameObjects[i])) {
            player = dynamic_cast<Player*>(m_gameObjects[i]);
        }
        else if (dynamic_cast<Enemy*>(m_gameObjects[i])) {
            enemy = dynamic_cast<Enemy*>(m_gameObjects[i]);
        }
    }
    hub.init(player, enemy);

    return true;
}

bool PlayState::onExit() {
    for(int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();

    for (int i = 0; i < m_textureIdList.size(); i++) {
        TheTextureManager::Instance()->clearFromTextureMap(m_textureIdList[i]);
    }
    m_textureIdList.clear();

    printf("Exiting PlayState\n");
    return true;
}

