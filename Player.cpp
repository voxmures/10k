#include "Player.h"

void Player::load(int x, int y, int width, int height, string textureId) {
    GameObject::load(x, y, width, height, textureId);
}

void Player::draw(SDL_Renderer* pRenderer) {
    GameObject::draw(pRenderer);
}

void Player::update() {
    m_x -= 1;
}

void Player::clean() {}
