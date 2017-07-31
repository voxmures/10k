#ifndef __TileLayer__
#define __TileLayer__

#include<vector>

#include "Layer.h"
#include "Level.h"
#include "Vector2D.h"

using namespace std;

class TileLayer : public Layer {
public:
    TileLayer(int tileSize, const vector<Tileset> &tilesets);

    virtual void update();
    virtual void render();

    void setTileIds(const vector< vector<int> >& data) { m_tileIds = data; }
    void setTileSize(int tileSize) { m_tileSize = tileSize; }

    Tileset getTilesetById(int tileId);

private:
    int m_numColumns, m_numRows;
    int m_tileSize;

    Vector2D m_position;
    Vector2D m_velocity;

    const vector<Tileset> &m_tilesets;
    vector< vector<int> > m_tileIds;
};

#endif // __TileLayer__
