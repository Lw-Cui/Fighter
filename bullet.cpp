#include "cmath"
#include "bullet.h"
#include "game.h"

enemybullet::enemybullet(double x, double y, double angle)
{
    _prototype = "blueBullet";
    _velocity = 0.3;
    _angle = angle;
    load();
    _sprite.setPosition(x, y);
    _sprite.setRotation(-angle);
}

enemybullet::~enemybullet()
{

}

void enemybullet::update()
{
    _sprite.move((float)sin(_angle * 3.1415926 / 180.0) * _velocity,
                 (float)cos(_angle * 3.1415926 / 180.0) * _velocity);
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
