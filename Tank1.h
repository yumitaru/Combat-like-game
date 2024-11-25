#ifndef TANK1_HPP
#define TANK1_HPP
#include "State.h"
#include "Bullet1.h"
#include <vector>
#include <stack>
#include <iostream>
#include <sstream>
class Bullet1;

class Tank1
{
	sf::RectangleShape shape;
	float movementSpeed;
	float x, y;
public:
	Tank1();
	~Tank1();

	sf::Vector2f getPosition();
	void setPosition();
	float getX();
	float getY();

	virtual void move(const float& dt, const float dir_x, const float dir_y);
	virtual void update(const float & dt);
	virtual void render(sf::RenderWindow * target);
	std::ostream& operator <<(std::ostream& s);
	std::istream& operator >>(std::istream& s);
	
};
#endif

