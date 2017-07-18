#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

using namespace std;

// Texture wrapper class
class LTexture {
    public:
        // Initializes variables
        LTexture();

        // Deallocates memory
        ~LTexture();

        // Loads image at specified path
        bool loadFromFile(string path);

        // Deallocates texture
        void free();

        // Renders texture at given point
        void render(int x, int y, SDL_Rect* clip = NULL);

        // Gets image dimensions
        int getWidth();
        int getHeight();

        void setRenderer(SDL_Renderer* renderer);

    private:
        // The actual hardware texture
        SDL_Texture* mTexture;
        SDL_Renderer* renderer;
        // Image dimensions
        int mWidth;
        int mHeight;
};
