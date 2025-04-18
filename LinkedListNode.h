#ifndef LINKEDLISTNODE1_HPP
#define LINKEDLISTNODE1_HPP
#include "Bullet.h"


class LinkedListNode
{
	LinkedListNode* Previous;
	LinkedListNode* Next;
	Bullet* Bullets;

public:
	LinkedListNode( Bullet*& bullets, LinkedListNode* previous = nullptr, LinkedListNode* next = nullptr);
	LinkedListNode*& next();
	LinkedListNode*& previous();
	Bullet* bullet();

	virtual void updateBullet(const float& dt);
	virtual void renderBullet(sf::RenderWindow* target);
	bool operator!=(LinkedListNode*);
};
#endif

