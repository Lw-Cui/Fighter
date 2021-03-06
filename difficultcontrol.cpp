#include "difficultcontrol.h"
#include <cstdlib>
#include <iostream>

difficultControl::difficultControl()
{
    _giftSum = 1;

    _enemySum = 3;
    _bossProportion = 5;
    _batmanProportion = 15;

    _bossVelocity = 0.05;
    _batmanVelocity = 0.1;
    _batVelocity = 0.2;
}

difficultControl::~difficultControl()
{

}

void difficultControl::upLevel()
{
    _giftSum++;

    _enemySum += 2;
    std::cout << "enemy: " << _enemySum << std::endl;

    _bossProportion += 2;
    _batmanProportion += 10;
}

int difficultControl::getEnemySum() const
{
    return _enemySum;
}

double difficultControl::getBossVelocity() const
{
    return _bossVelocity * getUnstability();
}

double difficultControl::getBatmanVelocity() const
{
    return _batmanVelocity * getUnstability();
}

double difficultControl::getBatVelocity() const
{
    return _batVelocity * getUnstability();
}

int difficultControl::getEnemyType() const
{
    int enemy = rand() % 100;
    if (enemy <= _bossProportion)
        return 0;
    else if (enemy <= _batmanProportion)
        return 1;
    else
        return 2;
}

int difficultControl::getGiftSum() const
{
    //to
    return _giftSum;
}

double difficultControl::getDoubleBulletVelocity() const
{
    return 0.2;
}


double difficultControl::getUnstability() const
{
    return 1 + (double)(rand() % 10) / 10;
}
