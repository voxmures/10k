#ifndef __StateParser__
#define __StateParser__

#include <iostream>
#include <vector>
#include "lib/tinyxml/tinyxml.h"

#include "GameObject.h"

using namespace std;

class StateParser {
public:
    bool parseState(const char* stateFile, string stateId, vector<GameObject*> *pObjects, vector<string> *pTextureIds);

private:
    void parseObjects(TiXmlElement* pStateRoot, vector<GameObject*> *pObjects);
    void parseTextures(TiXmlElement* pStateRoot, vector<string> *pTextureIds);
};

#endif // __StateParser__
