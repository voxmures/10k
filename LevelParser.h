#ifndef __LevelParser__
#define __LevelParser__

#include "lib/tinyxml/tinyxml.h"

#include "Level.h"

using namespace std;

class LevelParser {
public:
    Level* parseLevel(const char* levelFile);

private:
    void parseTileset(TiXmlElement* pTMXRoot, vector<Tileset>* pTilesets);
    void parseTileLayer(TiXmlElement* pTileElement, vector<Layer*> *pLayers, const vector<Tileset>* pTilesets);

    int m_tileSize;
    int m_width, m_height;
};

#endif // __LevelParser__
