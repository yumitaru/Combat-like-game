//
// Created by jakub on 20.06.2024.
//

#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "State.hpp"


class GameState: public State {

public:
    virtual void DoWorkA() override;
    virtual void DoWorkB() override;

};



#endif //GAMESTATE_H
