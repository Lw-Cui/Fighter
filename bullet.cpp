#include "bullet.h"
#include "game.h"

enemybullet::enemybullet(double x, double y)
{
    _prototype = "blueBullet";
    load();
    _sprite.setPosition(x, y);
}

enemybullet::~enemybullet()
{

}

void enemybullet::update()
{
    _sprite.move(0, 0.3);
}


myBullet::myBullet(double x, double y)
{
    _prototype = "redBullet";
    load();
    _sprite.setPosition(x, y);
}

myBullet::~myBullet()
{

}

void myBullet::update()
{
    _sprite.move(0, -1);
}



bullet::bullet() : isHit(false)
{
}

void bullet::setHit()
{
    isHit = true;
}

bool bullet::isExisting()
{
    if (_sprite.getPosition().y > game::LENGTH ||
            _sprite.getPosition().y < 0 || isHit)
        return false;
    else
        return true;
}
