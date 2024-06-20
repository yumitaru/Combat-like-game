//
// Created by jakub on 20.06.2024.
//

#include "States/State.h"


#ifndef GAMEENGINE_H
#define GAMEENGINE_H



class GameEngine {
    State *state_;

public:
    GameEngine(State *state) : state_(nullptr) {
        this->TransitionTo(state);
    }
    ~GameEngine() {
        delete state_;
    }
    /**
     * The Context allows changing the State object at runtime.
     */
    void TransitionTo(State *state);
    /**
     * The Context delegates part of its behavior to the current State object.
     */
    void Request1() {
        this->state_->Handle1();
    }
    void Request2() {
        this->state_->Handle2();
    }
};



#endif //GAMEENGINE_H
