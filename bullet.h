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
    myBullet(float x, float y);
    ~myBullet();

    void update();
};

class enemybullet : public bullet
{
public:
    enemybullet(float x, float y);
    ~enemybullet();

    void update();
};

#endif // BULLET

