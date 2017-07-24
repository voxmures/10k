#ifndef __Player__
#define __Player__

#include "SDLGameObject.h"
#include "Vector2D.h"

class Player : public SDLGameObject {
public:
    Player(const LoaderParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();

private:
    void handleInput();
};

#endif // __Player__
