#ifndef BULLET_HPP
#define BULLET_HPP

#include "Map.hpp"

class Bullet {
    sf::CircleShape shape;
    float speed;
    float x, y;
    float radius;
    sf::Vector2f direction;
    sf::Vector2f previousPosition;
    int hitCount = 0;
public:
    Bullet();
    Bullet(sf::Vector2f position);

    ~Bullet() = default;


    void render(sf::RenderTarget *target = nullptr);
    void update(const float &dt);
    void setDirection(float rad);
    void setDirection(sf::Vector2f direction);
    sf::Vector2f getDirection();
    
    sf::Vector2f getPosition();
    sf::Vector2f getPreviousPosition();
    void setPosition(sf::Vector2f);

    void incrementHitCount();
    int getHitCount() const;

    sf::CircleShape getShape();

};


#endif