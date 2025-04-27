#ifndef BULLET_HPP
#define BULLET_HPP

#include "Map.hpp"

class Bullet {
    sf::CircleShape shape;
    float speed;
    float x, y;
    float radius;
    sf::Vector2f direction;
public:
    Bullet();
    Bullet(sf::Vector2f position);

    ~Bullet() = default;


    void render(sf::RenderTarget *target = nullptr);
    void update(const float &dt);
    void setDirection(float rad);
};


#endif