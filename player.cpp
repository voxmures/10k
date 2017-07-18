#include "player.hpp"

Player::Player() {
    // Initialize the position of the player
    mPosX = 50;
    mPosY = 50;
}

int Player::getPosX() {
    return mPosX;
}

int Player::getPosY() {
    return mPosY;
}

void Player::move(int direction) {
    switch (direction) {
        case UP:
            mPosY -= PLAYER_SPEED; break;
        case DOWN:
            mPosY += PLAYER_SPEED; break;
        case LEFT:
            mPosX -= PLAYER_SPEED; break;
        case RIGHT:
            mPosX += PLAYER_SPEED; break;
    }
}

LTexture* Player::getTexture() {
    return &mTexture;
}

void Player::setTexture(LTexture texture) {
    mTexture = texture;
}
