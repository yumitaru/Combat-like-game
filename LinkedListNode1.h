#ifndef LINKEDLISTNODE1_HPP
#define LINKEDLISTNODE1_HPP
#include "Bullet1.h"
class LinkedListNode1
{
	LinkedListNode1* Previous;
	LinkedListNode1* Next;
	Bullet1* Bullets;

public:
	LinkedListNode1( Bullet1* bullets, LinkedListNode1* previous = nullptr, LinkedListNode1* next = nullptr);
	LinkedListNode1*& next();
	LinkedListNode1*& previous();
	Bullet1*& bullet();
	bool operator!=(LinkedListNode1*);
};
#endif

