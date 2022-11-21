#include "Cookware.h"

Cookware::Cookware()
{
    name_ = "";
    cost_ = 0;
    break_chance_ = 0;
}
Cookware::Cookware(string name, int cost, int break_chance)
{
    name_ = name;
    cost_ = cost;
    break_chance_ = break_chance;
}

string Cookware::getName()
{
    return name_;
}

void Cookware::setName(string name)
{
    name_ = name;
}

int Cookware::getCost()
{
    return cost_;
}

void Cookware::setCost(int cost)
{
    cost_ = cost;
}

int Cookware::getBreakChance()
{
    return break_chance_;
}

void Cookware::setBreakChance(int break_chance)
{
    break_chance_ = break_chance;
}