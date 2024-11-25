#include "LinkedList1.h"

LinkedList1::LinkedList1(): Head(nullptr)
{
}

LinkedList1::~LinkedList1()
{
	clear();
}

void LinkedList1::push_back(Bullet1* bullets)
{
	if (Head == nullptr)
	{
		Head = new LinkedListNode1(bullets);
	}
	else
	{
		LinkedListNode1* Current = Head;
		while (Current->next() != nullptr)
		{
			Current = Current->next();
		}
		LinkedListNode1* Temp = new LinkedListNode1(bullets , Current);
		Current->next() = Temp;
	}
}

void LinkedList1::pop_back()
{
	if (Head == nullptr)
	{
		std::cout << "The list is empty!" << std::endl;
	}
	if(Head->next() == nullptr)
	{
		delete Head;
		Head = nullptr;
	}
	else
	{
		LinkedListNode1* Current = Head;
		while (Current->next() != nullptr)
		{
			Current = Current->next();
		}
		Current = nullptr;
		delete Current;
	}
}

void LinkedList1::clear()
{
	LinkedListNode1* Current = Head;
	while(Current != nullptr)
	{
		LinkedListNode1* Temp = Current->next();
		delete Current;
		Current = Temp;
	}
	Head = nullptr;
}

LinkedListNode1* LinkedList1::getHead()
{
	return this->Head;
}



Bullet1* LinkedList1::front()
{
	if (Head == nullptr)
	{
		std::cout << "List is empty!" << std::endl;
	}
	return Head->bullet();
}

Bullet1* LinkedList1::back()
{
	if (Head == nullptr)
	{
		std::cout << "List is empty!" << std::endl;
	}
	LinkedListNode1* Current = Head;
	while (Current->next() != nullptr)
	{
		Current = Current->next();
	}
	return Current->bullet();
}

bool LinkedList1::empty()
{
	if (Head == nullptr)
		return true;
	if (Head != nullptr)
		return false;
}
