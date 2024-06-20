//
// Created by jakub on 20.06.2024.
//

#ifndef MENUSTATE_H
#define MENUSTATE_H
#include "../States/State.h"


class MenuState: public State {

public:
    void Handle1() override{
        std::cout << "ConcreteStateA handles request1.\n";
    }

    void Handle2() override {
        std::cout << "ConcreteStateA handles request2.\n";
    }


};



#endif //MENUSTATE_H
