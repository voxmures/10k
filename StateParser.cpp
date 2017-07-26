#include "StateParser.h"

#include "Game.h"
#include "TextureManager.h"
#include "GameObjectFactory.h"

bool StateParser::parseState(const char* stateFile, string stateId, vector<GameObject*> *pObjects, vector<string> *pTextureIds) {

    TiXmlDocument xmlDoc;

    if (!xmlDoc.LoadFile(stateFile)) {
        cerr << xmlDoc.ErrorDesc() << endl;
        return false;
    }

    TiXmlElement* pRoot = xmlDoc.RootElement();

    TiXmlElement* pStateRoot = 0;
    for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
        if (e->Value() == stateId) {
            pStateRoot = e;
        }
    }

    TiXmlElement* pTextureRoot = 0;
    for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
        if (e->Value() == string("TEXTURES")) {
            pTextureRoot = e;
        }
    }

    parseTextures(pTextureRoot, pTextureIds);

    TiXmlElement* pObjectRoot = 0;
    for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
        if (e->Value() == string("OBJECTS")) {
            pObjectRoot = e;
        }
    }

    parseObjects(pObjectRoot, pObjects);

    return true;
}

void StateParser::parseTextures(TiXmlElement* pStateRoot, vector<string> *pTextureIds) {
    for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
        string filenameAttribute = e->Attribute("filename");
        string idAttribute = e->Attribute("ID");
        pTextureIds->push_back(idAttribute);

        TheTextureManager::Instance()->load(filenameAttribute, idAttribute, TheGame::Instance()->getRenderer());
    }
}

void StateParser::parseObjects(TiXmlElement *pStateRoot, vector<GameObject*> *pObjects) {
    for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
        int x, y, width, height, numFrames, callbackId, animSpeed;
        bool selected;
        string textureId;

        e->Attribute("x", &x);
        e->Attribute("y", &y);
        e->Attribute("width", &width);
        e->Attribute("height", &height);
        e->Attribute("numFrames", &numFrames);
        e->Attribute("callbackID", &callbackId);
        e->Attribute("animSpeed", &animSpeed);
        selected = !!(e->Attribute("selected"));

        textureId = e->Attribute("textureID");

        GameObject* pGameObject = TheGameObjectFactory::Instance()->create(e->Attribute("type"));
        pGameObject->load(new LoaderParams(x, y, width, height, textureId, numFrames, callbackId, animSpeed, selected));
        pObjects->push_back(pGameObject);
    }
}
