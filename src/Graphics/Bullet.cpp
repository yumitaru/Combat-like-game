#include "Bullet.hpp"

Bullet::Bullet() {
    this->x = 0.f;
    this->y = 0.f;
    this->radius = 5.f;
    this->speed = 100.f;

    this->shape.setRadius(radius);
    this->shape.setFillColor(sf::Color::Red);
    this->shape.setPosition(x, y);
    this->shape.setOrigin(radius, radius);
}

Bullet::Bullet(sf::Vector2f position): x(position.x), y(position.y), radius(5.f), speed(300.f)
{
    this->shape.setRadius(radius);
    this->shape.setFillColor(sf::Color::Red);
    this->shape.setPosition(x, y);
    this->shape.setOrigin(radius, radius);
}

void Bullet::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
}

void Bullet::update(const float &dt)
{
    this->previousPosition = this->shape.getPosition();
    this->shape.move(this->direction * this->speed * dt); // Adjust speed as needed
}

void Bullet::setDirection(float rad)
{
    this->direction = {std::cos(rad), std::sin(rad)};
}

void Bullet::setDirection(sf::Vector2f direction)
{
    this->direction = direction;
}

sf::Vector2f Bullet::getDirection()
{
    return this->direction;
}

sf::Vector2f Bullet::getPosition()
{
    return this->shape.getPosition();
}

sf::Vector2f Bullet::getPreviousPosition()
{
    return this->previousPosition;
}

void Bullet::setPosition(sf::Vector2f pos)
{
    this->shape.setPosition(pos);
}

void Bullet::incrementHitCount()
{
    this->hitCount++;
}

int Bullet::getHitCount() const
{
    return this->hitCount;
}

sf::CircleShape Bullet::getShape()
{
    return this->shape;
}
