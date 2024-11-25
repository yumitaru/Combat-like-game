#include "LinkedListNode1.h"

LinkedListNode1::LinkedListNode1(Bullet1* bullets, LinkedListNode1* previous, LinkedListNode1* next) : Bullets(bullets), Previous(previous), Next(next)
{

}

LinkedListNode1*& LinkedListNode1::next()
{
	return this->Next;
}

LinkedListNode1*& LinkedListNode1::previous()
{
	return this->Previous;
}

Bullet1*& LinkedListNode1::bullet()
{
	return Bullets;
}

bool LinkedListNode1::operator!=(LinkedListNode1* l)
{
	if (this == l)
		return false;
	else
		return true;
}

