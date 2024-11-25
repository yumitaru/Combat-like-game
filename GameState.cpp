#include "GameState.h"

GameState::GameState(sf::RenderWindow* window) : State(window)
{
}

GameState::~GameState()
{
	bullets1.clear();
	bullets2.clear();
}




void GameState::endState()
{
}

void GameState::updateKeybinds(const float& dt)
{

	this->checkForEnd();
}

void GameState::update(const float& dt)
{
	Current1 = bullets1.getHead();
	Current2 = bullets2.getHead();
	this->updateKeybinds(dt);
	this->player1.update(dt);
	this->player2.update(dt);

	this->bulletKeys1(dt);
	if (Current1->operator!=(nullptr))
		bullets1.back()->create(dt);
	while (Current1->operator!=(nullptr))        
	{
		Current1->bullet()->update(dt);
		Current1 = Current1->next();
	}
	this->bulletKeys2(dt);
	if (Current2->operator!=(nullptr))
		bullets2.back()->create(dt);
	while (Current2->operator!=(nullptr))        
	{
		Current2->bullet()->update(dt);
		Current2 = Current2->next();
	}
	save.update(player1, player2);
	load.update(player1, player2);

	if (load.operator==(true))
	{
		player1.setPosition();
		player2.setPosition();
		bullets1.clear();
		bullets2.clear();
		load.loadFalse();
	}

}

void GameState::render(sf::RenderTarget* target)
{
	Current1 = bullets1.getHead();
	Current2 = bullets2.getHead();
	this->player1.render(this->getWindow());
	this->player2.render(this->getWindow());

	while (Current1->operator!=(nullptr))        
	{
		Current1->bullet()->render(this->getWindow());
		Current1 = Current1->next();
	}
	while (Current2->operator!=(nullptr))       
	{
		Current2->bullet()->render(this->getWindow());
		Current2 = Current2->next();
	}
}

void GameState::updateBullets1()
{
	bullets1.push_back(new Bullet1(this->player1));
}

void GameState::bulletKeys1(const float& dt)
{
	if (clock1.getElapsedTime().asMilliseconds() >= 500){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		this->updateBullets1();
		clock1.restart();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		this->updateBullets1();
		clock1.restart();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		this->updateBullets1();
		clock1.restart();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		this->updateBullets1();
		clock1.restart();
	}
		}

}

void GameState::updateBullets2()
{
	this->bullets2.push_back(new Bullet2(this->player2));
}

void GameState::bulletKeys2(const float& dt)
{
	if (clock2.getElapsedTime().asMilliseconds() >= 500)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
		{
			this->updateBullets2();
			clock2.restart();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
		{
			this->updateBullets2();
			clock2.restart();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
		{
			this->updateBullets2();
			clock2.restart();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
		{
			this->updateBullets2();
			clock2.restart();
		}
	}

}


