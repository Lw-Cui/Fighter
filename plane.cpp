#include <iostream>
#include "plane.h"
#include "game.h"


void plane::dead()
{
    _energy = 0;
}

void plane::setRandomPosition()
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
    load();
    setRandomPosition();
}


void boss::update()
{
    _sprite.move(0, VELOCITY);
    if (_energy <= 0)
        deathAnimate();
}


bat::bat()
{
    _prototype = "*-bat";
    _deathAnimation = ANIMATION;
    _energy = ENERGY;
    load();
    setRandomPosition();
}


void bat::update()
{
    _sprite.move(0, VELOCITY);
    if (_energy <= 0)
        deathAnimate();
}



batman::batman()
{
    _prototype = "*-batman";
    _deathAnimation = ANIMATION;
    _energy = ENERGY;
    load();
    setRandomPosition();
}

void batman::update()
{
    _sprite.move(0, VELOCITY);
    if (_energy <= 0)
        deathAnimate();
}


hero::hero()
{
    init();
    setCenter();
}

void hero::init()
{
    _energy = ENERGY;
    _rebornAnimation = ANIMATION;
    _prototype = "*-hero";
    load();
}

void hero::update()
{
    float offsetX = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
            && getPosition().x > getSize().x / 2)
        offsetX -= VELOCITY;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
            && getPosition().x < game::WIDTH - getSize().x / 2)
        offsetX += VELOCITY;

    _sprite.move(offsetX, 0);

    if (_energy <= 0  && reborn())
        init();
}

bool hero::isExisting()
{
    return _energy;
}


bool hero::reborn()
{
   if (_rebornAnimation > 1
           && _rebornTime.getElapsedTime().asSeconds() > 0.085) {
       load(--_rebornAnimation);
       _rebornTime.restart();
   } else if (_rebornAnimation > - ANIMATION + 2
       && _rebornTime.getElapsedTime().asSeconds() > 0.13) {

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


void enemy::deathAnimate()
{
   if (_deathAnimation > 1
           && _deathTime.getElapsedTime().asSeconds() > 0.075) {
       load(--_deathAnimation);
       _deathTime.restart();
   }
}

plane::~plane()
{
}

void plane::decreaseEnergy()
{
    _energy--;
}


enemy::~enemy()
{

}
