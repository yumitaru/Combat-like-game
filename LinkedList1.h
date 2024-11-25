#ifndef LINKEDLIST1_HPP
#define LINKEDLIST1_HPP
#include "LinkedListNode1.h"
#include "Bullet1.h"
#include <iostream>
class LinkedList1
{
	LinkedListNode1* Head;
	Bullet1* bullets;
public:
	LinkedList1();
	~LinkedList1();

	void push_back(Bullet1* bullets);
	void pop_back();
	void clear();
	LinkedListNode1* getHead();


	Bullet1* front();
	Bullet1* back();
	bool empty();
};

#endif