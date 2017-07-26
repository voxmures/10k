#include "GameOverState.h"

#include <stdio.h>
#include "Game.h"
#include "TextureManager.h"

#include "StateParser.h"
#include "MainMenuState.h"
#include "PlayState.h"

const string GameOverState::s_gameOverId = "GAMEOVER";

bool GameOverState::onEnter() {
    StateParser stateParser;
    if (!stateParser.parseState("config.xml", s_gameOverId, &m_gameObjects, &m_textureIdList)) {
        cerr << "Unable to parse the state '" << s_gameOverId << "'!" << endl;
        return false;
    }

    m_callbacks.push_back(0); // callbackId starts from 1
    m_callbacks.push_back(s_gameOverToMain);
    m_callbacks.push_back(s_retryPlay);

    MenuState::onEnter();

    printf("Entering GameOverState\n");
    return true;
}

bool GameOverState::onExit() {
    printf("Exiting GameOverState\n");
    return MenuState::onExit();
}

void GameOverState::s_gameOverToMain() {
    TheGame::Instance()->getGameStateMachine()->changeState(new MainMenuState());
}

void GameOverState::s_retryPlay() {
    TheGame::Instance()->getGameStateMachine()->changeState(new PlayState());
}


