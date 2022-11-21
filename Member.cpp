#include "Member.h"

Member::Member()
{
    fullness_ = 50;
    name_ = "";
    armor_ = false;
    weapon_.setWeaponName("");
    weapon_.setCost(-1);
    weapon_.setUpgradeLevel(-1);
}
Member::Member(string name, bool is_player)
{
    fullness_ = 50;
    name_ = name;
    armor_ = false;
    is_player_ = is_player;
    weapon_.setWeaponName("");
    weapon_.setCost(-1);
    weapon_.setUpgradeLevel(-1);
}

bool Member::getIsPlayer()
{
    return is_player_;
}

void Member::setIsPlayer(bool b)
{
    is_player_ = b;
}

int Member::getFullness()
{
    return fullness_;
}

void Member::setFullness(int fullness)
{
    fullness_ = fullness;
}

void Member::removeFullness(int amount)
{
    fullness_ -= amount;
}

string Member::getName()
{
    return name_;
}

void Member::setName(string name)
{
    name_ = name;
}

bool Member::getArmor()
{
    return armor_;
}

void Member::setArmor(bool armor)
{
    armor_ = armor;
}

void Member::removeWeapon()
{
    weapon_.setWeaponName("");
    weapon_.setCost(-1);
    weapon_.setUpgradeLevel(-1);
}

void Member::addWeapon(Weapon weapon)
{
    weapon_ = weapon;
}

Weapon Member::getWeapon()
{
    return weapon_;
}

void Member::removeArmor()
{
    armor_ = false;
}