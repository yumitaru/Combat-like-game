//
// Created by jakub on 20.06.2024.
//

#include "State.hpp"

State::~State() {
}

void State::set_engine(GameEngine *engine)  {
    this->game_engine_ = engine;
}
