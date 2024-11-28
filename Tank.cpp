#include "Tank.h"


Tank::Tank(): x(0), y(0), movementSpeed(25.f)
{
	this->shape.setSize(sf::Vector2f(50.f,50.f));
	this->shape.setFillColor(sf::Color::White);
	this->shape.setPosition(50.f, 300.f);
	this->shape.setOrigin(sf::Vector2f(25.f,25.f));
	this->setKeys(1);
}

Tank::Tank(int i) : x(0), y(0), movementSpeed(25.f)
{
	this->shape.setSize(sf::Vector2f(50.f,50.f));
	this->shape.setFillColor(sf::Color::White);
	this->shape.setPosition(50.f, 300.f);
	this->shape.setOrigin(sf::Vector2f(25.f,25.f));
	this->setKeys(i);
}

Tank::~Tank()
{
}

void Tank::move(const float& dt, const float dir_x, const float dir_y)
{
	this->shape.move(dir_x * this->movementSpeed*dt, dir_y * this->movementSpeed * dt);
}

void Tank::update(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(this->Up))
	{
		this->move(dt, 0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(this->Left))
		this->move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(this->Down))
		this->move(dt, 0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(this->Right))
		this->move(dt, 1.f, 0.f);

}

void Tank::render(sf::RenderWindow* target)
{
	target->draw(this->shape);
}

std::ostream& Tank::operator<<(std::ostream& s)
{
	s << this->getPosition().x << " " << this->getPosition().y << std::endl;
	return s;
}

std::istream& Tank::operator>>(std::istream& s)
{
	s >> this->x >> this->y;
	return s;
}

sf::Keyboard::Key Tank::getUp()
{
    return this->Up;
}

sf::Keyboard::Key Tank::getDown()
{
    return this->Down;
}

sf::Keyboard::Key Tank::getLeft()
{
    return this->Left;
}

sf::Keyboard::Key Tank::getRight()
{
    return this->Right;
}

sf::Keyboard::Key Tank::getFireKey()
{
    return this->Fire;
}



LinkedListNode* Tank::getCurrent()
{
    return this->Current;
}

void Tank::bulletsPush_back(Bullet *bullets)
{

	this->bullets.push_back(bullets);
}

void Tank::bulletsPop_back()
{
	this->bullets.pop_back();
}

void Tank::bulletsClear()
{
	this->bullets.clear();
}

Bullet *Tank::front()
{
    return this->bullets.front();
}

Bullet *Tank::back()
{
    return this->bullets.back();
}

bool Tank::empty()
{
    return this->bullets.empty();
}

LinkedListNode *Tank::getHead()
{
    return this->bullets.getHead();
}

LinkedListNode *&Tank::next()
{
    return this->Current->next();
}

LinkedListNode *&Tank::previous()
{
    return this->Current->previous();
}

Bullet *Tank::bullet()
{
    return this->Current->bullet();
}

bool Tank::operator!=(LinkedListNode * l)
{
    return this->Current->operator!=(l);
}

void Tank::setCurrent(LinkedListNode * current)
{
	this->Current = current;
}

void Tank::renderBullet(sf::RenderWindow *target)
{
	// std::cout << " jo; " << this->Current->bullet() << std::endl;
	this->Current->bullet()->render(target);
	
}

sf::Vector2f Tank::getPosition()
{
	return this->shape.getPosition();
}

void Tank::setPosition()
{
	this->shape.setPosition(this->x, this->y);
}

void Tank::startPos(int x, int y)
{
	this->x = x;
	this->y = y;
	this->shape.setPosition(this->x,this->y);
}

float Tank::getX()
{
	return this->x;
}

float Tank::getY()
{
	return this->y;
}

void Tank::setKeys(int i)
{
	if (i==1)
	{
			this->Up = sf::Keyboard::W;
			this->Down = sf::Keyboard::S;
			this->Left = sf::Keyboard::A;
			this->Right = sf::Keyboard::D;
			this->Fire = sf::Keyboard::Space;
	}
	else
	{
			this->Up = sf::Keyboard::Up;
			this->Down = sf::Keyboard::Down;
			this->Left = sf::Keyboard::Left;
			this->Right = sf::Keyboard::Right;
			this->Fire = sf::Keyboard::Enter;
	}
}
