#include "WallCollision.hpp"


bool WallCollision::checkCollision(Tank &tank, Map &walls)
{
    for (const auto &wall : walls.getWalls()) {
        if (tank.getCollisionShape().getGlobalBounds().intersects(wall.getGlobalBounds())) {
            return true; // Collision detected
        }
    }
    return false; // No collision
}

void WallCollision::update(const float &dt, Tank &tank, Map &walls)
{

    float rotation = tank.getShape().getRotation(); // in degrees
    float radians = rotation * 3.14159265f / 180.f;

    sf::Vector2f direction = {std::cos(radians), std::sin(radians)};
    

    if(this->checkCollision(tank, walls)) // Check for collision with walls
    {
        tank.setPosition(tank.getPreviousPosition());

        std::cout << "Collision detected!" << std::endl;

    }
}
