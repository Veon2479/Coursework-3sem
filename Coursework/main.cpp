//#include <SFML/Graphics.hpp>
#include <iostream>
#include "Engine.hpp"
//using namespace sf;
int main(int argc, char **argv) {
    
    Engine engine;
    std::cout << "LOG: app is starting" << std::endl;
    engine.start();
    std::cout << "LOG: app is closed" << std::endl;

    return 0;
}
