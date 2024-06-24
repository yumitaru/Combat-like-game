//
// Created by jakub on 24.06.2024.
//

#include "Window.hpp"

Window::Window() {
    this->window = new sf::RenderWindow{ { 1024u, 800u }, "Combat" };
    window->setFramerateLimit(60);
}

Window::~Window() {
    delete window;
}

sf::RenderWindow * Window::getWindow() {
    return this->window;
}

 sf::Event &Window::getEvent() {
    return this->event;
}

void Window::setWindow(sf::RenderWindow * _window) {
    window = _window;
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
