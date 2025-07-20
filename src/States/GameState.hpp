//
// Created by jakub on 20.06.2024.
//

#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "State.hpp"


class GameState: public State {

    Tank player;
    Tank player2;
    Map map;
    WallCollision wallCollision;

public:

    virtual void startState() override;
    virtual void update(const float & dt) override;
    virtual void endState() override;
    virtual void render(sf::RenderTarget *target = nullptr) override;

};



#endif //GAMESTATE_H
