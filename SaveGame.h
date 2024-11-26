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
	void update(Tank, Tank);
};

#endif // !SAVEGAME_HPP