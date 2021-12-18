#include "Engine.hpp"
#include "map.hpp"


Engine::Engine()
{
  
    resolution.x = VideoMode::getDesktopMode().width; //getFullscreenMode
    resolution.y = VideoMode::getDesktopMode().height;
    
    gameWin.create(VideoMode(resolution.x, resolution.y), "My platformer", Style::Fullscreen);
    gameBackgroundTexture.loadFromFile("src/background.jpg");
    gameBackgroundSprite.setTexture(gameBackgroundTexture);
    
    gameMapTexture.loadFromFile("src/map.png");
    gameMapSprite.setTexture(gameMapTexture);
    gameMapSprite.setScale(2, 2);
    
    gameView.reset(sf::FloatRect(0, 0, resolution.x, resolution.y));
        
}

void Engine::start()
{
    Clock gameClock;
    
    while (gameWin.isOpen())
    {
        Time dt = gameClock.restart();
      
        float dtAsSeconds = dt.asSeconds();
              
        input();
        update(dtAsSeconds);
        draw();
    }
}

void Engine::draw()
{
    gameWin.setView(gameView);
    setGameView(gamePlayer.getPosition());
    
    gameWin.clear(Color::White);
    
    gameWin.draw(gameBackgroundSprite);
    
    for (int i = 0; i < MAP_HEIGHT; i++)
        for ( int j = 0; j < MAP_WIDTH; j++)
        {
            if (Tile_Map[i][j] == ' ')
                gameMapSprite.setTextureRect(IntRect(0, 0, 32, 32));
            if (Tile_Map[i][j] == 's')
                gameMapSprite.setTextureRect(IntRect(32, 0, 32, 32));
            if (Tile_Map[i][j] == '0')
                gameMapSprite.setTextureRect(IntRect(64, 0, 32, 32));
            
            gameMapSprite.setPosition(j*32*2, i*32*2);
            gameWin.draw(gameMapSprite);
        }

    
   
  
    gameWin.draw(gamePlayer.getSprite());
    
    gameWin.display();
}

void Engine::update(float dtAsSeconds)
{
    gamePlayer.update(dtAsSeconds);
}

void Engine::setGameView(sf::Vector2f pPosition)
{
    
    float leftXBorder = 585;
    float rightXBorder = 1775;
    float upperYBorder = 385;
    float bottomYBorder = 1215;
    
    sf::Vector2f tmp = pPosition;
    if (tmp.x < leftXBorder) 
        tmp.x = leftXBorder;
    if (tmp.x > rightXBorder)
        tmp.x = rightXBorder;
    if (tmp.y < upperYBorder)
        tmp.y = upperYBorder;
    if (tmp.y > bottomYBorder)
        tmp.y = bottomYBorder;
    gameView.setCenter(tmp.x+100, tmp.y);
}


void Engine::input()
{
    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        gameWin.close();
    }
    
//     if (Keyboard::isKeyPressed(Keyboard::Right))
//         {
//             gamePlayer.moveRight();
//         }
//         else
//         {
//             gamePlayer.stopRightMove();
//         }
//         
//     if (Keyboard::isKeyPressed(Keyboard::Left))
//         {
//             gamePlayer.moveLeft();
//         }
//         else
//         {
//             gamePlayer.stopLeftMove();
//         }
//     
//     if (Keyboard::isKeyPressed(Keyboard::Up))
//         {
//             gamePlayer.moveUp();
//         }
//         else
//         {
//             gamePlayer.stopUpMove();
//         }
//         
//     if (Keyboard::isKeyPressed(Keyboard::Down))
//         {
//             gamePlayer.moveDown();
//         }
//         else
//         {
//             gamePlayer.stopDownMove();
//         }
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            gamePlayer.stopDownMove();  //remove later
            gamePlayer.stopUpMove();    //remove later
            gamePlayer.stopRightMove();
            gamePlayer.moveLeft();
            setGameView(gamePlayer.getPosition());
          
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            gamePlayer.stopDownMove();  //remove later
            gamePlayer.stopUpMove();    //remove later
            gamePlayer.stopLeftMove();
            gamePlayer.moveRight(); 
            setGameView(gamePlayer.getPosition());
        }
        else if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            gamePlayer.stopDownMove();  //remove later
            gamePlayer.stopLeftMove();    //remove later
            gamePlayer.stopRightMove();
            gamePlayer.moveUp();
            setGameView(gamePlayer.getPosition());
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            gamePlayer.stopLeftMove();  //remove later
            gamePlayer.stopUpMove();    //remove later
            gamePlayer.stopRightMove();
            gamePlayer.moveDown();
            setGameView(gamePlayer.getPosition());
        }
        else
        {
            gamePlayer.stopDownMove();  //remove later
            gamePlayer.stopUpMove();    //remove later
            gamePlayer.stopRightMove();
            gamePlayer.stopLeftMove();
            setGameView(gamePlayer.getPosition());
        }
        
      
        
}




