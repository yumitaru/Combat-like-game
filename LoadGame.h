#ifndef LOADGAME_HPP
#define LOADGAME_HPP
#include "State.h"
#include <iostream>
#include <fstream>
class LoadGame
{
	std::ifstream plik;
	bool loading;
public:
	LoadGame();
	virtual ~LoadGame();
	void loadFalse();
	
	void update(Tank1&, Tank2&);
	bool isLoaded();
	bool operator==(const bool&);

};

#endif

