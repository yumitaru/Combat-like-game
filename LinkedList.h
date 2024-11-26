#ifndef LINKEDLIST1_HPP
#define LINKEDLIST1_HPP
#include "LinkedListNode.h"
#include <iostream>

class LinkedList
{
	LinkedListNode* Head;
	Bullet* bullets;
public:
	LinkedList(): Head(nullptr) {};
	~LinkedList();

	void push_back(Bullet* bullets);
	void pop_back();
	void clear();
	LinkedListNode* getHead();


	Bullet* front();
	Bullet* back();
	bool empty();
};

#endif