#include <SFML/Graphics.hpp>
#include "GameEngine.hpp"

int main()
{

    GameEngine eng = GameEngine(new MenuState());

    eng.RequestA();
    return 0;

}
