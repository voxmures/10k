#ifndef __AnimatedGraphic__
#define __AnimatedGraphic__

#include "SDLGameObject.h"
#include "Vector2D.h"

using namespace std;

class AnimatedGraphic : public SDLGameObject {
public:
    AnimatedGraphic(const LoaderParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();
};


#endif // __AnimatedGraphic__
