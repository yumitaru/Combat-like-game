//
// Created by jakub on 20.06.2024.
//

#ifndef STATE_H
#define STATE_H
#include "SFML/Graphics.hpp"
#include <iostream>
class GameEngine;

class State {

    protected:
    GameEngine * game_engine_;
    bool quit;

    public:
    virtual ~State();

    void set_engine(GameEngine *engine);
    const bool& getQuit() const;
    bool& setQuit(bool q);

    virtual void DoWorkA() = 0;
    virtual void DoWorkB() = 0;
    virtual void update(const float & dt) = 0;
    virtual void endState() = 0;
    virtual void render(sf::RenderTarget *target = nullptr) = 0;


};



#endif //STATE_H
