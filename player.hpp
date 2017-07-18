#include "ltexture.hpp"

enum PLAYER_MOVES {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

// Player class
class Player {
    public:
        // The dimensions of the sprite
        static const int SPRITE_WIDTH = 24;
        static const int SPRITE_HEIGHT = 38;

        Player();

        void move(int direction);

        int getPosX();
        int getPosY();

        LTexture* getTexture();
        void setTexture(LTexture texture);

    private:
        //Maximum axis velocity of the sprite
        static const int PLAYER_SPEED = 10;

        int mPosX, mPosY;

        LTexture mTexture;
};
