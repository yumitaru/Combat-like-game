//
// Created by jakub on 20.06.2024.
//




#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "States/State.hpp"
#include "States/GameState.hpp"
#include "States/MenuState.hpp"

class GameEngine {
    State *state_;

public:
    GameEngine(State *state);
    ~GameEngine();

    void TransitionTo(State *state);

    void RequestA();
    void RequestB();

};



#endif //GAMEENGINE_H
