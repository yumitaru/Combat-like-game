//
// Created by jakub on 20.06.2024.
//

#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "State.h"


class GameState: public State {

public:
    void Handle1() override {
        std::cout << "ConcreteStateA handles request1.\n";
    }

    void Handle2() override {
        std::cout << "ConcreteStateA handles request2.\n";
    }

};



#endif //GAMESTATE_H
