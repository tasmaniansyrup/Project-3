#ifndef PARTY_MEMBERS_H
#define PARTY_MEMBERS_H

#include <iostream>
#include <vector>
#include "Member.h"
#include "Cookware.h"
//#include "Map.h"

class Party
{
private:
    int gold_;
    int keys_;
    int ingredients_;
    int rooms_cleared_;
    int turns_;

    vector<Cookware> cookware;

    int treasure[5];

    vector<Member> party_members;

public:
    Party();

    int getGold();
    void setGold(int gold);
    void addGold(int gold);
    void removeGold(int gold);

    int getKeys();
    void setKeys(int keys);
    void addKeys(int keys);

    int getIngredients();
    void setIngredients(int ingredients);
    void addIngredients(int ingredients);
    void removeIngredients(int ingredients);

    int getRoomsCleared();
    void setRoomsCleared(int rooms_cleared);
    void addRoomsCleared(int rooms_cleared);

    vector<Cookware> getCookware();
    Cookware useCookwareAt(int index);
    void addCookware(Cookware cookware);
    void removeCookware(int index);

    int * getTreasure();
    int getTreasureAt(int index);
    void sellTreasureType(char type);
    void sellAllTreasure();
    void addTreasureAt(int index);

    bool fightMonster();

    int getMisfortune();//1, 2, 3, or 4 as specified in write up

    void removePartyMember(int index);
    void addPartyMember(Member member);
    void printPartyMembers();

    bool doorPuzzle();
    bool npcPuzzle(string answer);

    int investigate();//1, 2, or 3 as specified in write up

};

#endif