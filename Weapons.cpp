#include "Weapons.h"

Weapon::Weapon()
{
    name_ = "";
    upgrade_level_ = -1;
    cost_ = -1;
}

Weapon::Weapon(string name, int upgrade_level, int cost)
{
    name_ = name;
    upgrade_level_ = upgrade_level;
    cost_ = cost;
}

int Weapon::getUpgradeLevel()
{
    return upgrade_level_;
}

void Weapon::setUpgradeLevel(int upgrade_level)
{
    upgrade_level_ = upgrade_level;
}

string Weapon::getWeaponName()
{
    return name_;
}

void Weapon::setWeaponName(string name)
{
    name_ = name;
}

int Weapon::getCost()
{
    return cost_;
}

void Weapon::setCost(int cost)
{
    cost_ = cost;
}