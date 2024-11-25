#include "Tank1.h"

Tank1::Tank1() : x(0), y(0), movementSpeed(25.f)
{
	this->shape.setSize(sf::Vector2f(50.f,50.f));
	this->shape.setFillColor(sf::Color::White);
	this->shape.setPosition(50.f, 300.f);
	this->shape.setOrigin(sf::Vector2f(25.f,25.f));
}

Tank1::~Tank1()
{
}

void Tank1::move(const float& dt, const float dir_x, const float dir_y)
{
	this->shape.move(dir_x * this->movementSpeed*dt, dir_y * this->movementSpeed * dt);
}

void Tank1::update(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->move(dt, 0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->move(dt, 0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->move(dt, 1.f, 0.f);

}

void Tank1::render(sf::RenderWindow* target)
{
	target->draw(this->shape);
}

std::ostream& Tank1::operator<<(std::ostream& s)
{
	s << this->getPosition().x << " " << this->getPosition().y << std::endl;
	return s;
}

std::istream& Tank1::operator>>(std::istream& s)
{
	s >> this->x >> this->y;
	return s;
}

sf::Vector2f Tank1::getPosition()
{
	return this->shape.getPosition();
}

void Tank1::setPosition()
{
	this->shape.setPosition(this->x, this->y);
}
float Tank1::getX()
{
	return this->x;
}

float Tank1::getY()
{
	return this->y;
}


