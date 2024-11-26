#include "LinkedList.h"


LinkedList::~LinkedList()
{
	clear();
}

void LinkedList::push_back(Bullet* bullets)
{
	if (Head == nullptr)
	{
		Head = new LinkedListNode(bullets);
	}
	else
	{
		LinkedListNode* Current = Head;
		while (Current->next() != nullptr)
		{
			Current = Current->next();
		}
		LinkedListNode* Temp = new LinkedListNode(bullets , Current);
		Current->next() = Temp;
	}
}

void LinkedList::pop_back()
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
		LinkedListNode* Current = Head;
		while (Current->next() != nullptr)
		{
			Current = Current->next();
		}
		Current = nullptr;
		delete Current;
	}
}

void LinkedList::clear()
{
	LinkedListNode* Current = Head;
	while(Current != nullptr)
	{
		LinkedListNode* Temp = Current->next();
		delete Current;
		Current = Temp;
	}
	Head = nullptr;
}

LinkedListNode* LinkedList::getHead()
{
	return this->Head;
}



Bullet* LinkedList::front()
{
	if (Head == nullptr)
	{
		std::cout << "List is empty!" << std::endl;
	}
	return Head->bullet();
}

Bullet* LinkedList::back()
{
	if (Head == nullptr)
	{
		std::cout << "List is empty!" << std::endl;
	}
	LinkedListNode* Current = Head;
	while (Current->next() != nullptr)
	{
		Current = Current->next();
	}
	return Current->bullet();
}

bool LinkedList::empty()
{
	if (Head == nullptr)
		return true;
	if (Head != nullptr)
		return false;
}
