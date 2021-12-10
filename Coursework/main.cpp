//#include <SFML/Graphics.hpp>
#include <iostream>
#include "Engine.hpp"
//using namespace sf;

int main(int argc, char **argv) {
    
    Engine engine;
    engine.start();
    
//     RenderWindow window(VideoMode(640, 200), "SFML Works!");
//     std::cout << "LOG: app started working" << std::endl;
//     
//     Event WinEv;
//     
//     while (window.isOpen())
//     {
//         while (window.pollEvent(WinEv))
//         {
//             if (WinEv.type == Event::Closed)
//                 window.close();
//         }
//         window.clear(Color::White);
//        window.setActive(true);
//         
//        Texture texture;
//        texture.loadFromFile("src/baphomet.jpg");
//        Sprite sprite(texture);
//        window.draw(sprite);
//         
//         window.display();
//     }
//     
//     
//     std::cout << "LOG: app is closing";
    return 0;
}
