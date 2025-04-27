//
// Created by jakub on 24.06.2024.
//

#include "Window.hpp"

Window::Window() {
    this->window = std::make_unique<sf::RenderWindow>(sf::VideoMode(1000, 800), "Combat");
    window->setFramerateLimit(60);
}


sf::RenderWindow * Window::getWindow() {
    return window.get();
}

 sf::Event &Window::getEvent() {
    return this->event;
}



void Window::setEvent(sf::Event _event) {
    event = _event;
}

bool Window::getPoolEvent() {
    return this->window->pollEvent(this->event);
}

void Window::close() {
    this->window->close();
}

void Window::clear(sf::Color color) {
    this->window->clear(color);
}

void Window::display() {
    this->window->display();
}

bool Window::isOpen() {
    return this->window->isOpen();
}
