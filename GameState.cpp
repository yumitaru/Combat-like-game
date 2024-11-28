#include "GameState.h"

GameState::GameState(sf::RenderWindow* window) : State(window)
{
	player2 = Tank(2);
	player2.startPos(750.f, 300.f);

}

GameState::~GameState()
{
	// this->player1.getBullets().clear();
	// this->player2.getBullets().clear();
	this->player1.bulletsClear();
	this->player2.bulletsClear();
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
	// Current1 = bullets1.getHead();
	// this->player1.setCurrent(this->player1.getBullets().getHead());
	// this->player2.setCurrent(this->player2.getBullets().getHead());
	this->player1.setCurrent(this->player1.getHead());
	this->player2.setCurrent(this->player2.getHead());
	this->updateKeybinds(dt);
	this->player1.update(dt);
	this->player2.update(dt);

	this->bulletKeys(player1, dt);
	// if (Current1->operator!=(nullptr))
	// 	bullets1.back()->create(dt);
	// while (Current1->operator!=(nullptr))        
	// {
	// 	Current1->bullet()->update(dt);
	// 	Current1 = Current1->next();
	// }
	this->bulletKeys(player2, dt);
	if (this->player1.operator!=(nullptr))
		this->player1.back()->create(dt);
	while (this->player1.operator!=(nullptr))        
	{
		this->player1.bullet()->update(dt);
		this->player1.setCurrent(this->player1.next());

	}

	if (this->player2.operator!=(nullptr))
		this->player2.back()->create(dt);
	while (this->player2.operator!=(nullptr))        
	{
		this->player2.bullet()->update(dt);
		this->player2.setCurrent(this->player1.next());

	}
	save.update(player1, player2);
	load.update(player1, player2);

	if (load.operator==(true))
	{
		player1.setPosition();
		player2.setPosition();
		// bullets1.clear();
		// this->player1.getBullets().clear();
		// this->player2.getBullets().clear();
		this->player1.bulletsClear();
		this->player2.bulletsClear();
		load.loadFalse();
	}

}

void GameState::render(sf::RenderTarget* target)
{
	// Current1 = bullets1.getHead();
	
	this->player1.setCurrent(this->player1.getHead());
	this->player2.setCurrent(this->player2.getHead());
	
	this->player1.render(this->getWindow());
	this->player2.render(this->getWindow());

	// while (Current1->operator!=(nullptr))        
	// {
	// 	Current1->bullet()->render(this->getWindow());
	// 	Current1 = Current1->next();
	// }


	while (this->player1.operator!=(nullptr))       
	{

		this->player1.bullet()->render(this->getWindow());
		this->player1.setCurrent(this->player1.getCurrent()->next());

		
	}

	while (this->player2.operator!=(nullptr))       
	{
		std::cout << "bomba" << std::endl;
		std::cout << player2.getHead() << std::endl;
		std::cout << player2.getCurrent() << std::endl;
		this->player2.renderBullet(this->getWindow());
		this->player2.setCurrent(this->player2.getCurrent()->next());
	}

}

void GameState::updateBullets(Tank &player)
{
	// player.getBullets().push_back(new Bullet(player.getPosition()));

	player.bulletsPush_back(new Bullet());
}

void GameState::bulletKeys(Tank &player, const float& dt)
{

	if (clock1.getElapsedTime().asMilliseconds() >= 500){

	if (sf::Keyboard::isKeyPressed(player.getUp()) && sf::Keyboard::isKeyPressed(player.getFireKey()))
	{
		this->updateBullets(player);
		std::cout << player.getHead() << std::endl;
		std::cout << "hej" << std::endl;
		std::cout << player.getCurrent() << std::endl;
		clock1.restart();
	}
	else if (sf::Keyboard::isKeyPressed(player.getLeft()) && sf::Keyboard::isKeyPressed(player.getFireKey()))
	{
		this->updateBullets(player);
		clock1.restart();
	}
	else if (sf::Keyboard::isKeyPressed(player.getDown()) && sf::Keyboard::isKeyPressed(player.getFireKey()))
	{
		this->updateBullets(player);
		clock1.restart();
	}
	else if (sf::Keyboard::isKeyPressed(player.getRight()) && sf::Keyboard::isKeyPressed(player.getFireKey()))
	{
		this->updateBullets(player);
		clock1.restart();
	}
		}

}




