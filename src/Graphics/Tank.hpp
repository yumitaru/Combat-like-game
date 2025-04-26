#ifndef TANK_H
#define TANK_H


#include "Bullet.hpp"
#include <iostream>

class Tank {
    sf::RectangleShape shape;
    TankController controller;
    float speed;
    float rotation;
    float radians;
    sf::Vector2f direction;
    std::vector<Bullet> bullets;
    sf::Clock bulletCooldown;
public:
    Tank();
    ~Tank();

    sf::RectangleShape &getShape();

    void render(sf::RenderTarget *target = nullptr);
    void update(const float &dt);

};







#endif