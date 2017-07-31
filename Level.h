#ifndef __Level__
#define __Level__

#include <string>
#include <vector>

#include "Layer.h"

using namespace std;

struct Tileset {
    int firstGridId;
    int tileWidth;
    int tileHeight;
    int spacing;
    int margin;
    int width;
    int height;
    int numColumns;
    string name;
};

class Level {
public:
    ~Level();

    void update();
    void render();

    vector<Tileset>* getTilesets() { return &m_tilesets; }
    vector<Layer*>* getLayers() { return &m_layers; }

private:
    friend class LevelParser;
    Level() {}

    vector<Tileset> m_tilesets;
    vector<Layer*> m_layers;
};

#endif // __Level__
