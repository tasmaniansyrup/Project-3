#ifndef PLAYER_H
#define MEMBERS_H

#include "Weapons.h"

class Member
{
private:
    int fullness_;
    string name_;
    bool armor_;
    Weapon weapon_;
    bool is_player_;

public:
    Member();
    Member(string name, bool is_player);

    bool getIsPlayer();
    void setIsPlayer(bool b);

    int getFullness();
    void setFullness(int fullness);
    void removeFullness(int amount);

    string getName();
    void setName(string name);

    bool getArmor();
    void setArmor(bool armor);

    void removeWeapon();
    void addWeapon(Weapon weapon);
    Weapon getWeapon();

    void removeArmor();
};

#endif