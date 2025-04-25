#include "TankController.hpp"

void TankController::setKeys(int i)
{
    switch (i) {
        case 0:
            Up = sf::Keyboard::W;
            Down = sf::Keyboard::S;
            Left = sf::Keyboard::A;
            Right = sf::Keyboard::D;
            Fire = sf::Keyboard::Space;
            break;
        case 1:
            Up = sf::Keyboard::Up;
            Down = sf::Keyboard::Down;
            Left = sf::Keyboard::Left;
            Right = sf::Keyboard::Right;
            Fire = sf::Keyboard::RControl;
            break;
        default:
            break;
    }
}