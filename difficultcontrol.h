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
    int getEnemyType() const;

private:
    double getUnstability() const;

    int _enemySum;
    int _bossProportion;
    int _batmanProportion;

    double _bossVelocity;
    double _batmanVelocity;
    double _batVelocity;

};

#endif // DIFFICULTCONTROL_H
