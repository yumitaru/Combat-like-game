#include "State.h"

State::State()
{
	this->window;
	this->end = false;
}

State::State(sf::RenderWindow* window)
{
	this->window = window;
	this->end = false;
}

State::~State()
{
}

const bool& State::getEnd() const
{
	return this->end;
}

sf::RenderWindow *State::getWindow()
{
	return this->window;
}

void State::checkForEnd()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->end = true;
	}
}


