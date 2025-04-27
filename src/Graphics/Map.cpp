#include "Map.hpp"

Map::Map()
{
    walls.push_back(sf::RectangleShape(sf::Vector2f(this->gridSize, this->gridSize*32)));
    walls[0].setPosition(0.f, 0.f);
    walls.push_back(sf::RectangleShape(sf::Vector2f(this->gridSize*39, this->gridSize)));
    walls[1].setPosition(this->gridSize, 0.f);
    walls.push_back(sf::RectangleShape(sf::Vector2f(this->gridSize, this->gridSize*31)));
    walls[2].setPosition(this->gridSize*39, this->gridSize);
    walls.push_back(sf::RectangleShape(sf::Vector2f(this->gridSize*38, this->gridSize)));
    walls[3].setPosition(this->gridSize, this->gridSize*31);
}

void Map::render(sf::RenderTarget *target)
{
    for (auto &wall : walls)
    {
        target->draw(wall);
    }

}

void Map::update(const float &dt)
{
}
