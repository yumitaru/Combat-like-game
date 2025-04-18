#include "LinkedListNode.h"

LinkedListNode::LinkedListNode(Bullet*& bullets, LinkedListNode* previous, LinkedListNode* next) : Bullets(bullets), Previous(previous), Next(next)
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

Bullet* LinkedListNode::bullet()
{
    if (this->Bullets == nullptr)
    {
        std::cerr << "Error: Bullet is nullptr in LinkedListNode::bullet()" << std::endl;
    }
    return this->Bullets;
}

void LinkedListNode::updateBullet(const float &dt)
{
    if (this->Bullets != nullptr)
    {
        this->Bullets->update(dt);
    }
    else
    {
        std::cerr << "Error: Bullet is nullptr in LinkedListNode::updateBullet()" << std::endl;
    }
}


void LinkedListNode::renderBullet(sf::RenderWindow *target)
{
    if (this->Bullets != nullptr)
    {
        this->Bullets->render(target);
    }
    else
    {
        std::cerr << "Error: Bullet is nullptr in LinkedListNode::renderBullet()" << std::endl;
    }
}

bool LinkedListNode::operator!=(LinkedListNode *l)
{
	if (this == l)
		return false;
	else
		return true;
}

