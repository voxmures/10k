#ifndef __AgentsHub__
#define __AgentsHub__

#include "Player.h"
#include "Enemy.h"

using namespace std;

class AgentsHub {
public:
    void init(Player* p, Enemy* e);

    void updateInformation();

    bool checkCollision();

private:
    Player* player;
    Enemy* enemy;
};


#endif // __Enemy__
