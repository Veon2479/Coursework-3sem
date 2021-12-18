#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
    private:
        Vector2f pPosition;
        
        Sprite pSprite;
        Texture pTexture;   
        Image pImage;
      //  float pTextureCounter;
        float pTxtrCntrs[4] = {0}; //0 - staying, 1- right/left, 2 - up, 3- down
        void setCurTexture(float elapsedTime);
       // float lastUpdatedTime;
        
        bool p_lastLeftMove;
        bool p_LeftMoving;
        bool p_RightMoving;
        bool p_UpMoving;
        bool p_DownMoving;
        
        float pXSpeed;
        float pYSpeed;
        
        
        
    public:
        Player();
        
        Sprite getSprite();
        
        Vector2f getPosition();
        
        void moveUp();
        void moveDown();
        void moveRight();
        void moveLeft();
        
        void stopLeftMove();
        void stopRightMove();
        void stopUpMove();
        void stopDownMove();
       
        void update(float elapsedTime);
        
        
};
