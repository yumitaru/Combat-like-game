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
    virtual void update(const float & dt) override;
    virtual void endState() override;
    virtual void render(sf::RenderTarget *target = nullptr) override;


};



#endif //MENUSTATE_H
