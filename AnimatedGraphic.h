#ifndef __AnimatedGraphic__
#define __AnimatedGraphic__

#include "SDLGameObject.h"
#include "GameObjectFactory.h"
#include "Vector2D.h"

using namespace std;

class AnimatedGraphic : public SDLGameObject {
public:
    AnimatedGraphic();

    virtual void draw();
    virtual void update();
    virtual void clean();

    virtual void load(const LoaderParams* pParams);

private:
    int m_animSpeed;
};

class AnimatedGraphicCreator : public BaseCreator {
    GameObject* createGameObject() const {
        return new AnimatedGraphic();
    }
};


#endif // __AnimatedGraphic__
