#ifndef __GameObject__
#define __GameObject__

#include "TextureManager.h"

using namespace std;

class GameObject {
public:
    virtual void load(int x, int y, int width, int height, string textureId);
    virtual void draw(SDL_Renderer* pRenderer);
    virtual void update();
    virtual void clean();

protected:
    string m_textureId;

    int m_currentFrame;
    int m_currentRow;

    int m_x, m_y;
    int m_width, m_height;
};
#endif // __GameObject__
