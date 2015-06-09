#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cassert>
#include <SFML/System/Clock.hpp>
#include "objectmanager.h"
#include "bullet.h"
#include "game.h"
#include "gift.h"

objectManager::objectManager()
{
    _score = 0;
    _move = 1600 - game::LENGTH;
    _level = 1;

    assert(_image.loadFromFile("resources/image/backGround.png"));
    _background.setTexture(_image);

    _hero = new hero;

    setTextType(_scoreBoard);
    _scoreBoard.setPosition(10, 10);
    setTextType(_lifeBoard);
    _lifeBoard.setPosition(game::WIDTH - 100, 10);
}

objectManager::~objectManager()
{
    clearEnemy();
    clearBullet();
    delete _hero;
}

void objectManager::drawAll(sf::RenderWindow &window)
{
    window.draw(_background);

    _hero->draw(window);
    for (std::list<enemy *>::iterator ite = _enemy.begin();
         ite != _enemy.end(); ite++)
        (*ite)->draw(window);

    for (std::list<bullet *>::iterator ite = _bullet.begin();
         ite != _bullet.end(); ite++)
        (*ite)->draw(window);

    for (std::list<gift *>::iterator ite = _gift.begin();
         ite != _gift.end(); ite++)
        (*ite)->draw(window);

    window.draw(_scoreBoard);
    window.draw(_lifeBoard);
}

void objectManager::updateAll()
{
    if (_backMoveTime.getElapsedTime().asSeconds() > 0.01) {
        _background.setTextureRect(sf::IntRect(0, _move, game::WIDTH, game::LENGTH));
        if ((_move -= 1) < 0)
            _move = 1600 - game::LENGTH;
        _backMoveTime.restart();
    }

    _hero->update();
    updateBullet();
    updateEnemy();
    updateGift();
    fire();
    collisionDetection();
    updateText();
}

bool objectManager::isContinue()
{
    return _hero->getAllLife() > 0;
}

void objectManager::reStart()
{
    _hero->reStart();
    _hero->setCenter();
    clearEnemy();
    clearBullet();
}

void objectManager::updateEnemy()
{
        std::cout << _level << std::endl;
        std::cout << _score << std::endl;

    if (log(_score / 30000) > _level) {
        _level = log(_score / 30000) + 1;
        game::_controlPanel.upLevel();
    }

    for (std::list<enemy *>::iterator ite = _enemy.begin();
         ite != _enemy.end();) {
        enemy *p = *ite;

        if (!p->isExisting()) {

            if( p->getPosition().y - p->getSize().y / 2 < game::LENGTH) {
                if (dynamic_cast<boss *>(p)) {
                    game::_audioPlay.playSound("resources/sound/enemy2_down.ogg", 75);
                    _score += 7000;
                } else if (dynamic_cast<batman *>(p)) {
                    game::_audioPlay.playSound("resources/sound/enemy3_down.ogg", 80);
                    _score += 3000;
                } else {
                    game::_audioPlay.playSound("resources/sound/enemy1_down.ogg", 90);
                    _score += 1000;
                }
            }

            delete p;
            _enemy.erase(ite++);
        } else {
            p->update();
            ite++;
        }
    }

    for (int i = _enemy.size();
         i < game::_controlPanel.getEnemySum(); i++) {
         int enemyTpye = game::_controlPanel.getEnemyType();
         switch (enemyTpye) {
         case 0:
            _enemy.push_back(new boss);
            break;
         case 1:
            _enemy.push_back(new batman);
            break;
         case 2:
            _enemy.push_back(new bat);
            break;
         default:
             break;
        }
    }
}

void objectManager::updateGift()
{
    for (std::list<gift *>::iterator ite = _gift.begin();
         ite != _gift.end();) {
        gift *p = *ite;
        if (!p->isExisting()) {
            delete p;
            _gift.erase(ite++);
        } else {
            p->update();
            ite++;
        }
    }

    for (int i = _gift.size();
         i < game::_controlPanel.getGiftSum(); i++) {
        _gift.push_back(new doubleFire);
    }
}

