#ifndef LINKEDLISTNODE2_HPP
#define LINKEDLISTNODE2_HPP
#include "Bullet2.h"
class LinkedListNode2
{
	LinkedListNode2* Previous;
	LinkedListNode2* Next;
	Bullet2* Bullets;

public:
	LinkedListNode2(Bullet2* bullets, LinkedListNode2* previous = nullptr, LinkedListNode2* next = nullptr);
	LinkedListNode2*& next();
	LinkedListNode2*& previous();
	Bullet2*& bullet();
	bool operator!=(LinkedListNode2*);
};
#endif

