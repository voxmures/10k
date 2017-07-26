#ifndef __LoaderParams__
#define __LoaderParams__

#include <string>

using namespace std;

class LoaderParams {
public:
    LoaderParams(int x, int y, int width, int height, string textureId, int numFrames, int callbackId = 0, int animSpeed = 0, bool selected = false) :
        m_x(x), m_y(y), m_width(width), m_height(height), m_textureId(textureId), m_numFrames(numFrames),
        m_callbackId(callbackId), m_animSpeed(animSpeed), m_selected(selected) {}

    int getX() const { return m_x; }
    int getY() const { return m_y; }
    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }
    int getNumFrames() const { return m_numFrames; }
    int getCallbackId() const { return m_callbackId; }
    int getAnimSpeed() const { return m_animSpeed; }
    bool selected() const { return m_selected; }
    string getTextureId() const { return m_textureId; }

private:
    int m_x, m_y;
    int m_width, m_height;
    int m_numFrames;
    int m_callbackId;
    int m_animSpeed;
    bool m_selected;

    string m_textureId;
};

#endif // __LoaderParams__
