#ifndef __MenuButton__
#define __MenuButton__

#include "SDLGameObject.h"
#include "GameObjectFactory.h"
#include <stdio.h>

enum button_state {
    IDLE = 0,
    SELECTED = 1
};

class MenuButton : public SDLGameObject {
public:
    MenuButton();

    virtual void draw();
    virtual void update();
    virtual void clean();

    virtual void load(const LoaderParams* pParams);

    void setCallback(void(*callback)()) { m_callback = callback; }
    int getCallbackId() { return m_callbackId; }

    void setState(bool selected);
    void doAction() { m_callback(); }

private:
    int m_callbackId;
    void (*m_callback)();
};

class MenuButtonCreator : public BaseCreator {
    GameObject* createGameObject() const {
        return new MenuButton();
    }
};

#endif // __MenuButton__
