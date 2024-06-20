//
// Created by jakub on 20.06.2024.
//

#include "GameEngine.h"




void GameEngine::TransitionTo(State* state)
{
    std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
    if (this->state_ != nullptr)
        delete this->state_;
    this->state_ = state;
    this->state_->set_context(this);
}