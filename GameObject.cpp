#include "GameObject.h"

void GameObject::load(int x, int y, int width, int height, string textureId) {
    m_x = x;
    m_y = y;
    m_width = width;
    m_height = height;
    m_textureId = textureId;

    m_currentRow = 1;
    m_currentFrame = 1;
}

void GameObject::draw(SDL_Renderer* pRenderer) {
    TextureManager::Instance()->drawFrame(m_textureId, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, pRenderer);
}

void GameObject::update() {
    m_x += 1;
}

void GameObject::clean() {}
