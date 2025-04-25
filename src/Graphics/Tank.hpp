#ifndef TANK_H
#define TANK_H


#include "../Controller/TankController.hpp"
#include <iostream>

class Tank {
    sf::RectangleShape shape;
    TankController controller;
    float speed;
    float rotation;
    float radians;
    sf::Vector2f direction;
public:
    Tank();
    ~Tank();

    sf::RectangleShape &getShape();

    void render(sf::RenderTarget *target = nullptr);
    void update(const float &dt);

};







#endif