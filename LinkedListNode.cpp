#include "LinkedListNode.h"

LinkedListNode::LinkedListNode(Bullet* bullets, LinkedListNode* previous, LinkedListNode* next) : Bullets(bullets), Previous(previous), Next(next)
{

}

LinkedListNode*& LinkedListNode::next()
{
	return this->Next;
}

LinkedListNode*& LinkedListNode::previous()
{
	return this->Previous;
}

Bullet*& LinkedListNode::bullet()
{
	return Bullets;
}

bool LinkedListNode::operator!=(LinkedListNode* l)
{
	if (this == l)
		return false;
	else
		return true;
}

