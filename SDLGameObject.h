#ifndef __SDLGameObject__
#define __SDLGameObject__

#include "GameObject.h"
#include "Vector2D.h"

using namespace std;

class SDLGameObject : public GameObject {
public:
    SDLGameObject() {}

    virtual void draw();
    virtual void update();
    virtual void clean();

    virtual void load(const LoaderParams* pParams);

    Vector2D& getPosition() { return m_position; }
    int getWidth() { return m_width; }
    int getHeight() { return m_height; }

protected:
    Vector2D m_position;
    Vector2D m_velocity;
    Vector2D m_acceleration;

    int m_width, m_height;

    int m_currentRow;
    int m_currentFrame;
    int m_numFrames;

    string m_textureId;
};

#endif // __SDLGameObject__
