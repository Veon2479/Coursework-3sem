#include <SFML/Graphics.hpp>
#include <iostream>
#include "Classes.hpp"

using namespace sf;

Image mapImage;
Image heroImage;

void loadResources()
{
    std::cout << "LOG: loading resources" << std::endl;
   	heroImage.loadFromFile("src/copia.png");
    mapImage.loadFromFile("src/map.png");
    loadMap();
}

bool startGame(RenderWindow &window)
{

    view.reset(FloatRect(0, 0, 683, 384));


	Player player(heroImage, "Player", 4000, 2000, 0, 0);
    Sprite mapSprite;
    Texture mapTexture;
    mapTexture.loadFromImage(mapImage);
    mapSprite.setTexture(mapTexture);
	
	Clock clock;
   // window.clear(Color(77, 83, 140));
	while (window.isOpen())
	{

        window.clear(Color::White);

		float time = clock.getElapsedTime().asSeconds();

		clock.restart();
		time = time / 2;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Tab)) 
        { 
            return true; 
        }
		if (Keyboard::isKeyPressed(Keyboard::Escape)) 
        { 
            return false; 
        }

        for (int i = 0; i < MAP_HEIGHT; i++)
        for ( int j = 0; j < MAP_WIDTH; j++)
        {
            if (i<(player.y+400)/32 && i>(player.y - 383)/32 && j<(player.x + 683)/32 && j>(player.x - 683)/32 )
            {
            if (Tile_Map[i][j] == ' ')
                mapSprite.setTextureRect(IntRect(0, 0, 32, 32));
            else if (Tile_Map[i][j] == 's')
                mapSprite.setTextureRect(IntRect(32, 0, 32, 32));
        else if (Tile_Map[i][i] == '0'|| Tile_Map[i][j] == 'b' || Tile_Map[i][j] == 'g' || Tile_Map[i][j] == 'd' )
                mapSprite.setTextureRect(IntRect(64, 0, 32, 32));
            else 
                mapSprite.setTextureRect(IntRect(96, 0, 32, 32));
        
            mapSprite.setPosition(j*32, i*32);
            window.draw(mapSprite);
            }
        }
       
		player.update(time);
		window.setView(view);
		window.draw(player.sprite);
		window.display();
	}
    return false;
    
}

void GameRunning(RenderWindow &window)
{
    std::cout << "LOG: game is starting" << std::endl;

    if (startGame(window))
        GameRunning(window);
}

int main(int argc, char **argv) {
    
  
    std::cout << "LOG: app is starting" << std::endl;
    loadResources();
    RenderWindow window(VideoMode( 1366, 768), "The Game", Style::Fullscreen);
    GameRunning(window);     
    std::cout << "LOG: app is closed" << std::endl;

    return 0;
}
