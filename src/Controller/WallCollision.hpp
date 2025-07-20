#ifndef WALLCOLLISION_HPP
#define WALLCOLLISION_HPP

#include "../Graphics/Tank.hpp"

class Tank;
class Map;

class WallCollision {

public:
    WallCollision() = default;
    ~WallCollision() = default;

    bool checkCollision(Tank &tank, Map &walls);
    void update(const float &dt, Tank&tank, Map &walls);

    void checkTankCollision(Tank &tank, Map &walls);
    void checkBulletCollision(Tank &tank, Map &walls);
    void checkTankBulletCollision(Tank &tank, Tank &tank2);

};









#endif