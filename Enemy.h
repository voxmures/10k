#ifndef __Enemy__
#define __Enemy__

#include "SDLGameObject.h"
#include "Vector2D.h"

using namespace std;

class Enemy : public SDLGameObject {
public:
    Enemy(const LoaderParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();

    void setPlayerPos(Vector2D* pos);


private:

    Vector2D* playerPos;
    void nextAction();
};


#endif // __Enemy__
