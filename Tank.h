#ifndef TANK1_HPP
#define TANK1_HPP


#include "LinkedList.h"

class Tank
{
	sf::RectangleShape shape;
	LinkedList bullets;
	LinkedListNode* Current;
	float movementSpeed;
	float x, y;
	sf::Keyboard::Key Up;
	sf::Keyboard::Key Down;
	sf::Keyboard::Key Left;
	sf::Keyboard::Key Right;
	sf::Keyboard::Key Fire;
public:
	Tank();
	Tank(int i);
	~Tank();

	sf::Vector2f getPosition();
	void setPosition();
	void startPos(int x, int y);
	float getX();
	float getY();
	void setKeys(int i);

	virtual void move(const float& dt, const float dir_x, const float dir_y);
	virtual void update(const float & dt);
	virtual void render(sf::RenderWindow * target);
	std::ostream& operator <<(std::ostream& s);
	std::istream& operator >>(std::istream& s);
	sf::Keyboard::Key getUp();
	sf::Keyboard::Key getDown();
	sf::Keyboard::Key getLeft();
	sf::Keyboard::Key getRight();
	sf::Keyboard::Key getFireKey();

	void isMoving();
	LinkedListNode *getCurrent();

	// Linked list methods
	void bulletsPush_back(Bullet* bullets);
	void bulletsPop_back();
	void bulletsClear();
	Bullet* front();
	Bullet* back();
	bool empty();
	LinkedListNode* getHead();

	// Linked list node methods
	LinkedListNode*& next();
	LinkedListNode*& previous();
	Bullet* bullet();
	bool operator!=(LinkedListNode*);


	void setCurrent(LinkedListNode*);

	virtual void renderBullet(sf::RenderWindow* target);

	
};
#endif

