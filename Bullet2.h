#ifndef BULLET2_HPP
#define BULLET2_HPP
#include "State.h"
class Tank2;

class Bullet2
{
	sf::CircleShape shape;
	sf::Vector2f direction;
	float movementSpeed;
	bool m;
	float d_x;
	float d_y;

public:
	Bullet2();
	Bullet2(Tank2);
	virtual ~Bullet2();

	const sf::FloatRect getBounds() const;

	void create(const float& dt);
	virtual void move(const float& dt, const float dir_x, const float dir_y);
	virtual void update(const float& dt);
	virtual void render(sf::RenderWindow* target);
	void isMoving();


};

#endif