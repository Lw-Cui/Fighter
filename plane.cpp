#include "plane.h"
#include "game.h"

void plane::deathAnimate()
{
   if (_animation > 1
           && _time.getElapsedTime().asSeconds() > 0.075) {
       load(--_animation);
       _time.restart();
   }
}

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


bool plane::isExisting()
{
    if (getPosition().y - getSize().y / 2 > game::LENGTH
            || (_energy <= 0 && _animation <= 1))
        return false;
    else
        return true;
}


boss::boss()
{
    _energy = ENERGY;
    _animation = ANIMATION;
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
    _animation = ANIMATION;
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
    _animation = ANIMATION;
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
    _energy = ENERGY;
    _animation = ANIMATION;
    _prototype = "*-hero";
    load();
    _sprite.setPosition(game::WIDTH / 2, game::LENGTH - getSize().y / 2);
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
    if (_energy <= 0)
        deathAnimate();

}


plane::~plane()
{

}

void plane::decreaseEnergy()
{
    _energy--;
}
