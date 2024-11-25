#ifndef GAME_HPP
#define GAME_HPP
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include <iostream>
#include <stack>
#include "Tank1.h"
#include "Tank2.h"
#include "GameState.h"

class Game
{
	sf::RenderWindow *window;
	sf::Event e;
	sf::Clock dtClock;
	std::stack<State*> states;
	float dt; 
	
	void initWindow();
	void initStates();

public:
	Game();
	~Game();
	void updateDt();
	void updateEvents();
	void update();
	void render();
	void run();
};

#endif
