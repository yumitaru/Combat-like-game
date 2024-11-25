#include "Game.h"



void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Combat");
    window->setVerticalSyncEnabled(true);
    this->window->setFramerateLimit(60);
}

void Game::initStates()
{
    this->states.push(new GameState(this->window));
}

Game::Game()
{
    this->initWindow();
    this->initStates();
}

Game::~Game()
{
    delete this->window;

    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }

}


void Game::updateDt()
{
    
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateEvents()
{
    while (this->window->pollEvent(this->e))
    {
        if (this->e.type == sf::Event::Closed)
        {
            this->window->close();
        }
    }
}

void Game::update()
{
    this->updateEvents();

    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);
        if (this->states.top()->getEnd())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    else
    {
        this->window->close();
    }
}

void Game::render()
{
    this->window->clear();

    if (!this->states.empty())
        this->states.top()->render();

    this->window->display();
}

void Game::run()
{

    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }

}
