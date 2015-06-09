#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <SFML/Graphics.hpp>
#include <list>
#include "objectmanager.h"
#include "plane.h"
#include "bullet.h"
#include "gift.h"

class objectManager
{
public:
    objectManager();
    ~objectManager();

    void drawAll(sf::RenderWindow &window);
    void updateAll();

    bool isContinue();
    void reStart();

private:
    void updateBullet();
    void updateEnemy();
    void updateGift();
    void updateText();
    void collisionDetection();
    void fire();

    void heroFire();
    void bossFire(boss *Boss);
    void batmanFire(batman *Batman);
    void setTextType(sf::Text &text);
    void clearEnemy();
    void clearBullet();

    sf::Texture _image;
    sf::Sprite _background;
    hero *_hero;

    std::list<enemy *> _enemy;
    std::list<bullet *> _bullet;
    std::list<gift *> _gift;

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
