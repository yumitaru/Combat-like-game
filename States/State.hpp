//
// Created by jakub on 20.06.2024.
//

#ifndef STATE_H
#define STATE_H
#include <iostream>
class GameEngine;

class State {

    protected:
    GameEngine * game_engine_;

    public:
    virtual ~State();

    void set_engine(GameEngine *engine);

    virtual void DoWorkA() = 0;
    virtual void DoWorkB() = 0;

};



#endif //STATE_H
