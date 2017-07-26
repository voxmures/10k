#ifndef __GameObjectFactory__
#define __GameObjectFactory__

#include <string>
#include <map>

#include "GameObject.h"

using namespace std;

class BaseCreator {
public:
    virtual GameObject* createGameObject() const = 0;
    virtual ~BaseCreator() {}
};

class GameObjectFactory {
    static GameObjectFactory* s_pInstance;
public:
    static GameObjectFactory* Instance() {
        if (s_pInstance == 0) {
            s_pInstance = new GameObjectFactory();
        }
        return s_pInstance;
    }

    bool registerType(string typeId, BaseCreator* pCreator);

    GameObject* create(string typeId);

private:
    GameObjectFactory() {}

    map<string, BaseCreator*> m_creators;
};

typedef GameObjectFactory TheGameObjectFactory;
#endif // __GameObjectFactory__
