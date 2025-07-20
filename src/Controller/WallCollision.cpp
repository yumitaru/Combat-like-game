#include "WallCollision.hpp"


bool WallCollision::checkCollision(Tank &tank, Map &walls)
{
    for (const auto &wall : walls.getWalls()) {
        if (tank.getCollisionShape().getGlobalBounds().intersects(wall.getGlobalBounds())) {
            return true; // Collision detected
        }
    }
    return false; // No collision
}

void WallCollision::update(const float &dt, Tank &tank, Map &walls)
{

    this->checkTankCollision(tank, walls);
    this->checkBulletCollision(tank, walls);
    
}

void WallCollision::checkTankCollision(Tank &tank, Map &walls)
{

     if(this->checkCollision(tank, walls)) // Check for collision with walls
    {
        tank.setPosition(tank.getPreviousPosition());

        std::cout << "Collision detected!" << std::endl;

    }
}

void WallCollision::checkBulletCollision(Tank &tank, Map &walls)
{

    std::vector<Bullet> bullets = tank.getBullets();

    for(auto &bullet : bullets)
    {
            sf::FloatRect bulletBounds = bullet.getShape().getGlobalBounds();

            for(const auto& wall : walls.getWalls())
            {
                if(bulletBounds.intersects(wall.getGlobalBounds()))
                {
                    sf::FloatRect wallBounds = wall.getGlobalBounds();

                    sf::Vector2f dir = bullet.getDirection();

                    
                    if (bulletBounds.left < wallBounds.left || bulletBounds.left + bulletBounds.width > wallBounds.left + wallBounds.width)
                    {
                        // Odbicie od pionowej ściany (zmiana X)
                        dir.x = -dir.x;
                    }
                    if (bulletBounds.top < wallBounds.top || bulletBounds.top + bulletBounds.height > wallBounds.top + wallBounds.height)
                    {
                        // Odbicie od poziomej ściany (zmiana Y)
                        dir.y = -dir.y;
                    }

                    bullet.setDirection(dir);

                    bullet.setPosition(bullet.getPreviousPosition());

                    bullet.incrementHitCount();

                    if(bullet.getHitCount() >= 4)
                    {
                        
                        bullet = bullets.back(); 
                        bullets.pop_back(); 
                    }


                    std::cout << "Bullet bounced off wall!" << std::endl;
                    break; 
                }
            }
        
    }

    tank.setBullets(bullets); 
}

void WallCollision::checkTankBulletCollision(Tank &tank, Tank &tank2)
{
    std::vector<Bullet> bullets = tank.getBullets();
    std::vector<Bullet> bullets2 = tank2.getBullets();

     for(auto &bullet : bullets)
    {
        sf::FloatRect bulletBounds = bullet.getShape().getGlobalBounds();

        if(bulletBounds.intersects(tank2.getShape().getGlobalBounds()))
        {
            

            bullet = bullets.back(); 
            bullets.pop_back(); 


            std::cout << "Bullet hit tank!" << std::endl;
        }
    }

    tank.setBullets(bullets);

    for(auto &bullet : bullets2)
    {
        sf::FloatRect bulletBounds = bullet.getShape().getGlobalBounds();

        if(bulletBounds.intersects(tank.getShape().getGlobalBounds()))
        {
            

            bullet = bullets2.back(); 
            bullets2.pop_back(); 


            std::cout << "Bullet hit tank!" << std::endl;
        }
    }

    tank2.setBullets(bullets2);
}
