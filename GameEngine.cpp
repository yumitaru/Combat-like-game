//
// Created by jakub on 20.06.2024.
//

#include "GameEngine.hpp"


void GameEngine::initWindow() {
    this->window = new sf::RenderWindow{ { 1024u, 800u }, "Combat" };
    window->setFramerateLimit(60);
    //
    // while (window->isOpen())
    // {
    //     for (auto event = sf::Event{}; window->pollEvent(event);)
    //     {
    //         if (event.type == sf::Event::Closed)
    //         {
    //             window->close();
    //         }
    //     }
    //
    //     window->clear();
    //     window->display();
    // }
}

GameEngine::GameEngine(State *state): state_(nullptr) {
    initWindow();
    TransitionTo(state);
}

GameEngine::~GameEngine()  {
    delete state_;
}

void GameEngine::TransitionTo(State *state)  {
    if (this->state_ != nullptr)
        delete this->state_;
    this->state_ = state;
    this->state_->set_engine(this);
}

void GameEngine::RequestA()  {
    state_->DoWorkA();
}

void GameEngine::RequestB() {
    state_->DoWorkB();
}

void GameEngine::update() {
    while (window->pollEvent(this->event))
    {
        if (this->event.type == sf::Event::Closed)
            this->window->close();
    }
    if (this->state_ != nullptr)
    {
        this->state_->update(this->dt);

        if (this->state_->getQuit())
        {
            this->state_->endState();
            delete this->state_;
        }
    }
    // End of application
    else
        this->window->close();
}

void GameEngine::render() {
    window->clear(sf::Color(14, 134, 212));

        this->state_->render(window);

    window->display();
}

void GameEngine::run() {
    while (this->window->isOpen())
    {
        this->update();

        this->render();
    }
}
