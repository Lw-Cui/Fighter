#include <iostream>
#include "plane.h"
#include "game.h"


void enemy::dead()
{
    _energy = 0;
}

void enemy::setRandomPosition()
{
    _sprite.setPosition(getSize().x / 2 +
                        rand() % (game::WIDTH - getSize().x),
                           50 - (int)getSize().y);
}


bool enemy::isExisting()
{
    if (getPosition().y - getSize().y / 2 > game::LENGTH
            || (_energy <= 0 && _deathAnimation <= 1))
        return false;
    else
        return true;
}


boss::boss()
{
    _energy = ENERGY;
    _deathAnimation = ANIMATION;
    _prototype = "*-boss";
    _velocity = game::_controlPanel.getBossVelocity();
    load();
    setRandomPosition();
}


void boss::update()
{
    _sprite.move(0, _velocity);
    if (_energy <= 0)
        deathAnimate();
}


bat::bat()
{
    _prototype = "*-bat";
    _deathAnimation = ANIMATION;
    _energy = ENERGY;
    _velocity = game::_controlPanel.getBatVelocity();
    load();
    setRandomPosition();
}


void bat::update()
{
    _sprite.move(0, _velocity);
    if (_energy <= 0)
        deathAnimate();
}



batman::batman()
{
    _prototype = "*-batman";
    _deathAnimation = ANIMATION;
    _energy = ENERGY;
    _velocity = game::_controlPanel.getBatmanVelocity();
    load();
    setRandomPosition();
}

void batman::update()
{
    _sprite.move(0, _velocity);
    if (_energy <= 0)
        deathAnimate();
}


hero::hero()
{
    _allLife = 3;
    init();
    setCenter();
}

void hero::init()
{
    _rebornAnimation = ANIMATION;
    _isdead = false;
    _prototype = "*-hero";
    load();
}

void hero::update()
{
    double offsetX = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
            && getPosition().x > getSize().x / 2)
        offsetX -= VELOCITY;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
            && getPosition().x < game::WIDTH - getSize().x / 2)
        offsetX += VELOCITY;

    _sprite.move(offsetX, 0);

    if (_isdead && reborn())
        init();
}

bool hero::isExisting()
{
    return _isdead;
}

bool hero::reborn()
{
   if (_rebornAnimation > 1
           && _rebornTime.getElapsedTime().asSeconds() > 0.095) {
       load(--_rebornAnimation);
       _rebornTime.restart();
   } else if (_rebornAnimation > - ANIMATION + 2
       && _rebornTime.getElapsedTime().asSeconds() > 0.2) {

       if (_rebornAnimation == 1)
           setCenter();

        if (_rebornAnimation % 2)
           load();
        else
           _sprite.setTexture(game::getTexture("transparent"));

       _rebornAnimation--;
       _rebornTime.restart();
       if (_rebornAnimation == - ANIMATION + 2)
           return true;
    }

   return false;
}

void hero::setCenter()
{
    _sprite.setPosition(game::WIDTH / 2,
                        game::LENGTH - getSize().y / 2);
}

void hero::dead()
{
    if (!_isdead)
        _allLife--;
    _isdead = true;
}

int hero::getAllLife()
{
    return _allLife;
}

void enemy::deathAnimate()
{
   if (_deathAnimation > 1
           && _deathTime.getElapsedTime().asSeconds() > 0.075) {
       load(--_deathAnimation);
       _deathTime.restart();
   }
}


void enemy::decreaseEnergy()
{
    _energy--;
}


enemy::~enemy()
{

}
