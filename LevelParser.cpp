#include "LevelParser.h"

//#include <sstream>

#include "TextureManager.h"
#include "Game.h"
#include "TileLayer.h"

Level* LevelParser::parseLevel(const char* levelFile) {
    TiXmlDocument levelDocument;
    levelDocument.LoadFile(levelFile);

    Level* pLevel = new Level();

    TiXmlElement* pRoot = levelDocument.RootElement();

    pRoot->Attribute("tilewidth", &m_tileSize);
    pRoot->Attribute("width", &m_width);
    pRoot->Attribute("height", &m_height);

    for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
        if (e->Value() == string("tileset")) {
            parseTileset(e, pLevel->getTilesets());
        }
    }

    for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
        if (e->Value() == string("layer")) {
            parseTileLayer(e, pLevel->getLayers(), pLevel->getTilesets());
        }
    }

    return pLevel;
}

void LevelParser::parseTileset(TiXmlElement* pTMXRoot, vector<Tileset>* pTilesets) {
    TiXmlDocument tilesetDocument;
    tilesetDocument.LoadFile(pTMXRoot->Attribute("source"));

    TiXmlElement* pTSXRoot = tilesetDocument.RootElement();

    TheTextureManager::Instance()->load(pTSXRoot->FirstChildElement()->Attribute("source"),
        pTSXRoot->Attribute("name"), TheGame::Instance()->getRenderer());

    Tileset tileset;
    pTSXRoot->FirstChildElement()->Attribute("width", &tileset.width);
    pTSXRoot->FirstChildElement()->Attribute("height", &tileset.height);
    pTMXRoot->Attribute("firstgid", &tileset.firstGridId);
    pTSXRoot->Attribute("tilewidth", &tileset.tileWidth);
    pTSXRoot->Attribute("tileheight", &tileset.tileHeight);
    pTSXRoot->Attribute("spacing", &tileset.spacing);
    pTSXRoot->Attribute("margin", &tileset.margin);
    tileset.name = pTSXRoot->Attribute("name");

    tileset.numColumns = tileset.width / (tileset.tileWidth + tileset.spacing);

    pTilesets->push_back(tileset);
}

void LevelParser::parseTileLayer(TiXmlElement* pTileElement, vector<Layer*>* pLayers, const vector<Tileset>* pTilesets) {
    TileLayer* pTileLayer = new TileLayer(m_tileSize, *pTilesets);

    vector< vector<int> > data;

    vector<int> layerRow(m_width);

    for (int j = 0; j < m_height; j++) {
        data.push_back(layerRow);
    }

    TiXmlElement* pDataNode;
    for (TiXmlElement* e = pTileElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
        if (e->Value() == string("data")) {
            pDataNode = e;
        }
    }

    // Parse CSV data
    for (TiXmlNode* e = pDataNode->FirstChild(); e != NULL; e = e->NextSibling()) {
        TiXmlText* text = e->ToText();
        string csvData = text->Value();
        stringstream ss(csvData);
        string token;

        int i, j;
        i = j = 0;
        while(getline(ss, token, ',')) {
            if (j == m_width) {
                i++;
                j = 0;
            }
            data[i][j] = atoi(token.c_str());

            j++;
        }
    }

    pTileLayer->setTileIds(data);

    pLayers->push_back(pTileLayer);
}
