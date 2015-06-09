#include "game.h"
#include "visualobject.h"
#include "gift.h"

gift::gift()
{
    isGotten = false;
}

gift::~gift()
{

}

bool gift::isExisting()
{
    if (_sprite.getPosition().y > game::LENGTH ||
            _sprite.getPosition().y < 0 || isGotten)
        return false;
    else
        return true;
}

void gift::setRandomPosition()
{
    _sprite.setPosition(getSize().x / 2 +
                        rand() % (game::WIDTH - getSize().x),
                        100 - (int)getSize().y);
}

bool gift::isGet()
{
    return isGotten;
}

void gift::get()
{
    isGotten = true;
}

doubleFire::doubleFire()
{
    _prototype = "ufo1";
    _velocity = game::_controlPanel.getDoubleBulletVelocity();
    load();
    setRandomPosition();
}

void doubleFire::update()
{
    _sprite.move(0, _velocity);
}

bomb::bomb()
{
    _prototype = "ufo2";
    load();
    setRandomPosition();

}

void bomb::update()
{
}
