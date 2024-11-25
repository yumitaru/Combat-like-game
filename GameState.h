#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "State.h"
#include "Tank1.h"
#include "Tank2.h"
#include "SaveGame.h"
#include "LoadGame.h"
#include <iostream>
#include "LinkedList2.h"
#include "LinkedListNode2.h"
#include "LinkedList1.h"
#include "LinkedListNode1.h"

class GameState: public State
{
	LoadGame load;
	SaveGame save;
	Tank1 player1;
	Tank2 player2;
	LinkedList2 bullets2;
	LinkedListNode2* Current2;
	LinkedList1 bullets1;
	LinkedListNode1* Current1;
	sf::Clock clock1;
	sf::Clock clock2;

public:
	GameState(sf::RenderWindow* window);
	~GameState();

	virtual void endState();
	void updateKeybinds(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = NULL);
	void updateBullets1();
	void bulletKeys1(const float & dt);
	void updateBullets2();
	void bulletKeys2(const float& dt);
};

#endif