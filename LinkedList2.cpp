#include "LinkedList2.h"

LinkedList2::LinkedList2() : Head(nullptr)
{
}

LinkedList2::~LinkedList2()
{
	clear();
}

void LinkedList2::push_back(Bullet2* bullets)
{
	if (Head == nullptr)
	{
		Head = new LinkedListNode2(bullets);
	}
	else
	{
		LinkedListNode2* Current = Head;
		while (Current->next() != nullptr)
		{
			Current = Current->next();
		}
		LinkedListNode2* Temp = new LinkedListNode2(bullets, Current);
		Current->next() = Temp;
	}
}

void LinkedList2::pop_back()
{
	if (Head == nullptr)
	{
		std::cout << "The list is empty!" << std::endl;
	}
	if (Head->next() == nullptr)
	{
		delete Head;
		Head = nullptr;
	}
	else
	{
		LinkedListNode2* Current = Head;
		while (Current->next() != nullptr)
		{
			Current = Current->next();
		}
		Current = nullptr;
		delete Current;
	}
}

void LinkedList2::clear()
{
	LinkedListNode2* Current = Head;
	while (Current != nullptr)
	{
		LinkedListNode2* Temp = Current->next();
		delete Current;
		Current = Temp;
	}
	Head = nullptr;
}

LinkedListNode2* LinkedList2::getHead()
{
	return this->Head;
}



Bullet2* LinkedList2::front()
{
	if (Head == nullptr)
	{
		std::cout << "List is empty!" << std::endl;
	}
	return Head->bullet();
}

Bullet2* LinkedList2::back()
{
	if (Head == nullptr)
	{
		std::cout << "List is empty!" << std::endl;
	}
	LinkedListNode2* Current = Head;
	while (Current->next() != nullptr)
	{
		Current = Current->next();
	}
	return Current->bullet();
}

bool LinkedList2::empty()
{
	if (Head == nullptr)
		return true;
	if (Head != nullptr)
		return false;
}
