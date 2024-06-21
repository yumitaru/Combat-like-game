//
// Created by jakub on 20.06.2024.
//

#ifndef MENUSTATE_H
#define MENUSTATE_H
#include "State.hpp"


class MenuState: public State {

public:
    virtual void DoWorkA() override;
    virtual void DoWorkB() override;


};



#endif //MENUSTATE_H
