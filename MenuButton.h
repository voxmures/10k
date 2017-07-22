#ifndef __MenuButton__
#define __MenuButton__

#include "SDLGameObject.h"
#include <stdio.h>

enum button_state {
    IDLE = 0,
    SELECTED = 1
};

class MenuButton : public SDLGameObject {
public:
    MenuButton(const LoaderParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();

    void setState(bool selected);
};

#endif // __MenuButton__
