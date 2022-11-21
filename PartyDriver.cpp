#include <iostream>
#include <vector>
#include "Party.h"

using namespace std;

int main()
{
    srand((unsigned int)time(0));
    Party Group_;
    Member m1 = Member("Edward", false);
    Member m2 = Member("Thelma", false);
    Member m3 = Member("Siegfried", false);
    Member m4 = Member("Marcus", false);
    Member m5 = Member("Player", true);//because of the way we remove members in fightMonster() the player must be in the final slot

    

    //creating weapons
    Weapon weapon1 = Weapon("club", 0, 2);
    Weapon weapon2 = Weapon("battle-axe", 2, 15);
    Weapon weapon3 = Weapon("rapier", 1, 5);
    Weapon weapon4 = Weapon("longsword", 3, 50);
    Weapon weapon5 = Weapon("spear", 0, 2);

    //adding weapons
    m1.addWeapon(weapon1);
    //m2.addWeapon(weapon2);
    //m3.addWeapon(weapon3);
    //m4.addWeapon(weapon4);
    //m5.addWeapon(weapon5);

    //adding armor
    m1.setArmor(true);
    m3.setArmor(true);
    //m5.setArmor(true);

    //adding party members
    Group_.addPartyMember(m1);
    Group_.addPartyMember(m2);
    Group_.addPartyMember(m3);
    Group_.addPartyMember(m4);
    Group_.addPartyMember(m5);//Player

    Cookware Pan = Cookware("Pan", 999, 0);
    
    vector<Cookware> Wares_;
    cout << Group_.getGold() << endl;
    Group_.addGold(50);
    cout << Group_.getGold() << endl;

    Group_.addKeys(2);
    cout << Group_.getKeys() << endl;

    //Group_.addRoomsCleared(2);
    cout << Group_.getRoomsCleared() << endl;

    Group_.addCookware(Pan);
    
    Wares_ = Group_.getCookware();
    for(int i = 0; i < Wares_.size(); i++)
    {
        cout << Wares_.at(i).getName() << endl;
    }

    Group_.addTreasureAt(3);
    Group_.addTreasureAt(3);
    cout << Group_.getTreasure()[3] << endl;

    cout << Group_.getGold() << endl;//what gold is before selling

    /*
    Group_.sellTreasureType('C');
    cout << Group_.getGold() << endl;//gold should increase by 80 because we're selling two pieces worth 40 each
    cout << Group_.getTreasure()[3] << endl;//should be 0 to verify that the treasure has been sold
    */

   Group_.addTreasureAt(0);
   Group_.addTreasureAt(0);
   Group_.addTreasureAt(0);
   cout << Group_.getTreasure()[0] << endl;

   Group_.sellAllTreasure();

   cout << Group_.getGold() << endl;//everything is sold, 3 worth 10, 2 worth 40, total added should be 110, + 150 from before is 260 expected


    cout << "Pre fight stats:" << endl;
    cout << "Gold: " << Group_.getGold() << endl;
    cout << "Keys " << Group_.getKeys() << endl;
    cout << "Ingredients " << Group_.getIngredients() << endl;
    Group_.printPartyMembers();


    Group_.fightMonster();


    cout << "Post fight stats:" << endl;
    cout << "Gold: " << Group_.getGold() << endl;
    cout << "Keys " << Group_.getKeys() << endl;
    cout << "Ingredients " << Group_.getIngredients() << endl;
    Group_.printPartyMembers();
}