#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

#include "map.hpp"
#include "View.hpp"

typedef enum
{ left, right, up, down, jump, stay, right_Top} tState;

using namespace sf;

class Entity
{
public:

	float dx, dy, x, y, speed, moveTimer;
	float w, h, health;
	bool life, isMove, onGround;
	Texture texture;
	Sprite sprite;
	String name;
	Entity(Image &image, String Name, float X, float Y, float W, float H)
    {
		x = X;
        y = Y; 
        w = W; 
        h = H; 
        name = Name; 
        moveTimer = 0;
		speed = 0; 
        health = 100; 
        dx = 0; 
        dy = 0;
		life = true; 
        onGround = false; 
        isMove = false;
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		//sprite.setOrigin(w / 2, h / 2);
	}

	FloatRect getRect()
    {
		return FloatRect(x, y, w, h);
	}

	virtual void update(float time) = 0;

};

class Player :public Entity 
{
public:
	tState state;
	int playerScore;
	bool isShoot;
    float pTxtrCntrs[4] = {0}; //0 - staying, 1- right/left, 2 - up, 3- down
    bool isLastMoveLeft;
    float shift;
    
	Player(Image &image, String Name, float X, float Y, float W, float H) :Entity(image, Name, X, Y, W, H )
    {
		   playerScore = isShoot = 0; 
           state = stay;
		   if (name == "Player")
           {
			   sprite.setTextureRect(IntRect(0, 0, w, h));
               sprite.setScale(0.25f, 0.25f);
		   }
		   isLastMoveLeft = true;
           onGround = false;
           
           health = 100;
           life = true;
           shift = 16;
           w = (250-2*shift*4)/4;
           h = 250/4;
           setView(x, y);
           
	}

	   void control()
	   {
			   if (Keyboard::isKeyPressed(Keyboard::Left)) 
               {
				   state = left; speed = 250;
			   }
			   if (Keyboard::isKeyPressed(Keyboard::Right)) 
               {
				   state = right; speed = 250;
			   }

			   if ((Keyboard::isKeyPressed(Keyboard::Up)) && (onGround)) 
               {
				   state = jump; dy = -550; onGround = false;
			   }

			   if (Keyboard::isKeyPressed(Keyboard::Down)) 
               {
				   state = down;
			   }

			   if (onGround && (Keyboard::isKeyPressed(Keyboard::Right)) && (Keyboard::isKeyPressed(Keyboard::Up))) 
               {
				   state = right_Top;
			   }

		   
	   } 

	   

	   void checkCollisionWithMap(float DX, float DY)
	   {
           for (int i = (y/32); i < (y+h)/32; i++)
               for (int j = ((x+shift)/32); j < (x+shift+w)/32; j++)
               {
                   if (isAbsSolid(i, j))
                   {
                        if (DY > 0)
                        {
                            y = i*32 - h;
                            onGround = true;
                            dy = 0;
                            state = stay;
                        }
                        else if (DY < 0)
                        {
                            y = (i+1)*32;
                            dy = 0;
                            state = jump;
                        }
                        else if (DX > 0)
                        {
                            x = (j*32) - w - shift;                                                      
                        }
                        else if (DX < 0)
                        {
                            x = (j+1)*32 - shift;                          
                        }    
                   }
                   else
                       onGround = false;        //BUG or FEATURE???
               }
	   }
	    
       void setCurTexture(float time)
        {
    
            if (state == left)
            {
                pTxtrCntrs[1] += 2*time;
                if (pTxtrCntrs[1] > 10)
                    pTxtrCntrs[1] -= 10;
                sprite.setTextureRect( IntRect( ((int)pTxtrCntrs[1])*250, 0, 250, 250 ) );
                pTxtrCntrs[0] = 0;
                pTxtrCntrs[2] = 0;
                pTxtrCntrs[3] = 0;
                isLastMoveLeft = true;
            }
            else if (state == right)
            {
                pTxtrCntrs[1] += 2*time;
                if (pTxtrCntrs[1] > 10)
                    pTxtrCntrs[1] -= 10;
                sprite.setTextureRect( IntRect( ((int)pTxtrCntrs[1])*250, 250, 250, 250 ) );
                pTxtrCntrs[0] = 0;
                pTxtrCntrs[2] = 0;
                pTxtrCntrs[3] = 0; 
                isLastMoveLeft = false;
            }
            else if (state == jump)
            {
                pTxtrCntrs[2] += 2*time;
                if (pTxtrCntrs[2] > 10)
                    pTxtrCntrs[2] -= 10;
                if (isLastMoveLeft)
                        sprite.setTextureRect( IntRect( ((int)pTxtrCntrs[2])*250, 0, 250, 250 ) );
                    else
                        sprite.setTextureRect( IntRect( ((int)pTxtrCntrs[2]), 250, 250, 250 ) );
                pTxtrCntrs[0] = 0;
                pTxtrCntrs[1] = 0;
                pTxtrCntrs[3] = 0; 
            }
            else if (state == down)
            {
            pTxtrCntrs[3] += 2*time;
                if (pTxtrCntrs[3] > 10)
                    pTxtrCntrs[3] -= 10;
                if (isLastMoveLeft)
                        sprite.setTextureRect( IntRect( ((int)pTxtrCntrs[3])*250, 0, 250, 250 ) );
                    else
                        sprite.setTextureRect( IntRect( ((int)pTxtrCntrs[3]), 250, 250, 250 ) );
                pTxtrCntrs[0] = 0;
                pTxtrCntrs[1] = 0;
                pTxtrCntrs[2] = 0; 
            }
            else
            {
                pTxtrCntrs[0] += 2*time;
                if (pTxtrCntrs[0] > 10)
                    pTxtrCntrs[0] -= 10;
                if (isLastMoveLeft)
                        sprite.setTextureRect( IntRect( ((int)pTxtrCntrs[0])*250, 0, 250, 250 ) );
                    else
                        sprite.setTextureRect( IntRect( ((int)pTxtrCntrs[0])*250, 250, 250, 250 ) );
                pTxtrCntrs[1] = 0;
                pTxtrCntrs[2] = 0;
                pTxtrCntrs[3] = 0;
            }
    
        } 
	    
	   void update(float time)
	   {
		   control();
           setCurTexture(time);

		   switch (state)
		   {
		   case right: dx = speed; break;
		   case left: dx = -speed; break;
		   case up: break;
		   case down: dx = 0; break;
		   case stay: break;
		   case right_Top: dx = speed; break;//состояние вправо вверх, просто продолжаем идти вправо
           case jump: break;
		   }
		   x += dx*time;
		   checkCollisionWithMap(dx, 0);
		   y += dy*time;
		   checkCollisionWithMap(0, dy);
		  // sprite.setPosition(x+w/2,y+h/2);
           sprite.setPosition(x, y);
		   if (health <= 0)
           { 
               life = false; 
           }
		   if (!isMove)
           { 
               speed = 0; 
           }
		   if (life) 
           { 
               setView(x, y); 
           }
		//   if (!onGround)
               dy = dy + 1500*time;
               if (onGround)
               {
                   state = stay;
                   dx = 0;
               }
        //    std::cout << x/32 << " - " << y/32 << std::endl;
      
	   } 
};
