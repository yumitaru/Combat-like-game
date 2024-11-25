#ifndef LINKEDLIST2_HPP
#define LINKEDLIST2_HPP
#include "LinkedListNode2.h"
#include "Bullet2.h"
#include <iostream>
class LinkedList2
{
	LinkedListNode2* Head;
	Bullet2* bullets;
public:
	LinkedList2();
	~LinkedList2();

	void push_back(Bullet2* bullets);
	void pop_back();
	void clear();
	LinkedListNode2* getHead();


	Bullet2* front();
	Bullet2* back();
	bool empty();
};

#endif