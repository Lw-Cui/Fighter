#include "difficultcontrol.h"
#include <cstdlib>
#include <iostream>

difficultControl::difficultControl()
{
    _enemySum = 3;

    _bossVelocity = 0.05;
    _batmanVelocity = 0.1;
    _batVelocity = 0.3;
}

difficultControl::~difficultControl()
{

}

void difficultControl::upLevel()
{
    _enemySum += 2;
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

double difficultControl::getUnstability() const
{
    std::cout <<  1 + (double)(rand() % 10) / 10 << std::endl;
    return 1 + (double)(rand() % 10) / 10;
}
