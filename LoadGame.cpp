#include "LoadGame.h"

LoadGame::LoadGame()
{
	this->loading = false;
}

LoadGame::~LoadGame()
{
}

void LoadGame::update(Tank& t1, Tank& t2)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		this->plik.open("save.txt");
		if (plik.is_open())
		{
			t1.operator>>(plik);
			t2.operator>>(plik);

			plik.close();
		}
		this->loading = true;
	}
	

}

void LoadGame::loadFalse()
{
	this->loading = false;
}

bool LoadGame::isLoaded()
{
	return loading;
}

bool LoadGame::operator==(const bool& p)
{
	if (this->loading == p)
		return true;
	else return false;
}
