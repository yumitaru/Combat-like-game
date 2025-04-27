#ifndef MAP_HPP
#define MAP_HPP

#include "../Controller/TankController.hpp"

class Map {
    std::vector<sf::RectangleShape> walls;
    float gridSize = 25.f;

public:
    Map();
    ~Map() = default;

    void render(sf::RenderTarget *target = nullptr);
    void update(const float &dt);
};








#endif