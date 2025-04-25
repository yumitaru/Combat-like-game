#include <SFML/Graphics.hpp>
#include "GameEngine.hpp"

int main()
{

    GameEngine eng = GameEngine(new GameState());

    eng.RequestA();
    eng.run();
    return 0;

}
