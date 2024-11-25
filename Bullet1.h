#ifndef BULLET1_HPP
#define BULLET1_HPP
#include "State.h"
class Tank1;

class Bullet1
{
	sf::CircleShape shape;
	float movementSpeed;
	bool m;
	float d_x;
	float d_y;
	
public:
	Bullet1(Tank1);
	virtual ~Bullet1();

	void create(const float& dt);
	virtual void move(const float& dt, const float& dir_x, const float& dir_y);
	virtual void update(const float& dt);
	virtual void render(sf::RenderWindow* target);
	void isMoving();


};

#endif