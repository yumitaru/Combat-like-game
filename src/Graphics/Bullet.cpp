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
    this->shape.move(direction * this->speed * dt); // Adjust speed as needed
}

void Bullet::setDirection(float rad)
{
    this->direction = {std::cos(rad), std::sin(rad)};
}
