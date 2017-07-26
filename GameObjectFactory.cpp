#include "GameObjectFactory.h"

#include <iostream>

GameObjectFactory* GameObjectFactory::s_pInstance = 0;

bool GameObjectFactory::registerType(string typeId, BaseCreator* pCreator) {
    map<string, BaseCreator*>::iterator it = m_creators.find(typeId);

    // if the type is already registered, do nothing
    if (it != m_creators.end()) {
        delete pCreator;
        return false;
    }

    m_creators[typeId] = pCreator;
    return true;
}

GameObject* GameObjectFactory::create(string typeId) {
    map<string, BaseCreator*>::iterator it = m_creators.find(typeId);

    if (it == m_creators.end()) {
        cout << "Could not find type: " << typeId << endl;
        return NULL;
    }

    BaseCreator* pCreator = (*it).second;
    return pCreator->createGameObject();
}
