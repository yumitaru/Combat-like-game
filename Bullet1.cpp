#include "Bullet1.h"


Bullet1::Bullet1(Tank1 t1)
{
	this->d_x = 0;
	this->d_y = 0;
	this->shape.setPosition(t1.getPosition());
	this->shape.setRadius(10.f);
	this->shape.setOrigin(5.f, 5.f);
	this->shape.setFillColor(sf::Color::Green);
	this->movementSpeed = 200.f;
	this->m = true;
}


Bullet1::~Bullet1()
{
}

void Bullet1::move(const float& dt, const float& dir_x, const float& dir_y)
{
	this->d_x = dir_x;
	this->d_y = dir_y;
	this->shape.move(this->d_x * this->movementSpeed * dt, this->d_y * this->movementSpeed * dt);
}

void Bullet1::create(const float& dt)
{

	this->isMoving();
	if (this->m == true)
	{
		this->move(dt, this->d_x, this->d_y);
	}
}
void Bullet1::update(const float& dt)
{
	
		this->move(dt, this->d_x, this->d_y);
	
}

void Bullet1::render(sf::RenderWindow* target)
{
	target->draw(this->shape);
}


void Bullet1::isMoving()
{
	if (this->m == true) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			this->m = false;
			this->d_y = -1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			this->d_x = -1;
			this->m = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			this->d_y = 1;
			this->m = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			this->d_x = 1;
			this->m = false;
		}
	}
}
