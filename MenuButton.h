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
    MenuButton(const LoaderParams* pParams, void (*callback)());

    virtual void draw();
    virtual void update();
    virtual void clean();

    void setState(bool selected);

    void doAction() { m_callback(); }

private:
    void (*m_callback)();
};

#endif // __MenuButton__
