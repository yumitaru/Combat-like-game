//
// Created by jakub on 24.06.2024.
//

#ifndef WINDOW_HPP
#define WINDOW_HPP
#include "SFML/Graphics.hpp"


class Window {

    sf::RenderWindow * window;
    sf::Event event;
public:
    Window();
    ~Window();
    sf::RenderWindow * getWindow();
    sf::Event &getEvent();
    void setWindow(sf::RenderWindow*);
    void setEvent(sf::Event);
    bool getPoolEvent();
    void close();
    void clear(sf::Color);
    void display();
    bool isOpen();




};



#endif //WINDOW_HPP
