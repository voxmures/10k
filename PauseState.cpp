#include "PauseState.h"

#include <stdio.h>
#include "Game.h"
#include "TextureManager.h"

#include "MainMenuState.h"
#include "StateParser.h"

const string PauseState::s_pauseId = "PAUSE";

bool PauseState::onEnter() {
    StateParser stateParser;
    if (!stateParser.parseState("config.xml", s_pauseId, &m_gameObjects, &m_textureIdList)) {
        cerr << "Unable to parse the state '" << s_pauseId << "'!" << endl;
        return false;
    }

    m_callbacks.push_back(0); // callbackId starts from 1
    m_callbacks.push_back(s_pauseToMain);
    m_callbacks.push_back(s_resumePlay);

    setCallbacks(m_callbacks);

    MenuState::onEnter();

    printf("Entering PauseState\n");
    return true;
}

bool PauseState::onExit() {
    printf("Exiting PauseState\n");
    return MenuState::onExit();
}

void PauseState::s_pauseToMain() {
    TheGame::Instance()->getGameStateMachine()->changeState(new MainMenuState());
}

void PauseState::s_resumePlay() {
    TheGame::Instance()->getGameStateMachine()->popState();
}

