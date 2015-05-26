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
    void updateText();
    void collisionDetection();
    void fire();
    void setTextType(sf::Text &text);


    sf::Texture _image;
    sf::Sprite _background;

    hero *_hero;

    std::list<enemy *> _enemy;
    std::list<bullet *> _bullet;

    sf::Clock _myFireTime, _enemyFireTime;
    sf::Clock _backMoveTime;
    int _move;

    sf::Text _scoreBoard;
    int _score;

    sf::Text _lifeBoard;
    sf::Text _levelBoard;
    int _level;
};

#endif // OBJECTMANAGER_H
