//
// Created by jakub on 20.06.2024.
//

#include "GameState.hpp"

void GameState::startState()
{
    player2.setPosition(sf::Vector2f(925.f, 400.f));
    player2.setKeys(1);
}

void GameState::update(const float &dt)
{

    this->player.update(dt);
    this->player2.update(dt);
    this->wallCollision.update(dt, this->player, this->map);
    this->wallCollision.update(dt, this->player2, this->map);
    this->wallCollision.checkTankBulletCollision(this->player, this->player2);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        this->setQuit(true);
}

void GameState::endState() {
}

void GameState::render(sf::RenderTarget *target) {
    
    this->map.render(target);

    this->player.render(target);
    this->player2.render(target);
}
