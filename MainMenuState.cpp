#include "MainMenuState.h"

#include <iostream>

#include "Game.h"
#include "TextureManager.h"

#include "StateParser.h"
#include "PlayState.h"
#include "MenuButton.h"

const string MainMenuState::s_menuId = "MENU";

bool MainMenuState::onEnter() {
    StateParser stateParser;
    if (!stateParser.parseState("config.xml", s_menuId, &m_gameObjects, &m_textureIdList)) {
        cerr << "Unable to parse the state '" << s_menuId << "'!" << endl;
        return false;
    };

    m_callbacks.push_back(0); // callbackId starts from 1
    m_callbacks.push_back(s_menuToPlay);
    m_callbacks.push_back(s_exitFromMenu);

    MenuState::onEnter();

    printf("Entering MainMenuState\n");
    return true;
}

bool MainMenuState::onExit() {
    cout << "Exiting MainMenuState" << endl;
    return MenuState::onExit();
}

void MainMenuState::s_menuToPlay() {
    TheGame::Instance()->getGameStateMachine()->changeState(new PlayState());
}

void MainMenuState::s_exitFromMenu() {
    TheGame::Instance()->quit();
}
