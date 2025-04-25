#ifndef TANKCONTROLLER_HPP
#define TANKCONTROLLER_HPP

#include "SFML/Graphics.hpp"
class TankController {
    sf::Keyboard::Key Up;
	sf::Keyboard::Key Down;
	sf::Keyboard::Key Left;
	sf::Keyboard::Key Right;
	sf::Keyboard::Key Fire;

public:
    TankController() = default;
    ~TankController() = default;

    void setKeys(int i);

    sf::Keyboard::Key getUp() const { return Up; }
    sf::Keyboard::Key getDown() const { return Down; }
    sf::Keyboard::Key getLeft() const { return Left; }
    sf::Keyboard::Key getRight() const { return Right; }
    sf::Keyboard::Key getFire() const { return Fire; }



};










#endif