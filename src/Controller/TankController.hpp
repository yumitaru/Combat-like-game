#ifndef TANKCONTROLLER_HPP
#define TANKCONTROLLER_HPP

#define WIDTH 1000
#define HEIGHT 800

#include "SFML/Graphics.hpp"
#include <iostream>
class TankController {
    int keys;

    sf::Keyboard::Key Up;
	sf::Keyboard::Key Down;
	sf::Keyboard::Key Left;
	sf::Keyboard::Key Right;
	sf::Keyboard::Key Fire;

public:
    TankController() = default;
    ~TankController() = default;

    void setKeys(int i);
    int getKeys() const;

    sf::Keyboard::Key getUp() const { return Up; }
    sf::Keyboard::Key getDown() const { return Down; }
    sf::Keyboard::Key getLeft() const { return Left; }
    sf::Keyboard::Key getRight() const { return Right; }
    sf::Keyboard::Key getFire() const { return Fire; }



};










#endif