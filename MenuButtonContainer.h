#ifndef __MenuButtonContainer__
#define __MenuButtonContainer__

#include "MenuButton.h"
#include <vector>
using namespace std;

class MenuButtonContainer : public GameObject {
public:
    void addButton(MenuButton* button);

    virtual void draw();
    virtual void update();
    virtual void clean();

private:
    vector<MenuButton*> m_menuButtons;
    int selectedIndex = 0;

    void handleInput();
};

#endif // __MenuButtonContainer__
