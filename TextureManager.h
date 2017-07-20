#ifndef __TextureManager__
#define __TextureManager__

#ifdef __linux__
    //linux code goes here
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_image.h>
#elif _WIN32
	//windows code goes here
	#include <SDL.h>
	#include <SDL_image.h>
#endif

#include <string>
#include <map>

using namespace std;

class TextureManager {
    static TextureManager* s_pInstance;

public:
    static TextureManager* Instance() {
        if (s_pInstance == 0) {
            s_pInstance = new TextureManager();
            return s_pInstance;
        }
        return s_pInstance;
    }

    bool load(string filename, string id, SDL_Renderer* pRenderer);

    void draw(string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void drawFrame(string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
    TextureManager() {}

    map<string, SDL_Texture*> m_textureMap;
};

typedef TextureManager TheTextureManager;

#endif // __TextureManager__
