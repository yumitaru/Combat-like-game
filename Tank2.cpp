#include "Tank2.h"

Tank2::Tank2()
{
	this->x = 0;
	this->y = 0;
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->shape.setFillColor(sf::Color::White);
	this->shape.setOrigin(sf::Vector2f(25.f, 25.f));
	this->shape.setPosition(750.f, 300.f);
	this->movementSpeed = 25.f;
}

Tank2::~Tank2()
{
}


void Tank2::setPosition()
{
	this->shape.setPosition(sf::Vector2f(this->x, this->y));

}

sf::Vector2f Tank2::getPosition()
{
	return this->shape.getPosition();
}
void Tank2::move(const float& dt, const float dir_x, const float dir_y)
{
	this->shape.move(dir_x * this->movementSpeed * dt, dir_y * this->movementSpeed * dt);
}

void Tank2::update(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		this->move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		this->move(dt, 0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->move(dt, 1.f, 0.f);
}

void Tank2::render(sf::RenderWindow* target)
{
	target->draw(this->shape);
}

std::ostream& Tank2::operator<<(std::ostream& s)
{
	s << this->getPosition().x << " " << this->getPosition().y << std::endl;
	return s;
}
std::istream& Tank2::operator>>(std::istream& s)
{
	s >> this->x >> this->y;
	return s;
}
