#ifndef PLANE_H
#define PLANE_H

#include "visualobject.h"

class plane : public visualObject
{
public:
    virtual ~plane();

    void decreaseEnergy();
    void dead();

protected:
    void setRandomPosition();
    int _energy;

};


class hero : public plane
{
public:
    hero();
    void init();
    void update();
    bool isExisting();
    bool reborn();
    void setCenter();

private:
    const static int ENERGY = 3;
    const static int ANIMATION = 4;
    const static float VELOCITY = 0.25;

    sf::Clock _rebornTime;
    int _rebornAnimation;
};



class enemy : public plane
{
public:
    virtual ~enemy();
    void deathAnimate();
    bool isExisting();

protected:
    int _deathAnimation;

private:
    sf::Clock _deathTime;
};

class boss : public enemy
{
public:
    boss();
    void update();

private:
    static const int ENERGY = 7;
    static const int ANIMATION = 6;
    static const float VELOCITY = 0.05;
};


class batman : public enemy
{
public:
    batman();
    void update();

private:
    const static int ENERGY = 2;
    const static int ANIMATION = 4;
    const static float VELOCITY = 0.1;
};

class bat : public enemy
{
public:
    bat();
    void update();

private:
    const static int ENERGY = 1;
    const static int ANIMATION = 4;
    const static float VELOCITY = 0.3;
};

#endif // PLANE_H

