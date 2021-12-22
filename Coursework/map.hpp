#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED


#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <vector>


int MAP_HEIGHT = 0;
int MAP_WIDTH = 0;

std::vector<sf::String> Tile_Map;

void loadMap()
{
 
    std::fstream map;
    std::string line;
    map.open("src/Map.txt", std::ios::in);
    if (map)
    {
        while ( std::getline(map, line))
        {
            Tile_Map.push_back(line);
            MAP_HEIGHT++;
            MAP_WIDTH = (line.length()>MAP_WIDTH) ? line.length() : MAP_WIDTH;
            
        }
        map.close();
        std::cout << "LOG: map created" << std::endl;

    }
        else
            std::cout << "ERR: map hasn't read!" << std::endl;
    
}

bool isAbsSolid(int i, int j)
{
    switch (Tile_Map[i][j])
    {
        case '0':
        case 's':
        case 'b':
        case 'd':
            return true;
    }
    return false;
}

#endif // MAP_HPP_INCLUDED
