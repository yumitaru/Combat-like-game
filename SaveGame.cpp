#include "SaveGame.h"

SaveGame::SaveGame()
{
}


SaveGame::~SaveGame()
{
}




void SaveGame::update(Tank1 t1, Tank2 t2)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        this->plik.open("save.txt");
        if (plik.is_open())
        {
            t1.operator<<(plik);
            t2.operator<<(plik);
        }
        plik.close();
    }
}
