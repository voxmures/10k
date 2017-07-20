#ifndef __GameObject__
#define __GameObject__

#include "TextureManager.h"

using namespace std;

class GameObject {
public:
    void load(int x, int y, int width, int height, string textureId);
    void draw(SDL_Renderer* pRenderer);
    void update();
    void clean();

protected:
    string m_textureId;

    int m_currentFrame;
    int m_currentRow;

    int m_x, m_y;
    int m_width, m_height;
};
#endif // __GameObject__
