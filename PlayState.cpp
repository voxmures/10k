#include "PlayState.h"
#include <stdio.h>

const string PlayState::s_playId = "PLAY";

void PlayState::update() {}

void PlayState::render() {}

bool PlayState::onEnter() {
    printf("Entering PlayState\n");
    return true;
}

bool PlayState::onExit() {
    printf("Exiting PlayState\n");
    return true;
}

