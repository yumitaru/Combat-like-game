//
// Created by jakub on 20.06.2024.
//

#include "GameState.hpp"

void GameState::DoWorkA() {
    std::cout << "Doing work A" << std::endl;
}

void GameState::DoWorkB() {
    std::cout << "Doing work B" << std::endl;
}

void GameState::update(const float &dt) {
}

void GameState::endState() {
}

void GameState::render(sf::RenderTarget *target) {
}
