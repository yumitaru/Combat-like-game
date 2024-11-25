#include "LinkedListNode2.h"

LinkedListNode2::LinkedListNode2(Bullet2* bullets, LinkedListNode2* previous, LinkedListNode2* next) : Bullets(bullets), Previous(previous), Next(next)
{

}

LinkedListNode2*& LinkedListNode2::next()
{
	return this->Next;
}

LinkedListNode2*& LinkedListNode2::previous()
{
	return this->Previous;
}

Bullet2*& LinkedListNode2::bullet()
{
	return Bullets;
}

bool LinkedListNode2::operator!=(LinkedListNode2* l)
{
	if (this == l)
		return false;
	else
		return true;
}
