#include "Player.hpp"

Player::Player()
{
    pXSpeed = 50;
    pYSpeed = 50;
    
   
    pImage.loadFromFile("src/copia.png");
    pImage.createMaskFromColor(Color::White);
    
    pTexture.loadFromImage(pImage);
    pSprite.setTexture(pTexture);

    
    pPosition.x = 500;
    pPosition.y = 500;
    
    p_lastLeftMove = true;
   
  //  lastUpdatedTime = 0;
    
}

Sprite Player::getSprite()
{
    return pSprite;
}

void Player::moveDown()
{
    p_DownMoving = true;
}

void Player::stopDownMove()
{
    p_DownMoving = false;
}

void Player::moveUp()
{
    p_UpMoving = true;
}

void Player::stopUpMove()
{
    p_UpMoving = false;
}

void Player::moveLeft()
{
    p_LeftMoving = true;
    p_lastLeftMove = true;
}

void Player::stopLeftMove()
{
    p_LeftMoving = false;
}

void Player::moveRight()
{
    p_RightMoving = true;
    p_lastLeftMove = false;
}

void Player::stopRightMove()
{
    p_RightMoving = false;
}



void Player::setCurTexture(float elapsedTime)
{
    
    if (p_LeftMoving)
    {
        pTxtrCntrs[1] += 2*elapsedTime;
        if (pTxtrCntrs[1] > 10)
            pTxtrCntrs[1] -= 10;
        pSprite.setTextureRect( IntRect( ((int)pTxtrCntrs[1])*250, 0, 250, 250 ) );
        pTxtrCntrs[0] = 0;
        pTxtrCntrs[2] = 0;
        pTxtrCntrs[3] = 0;
    }
    else if (p_RightMoving)
    {
        pTxtrCntrs[1] += 2*elapsedTime;
        if (pTxtrCntrs[1] > 10)
            pTxtrCntrs[1] -= 10;
        pSprite.setTextureRect( IntRect( ((int)pTxtrCntrs[1])*250 + 250, 0, -250, 250 ) );
        pTxtrCntrs[0] = 0;
        pTxtrCntrs[2] = 0;
        pTxtrCntrs[3] = 0; 
    }
    else if (p_UpMoving)
    {
        pTxtrCntrs[2] += 2*elapsedTime;
        if (pTxtrCntrs[2] > 10)
            pTxtrCntrs[2] -= 10;
        if (p_lastLeftMove)
                pSprite.setTextureRect( IntRect( ((int)pTxtrCntrs[2])*250, 0, 250, 250 ) );
            else
                pSprite.setTextureRect( IntRect( ((int)pTxtrCntrs[2])*250 + 250, 0, -250, 250 ) );
        pTxtrCntrs[0] = 0;
        pTxtrCntrs[1] = 0;
        pTxtrCntrs[3] = 0; 
    }
    else if (p_DownMoving)
    {
       pTxtrCntrs[3] += 2*elapsedTime;
        if (pTxtrCntrs[3] > 10)
            pTxtrCntrs[3] -= 10;
        if (p_lastLeftMove)
                pSprite.setTextureRect( IntRect( ((int)pTxtrCntrs[3])*250, 0, 250, 250 ) );
            else
                pSprite.setTextureRect( IntRect( ((int)pTxtrCntrs[3])*250 + 250, 0, -250, 250 ) );
        pTxtrCntrs[0] = 0;
        pTxtrCntrs[1] = 0;
        pTxtrCntrs[2] = 0; 
    }
    else
   // if (!p_DownMoving && !p_UpMoving && !p_RightMoving && !p_LeftMoving)
    {
        pTxtrCntrs[0] += 2*elapsedTime;
        if (pTxtrCntrs[0] > 10)
            pTxtrCntrs[0] -= 10;
        if (p_lastLeftMove)
                pSprite.setTextureRect( IntRect( ((int)pTxtrCntrs[0])*250, 0, 250, 250 ) );
            else
                pSprite.setTextureRect( IntRect( ((int)pTxtrCntrs[0])*250 + 250, 0, -250, 250 ) );
        pTxtrCntrs[1] = 0;
        pTxtrCntrs[2] = 0;
        pTxtrCntrs[3] = 0;
    }
  
}


void Player::update(float elapsedTime)
{
    float speed = 5;
    
    if (p_UpMoving)
    {
        pPosition.y -= pYSpeed * elapsedTime * speed;
    }
    
    if (p_DownMoving)
    {
        pPosition.y += pYSpeed * elapsedTime * speed;
    }
    
    if (p_LeftMoving)
    {
        pPosition.x -= pXSpeed * elapsedTime * speed;
    }
    
    if (p_RightMoving)
    {
        pPosition.x += pXSpeed * elapsedTime * speed;
    }
    
    setCurTexture(elapsedTime); 
    printf("%f ", elapsedTime);
    
    pSprite.setPosition(pPosition);
   // lastUpdatedTime = elapsedTime;
}


