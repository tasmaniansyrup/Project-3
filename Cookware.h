#ifndef COOKWARE_H
#define COOKWARE_H

#include <iostream>

using namespace std;

class Cookware
{
private:
    string name_;
    int cost_;
    int break_chance_;
public:
    Cookware();
    Cookware(string name, int cost, int break_chance);

    string getName();
    void setName(string name);

    int getCost();
    void setCost(int cost);

    int getBreakChance();
    void setBreakChance(int break_chance);
};

#endif