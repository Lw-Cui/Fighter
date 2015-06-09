#ifndef DIFFICULTCONTROL_H
#define DIFFICULTCONTROL_H

#include <SFML/Window.hpp>

class difficultControl
{
public:
    difficultControl();
    ~difficultControl();

    void upLevel();

    int getEnemySum() const;
    double getBossVelocity() const;
    double getBatmanVelocity() const;
    double getBatVelocity() const;
    int getEnemyType() const;

    int getGiftSum() const;
    double getDoubleBulletVelocity() const;

private:
    double getUnstability() const;

    int _giftSum;

    int _enemySum;
    int _bossProportion;
    int _batmanProportion;

    double _bossVelocity;
    double _batmanVelocity;
    double _batVelocity;

};

#endif // DIFFICULTCONTROL_H
