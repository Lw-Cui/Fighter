#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <SFML/Graphics.hpp>
#include <list>
#include "objectmanager.h"
#include "plane.h"
#include "bullet.h"

class objectManager
{
public:
    objectManager();
    ~objectManager();

    void drawAll(sf::RenderWindow &window);
    void updateAll();

private:
    void updateBullet();
    void updateEnemy();
    void collisionDetection();
    void fire();

    sf::Texture _image;
    sf::Sprite _background;

    hero *_hero;
    std::list<plane *> _enemy;
    std::list<bullet *> _bullet;

    int _enemySum;
    sf::Clock _myTime, _enemyTime;
};

#endif // OBJECTMANAGER_H
