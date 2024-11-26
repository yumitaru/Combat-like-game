#ifndef STATE_HPP
#define STATE_HPP

#include "SFML/Graphics.hpp"
#include "Tank.h"

class Tank;

class State
{
	sf::RenderWindow* window;
	bool end;

public:
	State();
	State(sf::RenderWindow* window);
	virtual ~State();

	const bool& getEnd() const;
	sf::RenderWindow *getWindow();

	virtual void checkForEnd();

	virtual void endState() = 0;
	virtual void updateKeybinds(const float &dt) = 0;
	virtual void update(const float & dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
	virtual void updateBullets(Tank player) = 0;
	virtual void bulletKeys(Tank player, const float& dt) = 0;
};

#endif