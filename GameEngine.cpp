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
