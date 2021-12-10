#include "Engine.hpp"


Engine::Engine()
{
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width; //getFullscreenMode
    resolution.y = VideoMode::getDesktopMode().height;
    
    gameWin.create(VideoMode(resolution.x, resolution.y), "My platformer", Style::Fullscreen);
    gameBackgroundTexture.loadFromFile("src/background.jpg");
    gameBackgroundSprite.setTexture(gameBackgroundTexture);
    
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
    gameWin.clear(Color::White);
    
    gameWin.draw(gameBackgroundSprite);
    gameWin.draw(gamePlayer.getSprite());
    
    gameWin.display();
}

void Engine::update(float dtAsSeconds)
{
    gamePlayer.update(dtAsSeconds);
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
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            gamePlayer.stopDownMove();  //remove later
            gamePlayer.stopUpMove();    //remove later
            gamePlayer.stopLeftMove();
            gamePlayer.moveRight(); 
        }
        else if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            gamePlayer.stopDownMove();  //remove later
            gamePlayer.stopLeftMove();    //remove later
            gamePlayer.stopRightMove();
            gamePlayer.moveUp();
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            gamePlayer.stopLeftMove();  //remove later
            gamePlayer.stopUpMove();    //remove later
            gamePlayer.stopRightMove();
            gamePlayer.moveDown();
        }
        else
        {
            gamePlayer.stopDownMove();  //remove later
            gamePlayer.stopUpMove();    //remove later
            gamePlayer.stopRightMove();
            gamePlayer.stopLeftMove();
        }
}




