#ifndef LINKEDLISTNODE1_HPP
#define LINKEDLISTNODE1_HPP
#include "Bullet.h"


class LinkedListNode
{
	LinkedListNode* Previous;
	LinkedListNode* Next;
	Bullet* Bullets;

public:
	LinkedListNode( Bullet* bullets, LinkedListNode* previous = nullptr, LinkedListNode* next = nullptr);
	LinkedListNode*& next();
	LinkedListNode*& previous();
	Bullet*& bullet();
	bool operator!=(LinkedListNode*);
};
#endif

