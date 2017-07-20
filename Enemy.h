#ifndef __Enemy__
#define __Enemy__

#include "SDLGameObject.h"

using namespace std;

class Enemy : public SDLGameObject {
public:
    Enemy(const LoaderParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();
};

#endif // __Enemy__
