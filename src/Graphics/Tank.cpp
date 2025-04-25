#include "Tank.hpp"

Tank::Tank()
{
    this->shape.setSize(sf::Vector2f(50.f,50.f));
	this->shape.setFillColor(sf::Color::White);
	this->shape.setPosition(50.f, 300.f);
	this->shape.setOrigin(sf::Vector2f(25.f,25.f));
    this->controller.setKeys(0);
    this->speed = 50.f;
}

Tank::~Tank()
{
}

sf::RectangleShape &Tank::getShape()
{
    return this->shape;
}

void Tank::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
}

void Tank::update(const float &dt)
{
    std::cout << "Rectangle Position: " << this->shape.getPosition().x << ", " << this->shape.getPosition().y << std::endl;

    rotation = this->shape.getRotation(); // in degrees
    radians = rotation * 3.14159265f / 180.f;

    direction = {std::cos(radians), std::sin(radians)};

    if (sf::Keyboard::isKeyPressed(this->controller.getUp()))
    {
        this->shape.move(direction * speed * dt);
    }
    if (sf::Keyboard::isKeyPressed(this->controller.getDown()))
    {
        this->shape.move(-direction * speed * dt);
    }
    if (sf::Keyboard::isKeyPressed(this->controller.getLeft()))
    {
        this->shape.rotate(-100.f * dt); // Adjust this value for your desired turn rate
    }
    if (sf::Keyboard::isKeyPressed(this->controller.getRight()))
    {
        this->shape.rotate(100.f * dt);
    }
    if (sf::Keyboard::isKeyPressed(this->controller.getFire()))
    {
        // Fire logic here
    }
}
