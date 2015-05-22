#ifndef PLANE_H
#define PLANE_H

#include "visualobject.h"

class plane : public visualObject
{
public:
    virtual ~plane();

    virtual void update() = 0;
    void decreaseEnergy();
    bool isExisting();
    void deathAnimate();
    void dead();

protected:
    void setRandomPosition();
    int _energy;
    int _animation;
    sf::Clock _time;
};


class hero : public plane
{
public:
    hero();
    void update();

private:
    const static int ENERGY = 3;
    const static int ANIMATION = 4;
    const static float VELOCITY = 0.25;
};

class boss : public plane
{
public:
    boss();
    void update();

private:
    static const int ENERGY = 7;
    static const int ANIMATION = 6;
    static const float VELOCITY = 0.05;
};


class batman : public plane
{
public:
    batman();
    void update();

private:
    const static int ENERGY = 2;
    const static int ANIMATION = 4;
    const static float VELOCITY = 0.1;
};

class bat : public plane
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

