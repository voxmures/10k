#ifndef __Player__
#define __Player__

#include "GameObject.h"

using namespace std;

class Player : public GameObject {
public:
    void load(int x, int y, int width, int height, string textureId);
    void draw(SDL_Renderer* pRenderer);
    void update();
    void clean();
};

#endif // __Player__
