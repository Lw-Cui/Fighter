#include "game.h"
#include "visualobject.h"
#include "gift.h"

gift::gift()
{
    isHit = false;
}

gift::~gift()
{

}

bool gift::isExisting()
{
    if (_sprite.getPosition().y > game::LENGTH ||
            _sprite.getPosition().y < 0 || isHit)
        return false;
    else
        return true;
}

void gift::setRandomPosition()
{
    _sprite.setPosition(getSize().x / 2 +
                        rand() % (game::WIDTH - getSize().x),
                           150 - (int)getSize().y);
}


doubleFire::doubleFire()
{
    _prototype = "ufo1";
    load();
    setRandomPosition();
}

void doubleFire::update()
{
    _sprite.move(0, game::_controlPanel.getDoubleVelocity());
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
