#ifndef TANK_H
#define TANK_H


#include "Bullet.hpp"
#include <iostream>

class Tank {
    sf::RectangleShape shape;
    sf::CircleShape collisionShape;
    TankController controller;
    float speed;
    float rotation;
    float radians;
    sf::Vector2f direction;
    std::vector<Bullet> bullets;
    sf::Clock bulletCooldown;
    sf::Vector2f previousPosition;
    float forward = 0.f;
public:
    Tank();
    ~Tank();

    sf::RectangleShape getShape();
    sf::CircleShape getCollisionShape();
    sf::Vector2f getPreviousPosition();
    void setPosition(const sf::Vector2f &position);

    std::vector<Bullet> getBullets();
    void setBullets(const std::vector<Bullet> &bullets);


    void render(sf::RenderTarget *target = nullptr);
    void update(const float &dt);

};







#endif