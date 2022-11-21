#ifndef WEAPONS_H
#define WEAPONS_H

#include <iostream>

using namespace std;

class Weapon
{
private:
    string name_;
    int upgrade_level_;
    int cost_;
public:
    Weapon();
    Weapon(string name, int upgrade_level, int cost);

    string getWeaponName();
    void setWeaponName(string name);

    int getUpgradeLevel();
    void setUpgradeLevel(int upgrade_level);

    int getCost();
    void setCost(int cost);
};

#endif