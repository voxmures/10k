#ifndef __SDLGameObject__
#define __SDLGameObject__

#include "GameObject.h"

using namespace std;

class SDLGameObject : public GameObject {
public:
    SDLGameObject(const LoaderParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();

protected:
    int m_x, m_y;
    int m_width, m_height;

    int m_currentRow;
    int m_currentFrame;

    string m_textureId;
};

#endif // __SDLGameObject__
