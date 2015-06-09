#ifndef BULLET
#define BULLET

#include "visualobject.h"

class bullet : public visualObject
{
public:
    bullet();
    virtual void update() = 0;
    void setHit();
    bool isExisting();

private:
    bool isHit;

};

class myBullet : public bullet
{
public:
    myBullet(double x, double y);
    ~myBullet();

    void update();
};

class enemybullet : public bullet
{
public:
    enemybullet(double x, double y, double angle);
    ~enemybullet();

    void update();

private:
    double _velocity;
    double _angle;
};

#endif // BULLET

