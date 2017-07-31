#include "TileLayer.h"

#include <iostream>

#include "Game.h"
#include "TextureManager.h"

TileLayer::TileLayer(int tileSize, const vector<Tileset>& tilesets) : m_tileSize(tileSize),
    m_tilesets(tilesets), m_position(0, 0), m_velocity(0, 0) {

    m_numColumns = (TheGame::Instance()->getGameWidth() / m_tileSize);
    m_numRows = (TheGame::Instance()->getGameHeight() / m_tileSize);
}

void TileLayer::update() {
    m_position += m_velocity;
}

void TileLayer::render() {
    int x, y, x2, y2 = 0;

    x = m_position.getX() / m_tileSize;
    y = m_position.getY() / m_tileSize;

    x2 = int(m_position.getX()) % m_tileSize;
    y2 = int(m_position.getY()) % m_tileSize;

    for (int i = 0; i < m_numRows; i++) {
        for (int j = 0; j < m_numColumns; j++) {
            int id = m_tileIds[i][j + x];
            if (id == 0) {
                continue;
            }

            Tileset tileset = getTilesetById(id);
            id--;

            TheTextureManager::Instance()->drawTile(tileset.name, 0, 0, (j * m_tileSize) - x2,
                (i * m_tileSize) - y2, m_tileSize, m_tileSize, (id - (tileset.firstGridId - 1)) / tileset.numColumns,
                (id - (tileset.firstGridId - 1)) % tileset.numColumns, TheGame::Instance()->getRenderer());
        }
    }
}

Tileset TileLayer::getTilesetById(int tileId) {
    return m_tilesets[0];

    // TODO: FIX THIS!!

    for (int i = 0; i < m_tilesets.size(); i++) {
        if (i + 1 <= m_tilesets.size() - 1) {
            if (tileId >= m_tilesets[i].firstGridId && tileId < m_tilesets[i + 1].firstGridId) {
                return m_tilesets[i];
            }
            else {
                return m_tilesets[i];
            }
        }
    }

    //cout << "Tileset not found, returning empty tileset" << endl;
    Tileset t;
    return t;
}
