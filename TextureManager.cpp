#include "TextureManager.h"

#ifdef __linux__
    //linux code goes here
	#include <SDL2/SDL_image.h>
#elif _WIN32
	//windows code goes here
	#include <SDL_image.h>
#endif

#include <stdio.h>

TextureManager* TextureManager::s_pInstance = 0;

bool TextureManager::load(string filename, string id, SDL_Renderer* pRenderer) {
    SDL_Surface* pTempSurface = IMG_Load(filename.c_str());
    if (pTempSurface == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", filename.c_str(), IMG_GetError());
        return false;
    }

    SDL_SetColorKey(pTempSurface, SDL_TRUE, SDL_MapRGB(pTempSurface->format, 0, 0xFF, 0xFF));

    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);

    if (pTexture == NULL) {
        printf("Unable to create texture from %s! SDL Error: %s\n", filename.c_str(), SDL_GetError());
        return false;
    }

    m_textureMap[id] = pTexture;
    return true;
}

void TextureManager::draw(string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawTile(string id, int margin, int spacing, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer) {
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = margin + (spacing + width) * currentFrame;
    srcRect.y = margin + (spacing + height) * currentRow;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, SDL_FLIP_NONE);
}
