#ifndef __Enemy__
#define __Enemy__

#include "SDLGameObject.h"
#include "Vector2D.h"

using namespace std;

class Enemy : public SDLGameObject {
public:
    Enemy();

    virtual void draw();
    virtual void update();
    virtual void clean();

    virtual void load(const LoaderParams* pParams);

    void setPlayerPos(Vector2D& pos);

private:
    Vector2D* playerPos;

    void nextAction();
};


#endif // __Enemy__
