#pragma once
#include <SFML/Graphics.hpp>
#include "Player.hpp"

using namespace sf;

class Engine
{
    private:
        RenderWindow gameWin;
        
        Sprite gameBackgroundSprite;
        Texture gameBackgroundTexture;
        
        Player gamePlayer;
        
        bool isMovingUp;
        bool isMovingDown;
        bool isMovingRight;
        bool isMovingLeft;
        
        
        void input();
        void update(float dtAsSeconds);
        void draw();
        
       
    public:
        Engine();
        void start();
      
};
