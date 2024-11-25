#ifndef SAVEGAME_HPP
#define SAVEGAME_HPP
#include "State.h"
#include <iostream>
#include <fstream>
class SaveGame
{
	std::ofstream plik;
public:
	SaveGame();
	virtual ~SaveGame();
	void update(Tank1, Tank2);
};

#endif // !SAVEGAME_HPP