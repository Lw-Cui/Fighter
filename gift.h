#ifndef BOMB
#define BOMB

#include "visualobject.h"

class gift : public visualObject
{
public:
    gift();
    ~gift();

    virtual void update() = 0;
    bool isExisting();
    void setRandomPosition();
    bool isGet();

    void get();

protected:
    double _velocity;

private:
    bool isGotten;
};

class bomb : public gift
{
public:
    bomb();
    void update();
};

class doubleFire : public gift
{
public:
    doubleFire();
    void update();
};

#endif // BOMB

