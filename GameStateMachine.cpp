#include "GameStateMachine.h"
#include "stdio.h"

bool m_busy = false;

void GameStateMachine::update() {
    if (!m_gameStates.empty())
        m_gameStates.back()->update();
}

void GameStateMachine::render() {
    if (!m_gameStates.empty())
        m_gameStates.back()->render();
}

void GameStateMachine::pushState(GameState* pState) {
    m_gameStates.push_back(pState);
    m_gameStates.back()->onEnter();
}

void GameStateMachine::changeState(GameState* pState) {
    if (!m_gameStates.empty()) {
        if (m_gameStates.back()->getStateId() == pState->getStateId()) {
            return;
        }
        if (m_gameStates.back()->onExit()) {
            delete m_gameStates.back();
            m_gameStates.pop_back();
        }
    }
    m_gameStates.push_back(pState);
    m_gameStates.back()->onEnter();
}

void GameStateMachine::popState() {
    if (!m_gameStates.empty()) {
        if (m_gameStates.back()->onExit()) {
            delete m_gameStates.back();
            m_gameStates.pop_back();
        }
    }
}
