//
// Created by jakub on 20.06.2024.
//

#include <iostream>
#include "GameState.h"
#include "MenuState.h"

#ifndef STATE_H
#define STATE_H



class State {
    /**
     * @var Context
     */
    protected:
    GameEngine *context_;

    public:
    virtual ~State() {
    }

    void set_context(GameEngine *context) {
        this->context_ = context;
    }

    virtual void Handle1() = 0;
    virtual void Handle2() = 0;
};



#endif //STATE_H
