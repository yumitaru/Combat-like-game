#include "Bullet2.h"

Bullet2::Bullet2()
{
	this->d_x = 0;
	this->d_y = 0;
	this->shape.setRadius(10.f);
	this->shape.setFillColor(sf::Color::Green);
	this->movementSpeed = 200.f;
	this->shape.setOrigin(10.f, 10.f);
	this->m = false;
}
Bullet2::Bullet2(Tank2 t2)
{
	this->d_x = 0;
	this->d_y = 0;
	this->shape.setPosition(t2.getPosition());
	this->shape.setRadius(10.f);
	this->shape.setOrigin(5.f, 5.f);
	this->shape.setFillColor(sf::Color::Green);
	this->movementSpeed = 200.f;
	this->m = true;
}

Bullet2::~Bullet2()
{
}

void Bullet2::create(const float& dt)
{
	this->isMoving();
	if (this->m == true)
	{
		this->move(dt, this->d_x, this->d_y);
	}
}

void Bullet2::move(const float& dt, const float dir_x, const float dir_y)
{
	this->d_x = dir_x;
	this->d_y = dir_y;
	this->shape.move(this->d_x * this->movementSpeed * dt, this->d_y * this->movementSpeed * dt);
}

void Bullet2::update(const float& dt)
{
	this->move(dt, this->d_x, this->d_y);
}

void Bullet2::render(sf::RenderWindow* target)
{
	target->draw(this->shape);
}

const sf::FloatRect Bullet2::getBounds() const
{
	return this->shape.getGlobalBounds();
}

void Bullet2::isMoving()
{
	if (this->m == true) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
		{
			this->m = false;
			this->d_y = -1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
		{
			this->d_x = -1;
			this->m = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
		{
			this->d_y = 1;
			this->m = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
		{
			this->d_x = 1;
			this->m = false;
		}
	}
}
