#include <SFML/Graphics.hpp>
#include "GameEngine.hpp"

int main()
{

    GameEngine eng = GameEngine(new MenuState());

    eng.RequestA();
    // auto window = sf::RenderWindow{ { 1920u, 1080u }, "CMake SFML Project" };
    // window.setFramerateLimit(144);
    //
    // while (window.isOpen())
    // {
    //     for (auto event = sf::Event{}; window.pollEvent(event);)
    //     {
    //         if (event.type == sf::Event::Closed)
    //         {
    //             window.close();
    //         }
    //     }
    //
    //     window.clear();
    //     window.display();
    // }
}