void objectManager::updateText()
{
    char score[100];
    sprintf(score, "SCORE:%6d", _score);
    _scoreBoard.setString(std::string(score));

    char life[100];
    //for (int i = 0; i < _heroLife; i++)
    sprintf(life, "LIFE: %2d", _hero->getAllLife());
    _lifeBoard.setString(std::string(life));
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
    if (_myFireTime.getElapsedTime().asSeconds()> 0.2
            && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        game::_audioPlay.playSound("resources/sound/bullet.ogg");
        heroFire();
        _myFireTime.restart();
    }

    if (!_enemy.empty()
            && _enemyFireTime.getElapsedTime().asSeconds() > 1) {
        std::list<enemy *>::iterator ite = _enemy.begin();
        int index = rand() % (game::_controlPanel.getEnemySum() - 1);
        while (index--)
            ite++;
        enemy *enemyF = *ite;
        bossFire(dynamic_cast<boss *>(enemyF));
        batmanFire(dynamic_cast<batman *>(enemyF));
        _enemyFireTime.restart();
    }
}

void objectManager::heroFire()
{
    if (game::_controlPanel.isDoubleFire()) {
        bullet *p1 = new myBullet(_hero->getPosition().x - 5,
                _hero->getPosition().y - _hero->getSize().y / 2 - 15);
        _bullet.push_back(p1);

        bullet *p2 = new myBullet(_hero->getPosition().x + 5,
                _hero->getPosition().y - _hero->getSize().y / 2 - 15);
        _bullet.push_back(p2);

    } else {
        bullet *p = new myBullet(_hero->getPosition().x,
                _hero->getPosition().y - _hero->getSize().y / 2 - 15);
        _bullet.push_back(p);

    }
}


void objectManager::bossFire(boss *Boss)
{
    if (!Boss)
        return;
    game::_audioPlay.playSound("resources/sound/bullet.ogg");
    _bullet.push_back(new enemybullet(Boss->getPosition().x,
        Boss->getPosition().y + Boss->getSize().y / 2 + 15,
                                60));
    _bullet.push_back(new enemybullet(Boss->getPosition().x,
        Boss->getPosition().y + Boss->getSize().y / 2 + 15,
                                30));
    _bullet.push_back(new enemybullet(Boss->getPosition().x,
        Boss->getPosition().y + Boss->getSize().y / 2 + 15,
                                0));
    _bullet.push_back(new enemybullet(Boss->getPosition().x,
        Boss->getPosition().y + Boss->getSize().y / 2 + 15,
                              -30));
    _bullet.push_back(new enemybullet(Boss->getPosition().x,
        Boss->getPosition().y + Boss->getSize().y / 2 + 15,
                              -60));
}

void objectManager::batmanFire(batman *Batman)
{
    if (!Batman)
        return;
    _bullet.push_back(new enemybullet(Batman->getPosition().x,
        Batman->getPosition().y + Batman->getSize().y / 2 + 15,
                                0));
}

void objectManager::setTextType(sf::Text &text)
{
    text.setFont(game::_font);
    text.setColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);
    text.setCharacterSize(25);

}

void objectManager::clearEnemy()
{
    for (std::list<enemy *>::iterator ite = _enemy.begin();
         ite != _enemy.end(); ite++)
        delete *ite;
    _enemy.clear();
}

void objectManager::clearBullet()
{
    for (std::list<bullet *>::iterator ite = _bullet.begin();
         ite != _bullet.end(); ite++)
        delete *ite;
    _bullet.clear();
}

void objectManager::collisionDetection()
{
    for (std::list<bullet*>::iterator bulletIte = _bullet.begin();
         bulletIte != _bullet.end(); bulletIte++) {

        bullet *bulletP = *bulletIte;
        sf::FloatRect bulletBound = bulletP->getBounds();

        if (dynamic_cast<myBullet *>(bulletP)) {
            for (std::list<enemy *>::iterator enemyIte = _enemy.begin();
                 enemyIte != _enemy.end(); enemyIte++) {
                enemy *enemyP = *enemyIte;

                if (bulletBound.intersects(enemyP->getBounds())) {
                bulletP->setHit();
                enemyP->decreaseEnergy();
                continue;
                }
            }
        } else {
            if (bulletBound.intersects(_hero->getBounds())) {
                _hero->dead();
                bulletP->setHit();
            }
        }
    }

    for (std::list<enemy *>::iterator enemyIte = _enemy.begin();
         enemyIte != _enemy.end(); enemyIte++) {

        enemy *enemyP = *enemyIte;
        if (_hero->getBounds().intersects(enemyP->getBounds())) {
            _hero->dead();
            enemyP->dead();
        }
    }
}
