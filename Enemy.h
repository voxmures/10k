#ifndef __Enemy__
#define __Enemy__

#include "GameObject.h"

using namespace std;

class Enemy : public GameObject {
public:
    void load(int x, int y, int width, int height, string textureId);
    void draw(SDL_Renderer* pRenderer);
    void update();
    void clean();
};

#endif // __Enemy__
