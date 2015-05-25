#ifndef DIFFICULTCONTROL_H
#define DIFFICULTCONTROL_H


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

private:
    double getUnstability() const;

    int _enemySum;

    double _bossVelocity;
    double _batmanVelocity;
    double _batVelocity;

};

#endif // DIFFICULTCONTROL_H
