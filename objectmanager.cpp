#include <cstdlib>
#include <cassert>
#include <SFML/System/Clock.hpp>
#include "objectmanager.h"
#include "bullet.h"
#include "game.h"


objectManager::objectManager() : _enemySum(3)
{
    assert(_image.loadFromFile("resources/image/background.png"));
    _background.setTexture(_image);

    _hero = new hero;
}

objectManager::~objectManager()
{

}

void objectManager::drawAll(sf::RenderWindow &window)
{
    window.draw(_background);

    _hero->draw(window);
    for (std::list<plane *>::iterator ite = _enemy.begin();
         ite != _enemy.end(); ite++)
        (*ite)->draw(window);

    for (std::list<bullet *>::iterator ite = _bullet.begin();
         ite != _bullet.end(); ite++)
        (*ite)->draw(window);
}

void objectManager::updateAll()
{
    _hero->update();

    updateBullet();
    updateEnemy();
    fire();
    collisionDetection();
}

void objectManager::updateEnemy()
{
    for (std::list<plane *>::iterator ite = _enemy.begin();
         ite != _enemy.end();) {
        plane *p = *ite;

        if (!p->isExisting()) {

            if( p->getPosition().y - p->getSize().y / 2 < game::LENGTH) {
                if (dynamic_cast<boss *>(p))
                    game::soundPlay("resources/sound/enemy2_down.ogg");
                else if (dynamic_cast<batman *>(p))
                    game::soundPlay("resources/sound/enemy3_down.ogg");
                else
                    game::soundPlay("resources/sound/enemy1_down.ogg");
            }

            delete p;
            _enemy.erase(ite++);
        } else {
            p->update();
            ite++;
        }
    }

    for (int i = _enemy.size(); i < _enemySum; i++) {
        int random = rand();
        if (random % 2)
            _enemy.push_back(new bat);
        else if (random % 4)
            _enemy.push_back(new batman);
        else
            _enemy.push_back(new boss);
    }
}


void objectManager::updateBullet()
{

    for (std::list<bullet*>::iterator ite = _bullet.begin();
         ite != _bullet.end();) {
        bullet *p = *ite;

        if (!p->isExisting()) {
            delete p;
            _bullet.erase(ite++);
        } else {
            p->update();
            ite++;
        }
    }
}

void objectManager::fire()
{
    if (_myTime.getElapsedTime().asSeconds()> 0.2
            && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        game::soundPlay("resources/sound/bullet.ogg");
        bullet *p = new myBullet(_hero->getPosition().x,
                        _hero->getPosition().y - _hero->getSize().y / 2 - 15);
        _bullet.push_back(p);
        _myTime.restart();
    }


    if (!_enemy.empty() && _enemySum > 1
            && _enemyTime.getElapsedTime().asSeconds() > 2) {
        std::list<plane *>::iterator ite = _enemy.begin();
        int index = rand() % (_enemySum - 1);
        while (index--)
            ite++;
        visualObject *front = *ite;
        if (!dynamic_cast<bat *>(front)) {
            game::soundPlay("resources/sound/bullet.ogg");
            bullet *p = new enemybullet(front->getPosition().x,
                    front->getPosition().y +
                    front->getSize().y / 2 + 15);
            _bullet.push_back(p);
            _enemyTime.restart();
        }
    }

}

void objectManager::collisionDetection()
{
    for (std::list<bullet*>::iterator bulletIte = _bullet.begin();
         bulletIte != _bullet.end(); bulletIte++) {

        bullet *bulletP = *bulletIte;
        sf::FloatRect bulletBound = bulletP->getBounds();

        for (std::list<plane *>::iterator enemyIte = _enemy.begin();
             enemyIte != _enemy.end(); enemyIte++) {
            plane *enemyP = *enemyIte;

            if (bulletBound.intersects(enemyP->getBounds())) {
                bulletP->setHit();
                enemyP->decreaseEnergy();
                continue;
            }
        }

        if (bulletBound.intersects(_hero->getBounds())) {
            _hero->decreaseEnergy();
            bulletP->setHit();
        }
    }

    for (std::list<plane *>::iterator bulletIte = _enemy.begin();
         bulletIte != _enemy.end(); bulletIte++) {

        plane *enemyP = *bulletIte;
        if (_hero->getBounds().intersects(enemyP->getBounds())) {
            _hero->dead();
            enemyP->dead();
        }
    }
}