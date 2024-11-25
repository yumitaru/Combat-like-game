#ifndef TANK2_HPP
#define TANK2_HPP
#include "State.h"
#include "Bullet2.h"
#include <sstream>
class Tank2
{
	sf::RectangleShape shape;
	float movementSpeed;
	int maxBullets = 6;
	float x;
	float y;
public:
	Tank2();
	virtual ~Tank2();

	void setPosition();
	sf::Vector2f getPosition();
	virtual void move(const float& dt, const float dir_x, const float dir_y);
	virtual void update(const float& dt);
	virtual void render(sf::RenderWindow* target);
	std::ostream& operator <<(std::ostream& s);
	std::istream& operator>>(std::istream& s);
};
#endif

