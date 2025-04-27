#include "Tank.hpp"

Tank::Tank()
{
    this->shape.setSize(sf::Vector2f(50.f,50.f));
	this->shape.setFillColor(sf::Color::Blue);

	this->shape.setOrigin(sf::Vector2f(25.f,25.f));
    this->shape.setPosition(75.f, 400.f);
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

    for (auto &bullet : bullets)
    {
        bullet.render(target);
    }

}

void Tank::update(const float &dt)
{
    std::cout << "Rectangle Position: " << this->shape.getPosition().x << ", " << this->shape.getPosition().y << std::endl;

    std::cout << "Bullets size: " << bullets.size() << std::endl;
    
    this->rotation = this->shape.getRotation(); // in degrees
    this->radians = rotation * 3.14159265f / 180.f;

    this->direction = {std::cos(radians), std::sin(radians)};

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
    if (sf::Keyboard::isKeyPressed(this->controller.getFire()) && bulletCooldown.getElapsedTime().asSeconds() > 0.5f)
    {
        Bullet bullet(this->shape.getPosition());
        bullet.setDirection(this->radians);
        bullet.update(dt);
        bullets.push_back(bullet);
        bulletCooldown.restart();
    }

    for (auto &bullet : bullets)
    {
        bullet.update(dt);
    }
}
