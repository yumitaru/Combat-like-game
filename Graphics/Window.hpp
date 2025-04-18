//
// Created by jakub on 24.06.2024.
//

#ifndef WINDOW_HPP
#define WINDOW_HPP
#include "SFML/Graphics.hpp"


class Window {

    std::unique_ptr<sf::RenderWindow> window;
    sf::Event event;
public:
    Window();
    ~Window() = default;
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    sf::RenderWindow * getWindow();
    sf::Event &getEvent();
    void setEvent(sf::Event);
    bool getPoolEvent();
    void close();
    void clear(sf::Color);
    void display();
    bool isOpen();




};



#endif //WINDOW_HPP
