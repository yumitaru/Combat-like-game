//
// Created by jakub on 20.06.2024.
//

#include "GameEngine.hpp"



GameEngine::GameEngine(State *state): state_(nullptr) {
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

void GameEngine::updateDt()
{
    this->dt = this->dtClock.restart().asSeconds();
}

void GameEngine::update() {
    while (window.getPoolEvent())
    {
        if (this->window.getEvent().type == sf::Event::Closed)
            this->window.close();
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
        this->window.close();
}

void GameEngine::render() {
    window.clear(sf::Color(135, 27, 14));

        this->state_->render(window.getWindow());

    window.display();
}

void GameEngine::run() {
    while (this->window.isOpen())
    {
        this->updateDt();

        this->update();

        this->render();
    }
}
