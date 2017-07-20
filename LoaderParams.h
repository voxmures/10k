#ifndef __LoaderParams__
#define __LoaderParams__

#include <string>

using namespace std;

class LoaderParams {
public:
    LoaderParams(int x, int y, int width, int height, string textureId) :
        m_x(x), m_y(y), m_width(width), m_height(height), m_textureId(textureId) {}

    int getX() const { return m_x; }
    int getY() const { return m_y; }
    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }
    string getTextureId() const { return m_textureId; }

private:
    int m_x, m_y;
    int m_width, m_height;

    string m_textureId;
};

#endif // __LoaderParams__
