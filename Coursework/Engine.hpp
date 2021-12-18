#pragma once

#include <SFML/Graphics.hpp>
#include "Player.hpp"

using namespace sf;

class Engine
{
    private:
        RenderWindow gameWin;
        Vector2f resolution;
        
        Sprite gameBackgroundSprite;
        Texture gameBackgroundTexture;
        
       
        Sprite gameMapSprite;
        Texture gameMapTexture;
        
        Player gamePlayer;
        
        bool isMovingUp;
        bool isMovingDown;
        bool isMovingRight;
        bool isMovingLeft;
        
        void setGameView(Vector2f pPosition);
        sf::View gameView;
        
        void input();
        void update(float dtAsSeconds);
        void draw();
        
       
    public:
        Engine();
        void start();
      
};
