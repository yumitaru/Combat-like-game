#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "State.h"
#include "Tank.h"
#include "SaveGame.h"
#include "LoadGame.h"
#include <iostream>
#include "LinkedList.h"
#include "LinkedListNode.h"

class GameState: public State
{
	LoadGame load;
	SaveGame save;
	Tank player1;
	Tank player2;
	
	// LinkedList1 bullets1;
	// LinkedListNode1* Current1;
	sf::Clock clock1;
	sf::Clock clock2;

public:
	GameState(sf::RenderWindow* window);
	~GameState();

	virtual void endState();
	void updateKeybinds(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = NULL);
	void updateBullets(Tank &player);
	void bulletKeys(Tank &player, const float & dt);
};

#endif