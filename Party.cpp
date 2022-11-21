#include <iostream>
#include <fstream>
#include <ctime>
#include "Party.h"

using namespace std;

int split(string input_string, char separator, string string_array[], int arr_size)
{
    int n = 0, j = 0;
    int num_splits = 0;
    int num_separators = 0;
    int start_of_string = 0;
    string substring = "";

    for(int i = 0; i < input_string.length(); i++)//counting the number of separators
    {
        if(input_string[i] == separator)
        {
            num_separators++;
        }
    }

    if(input_string == "")//return 0 if an empty string is received
    {
        return 0;
    } else if(num_separators >= arr_size)//if there will be more splits than spots in the array
    {
        while(num_splits < arr_size - 1)
        {
            if(input_string[n] == separator)//found a delimiter
            {
                string_array[num_splits] = input_string.substr(start_of_string, n - start_of_string);
                start_of_string = n + 1;
                num_splits++;
            }
            if(num_splits == arr_size - 1)//want to add the substring which ends at the next separator
            {
                substring = input_string.substr(start_of_string, arr_size - start_of_string);
                while(substring[j] != separator)//finding the next separator
                {
                    j++;
                }
                string_array[num_splits] = input_string.substr(start_of_string, j);
            }
            n++;
        }
        return -1;
    } else//case which there are enough spots in the array to fit all splits
    {
        for(int i = 0; i < input_string.length(); i++)//loop through the string
        {
            if(input_string[i] == separator)//found a delimiter
            {
                string_array[num_splits] = input_string.substr(start_of_string, i - start_of_string);
                start_of_string = i + 1;
                num_splits++;
            }
            if(num_splits == num_separators)//grabbing the last substring to be placed in the array which comes after the final separator
            {
                string_array[num_splits] = input_string.substr(start_of_string, input_string.length() - start_of_string);
            }
        }

        if(num_splits == 0)//if no delimiters are found, place the string in the first index of the array
        {
            string_array[0] = input_string;
        }
    }

    return num_splits + 1;
}

Party::Party()
{
    gold_ = 100;
    keys_ = 0;
    ingredients_ = 0;
    rooms_cleared_ = 0;
    turns_ = 0;
    
    for(int i = 0; i < 5; i++)
    {
        treasure[i] = 0;
    }
}

int Party::getGold()
{
    return gold_;
}

void Party::setGold(int gold)
{
    gold_ = gold;
}

void Party::addGold(int gold)
{
    gold_ += gold;
}

void Party::removeGold(int gold)
{
    gold_ -= gold;
}

int Party::getKeys()
{
    return keys_;
}

void Party::setKeys(int keys)
{
    keys_ = keys;
}

void Party::addKeys(int keys)
{
    keys_ += keys;
}


int Party::getIngredients()
{
    return ingredients_;
}
void Party::setIngredients(int ingredients)
{
    ingredients_ = ingredients;
}
void Party::addIngredients(int ingredients)
{
    ingredients_ += ingredients;
}
void Party::removeIngredients(int ingredients)
{
    ingredients_ -= ingredients;
}


int Party::getRoomsCleared()
{
    return rooms_cleared_;
}

void Party::setRoomsCleared(int rooms_cleared)
{
    rooms_cleared_ = rooms_cleared;
}

void Party::addRoomsCleared(int rooms_cleared)
{
    rooms_cleared_ += rooms_cleared;
}

vector<Cookware> Party::getCookware()
{
    return cookware;
}

Cookware Party::useCookwareAt(int index)
{
    return cookware.at(index);
}

void Party::addCookware(Cookware cookware_)
{
    cookware.push_back(cookware_);
}

void Party::removeCookware(int index)
{
    cookware.erase(cookware.begin() + index);
}


int * Party::getTreasure()
{
    return treasure;
}

int Party::getTreasureAt(int index)
{
    return treasure[index];
}

void Party::sellTreasureType(char type)
{
    // Switch statement that removes the tresure thats sold from the array of treasure and then increments the variable gold accordingly.
    switch(type)
    {
        case 'R':
            addGold(getTreasureAt(0) * 10);
            treasure[0] = 0;
            break;
        case 'N':
            addGold(getTreasureAt(1) * 20);
            treasure[1] = 0;
            break;
        case 'B':
            addGold(getTreasureAt(2) * 30);
            treasure[2] = 0;
            break;
        case 'C':
            addGold(getTreasureAt(3) * 40);
            treasure[3] = 0;
            break;
        case 'G':
            addGold(getTreasureAt(4) * 50);
            treasure[4] = 0;
            break;
    }
}
void Party::sellAllTreasure()
{
    // Removes all treasure from the array and then increments the variable gold accordingly
    for(int i = 0; i < 5; i++)
    {
        switch(i)
    {
        case 0:
            addGold(getTreasureAt(0) * 10);
            treasure[0] = 0;
            break;
        case 1:
            addGold(getTreasureAt(1) * 20);
            treasure[1] = 0;
            break;
        case 2:
            addGold(getTreasureAt(2) * 30);
            treasure[2] = 0;
            break;
        case 3:
            addGold(getTreasureAt(3) * 40);
            treasure[3] = 0;
            break;
        case 4:
            addGold(getTreasureAt(4) * 50);
            treasure[4] = 0;
            break;
    }
    }
}
void Party::addTreasureAt(int index)
{
    treasure[index]++;
}

bool Party::fightMonster()
{
    for(int i = 0; i < party_members.size(); i++)
    {
        cout << party_members.at(i).getName() << "'s weapon: " << party_members.at(i).getWeapon().getWeaponName() << endl;
    }
    ifstream in_file("monsters.txt");//opening the text file with the monster names and challenge levels in it
    
    if(in_file.fail())
    {
        cout << "File failed to open" << endl;
        return -1;
    }

    int challenge_rating;
    string data[2];
    string line;
    vector<string> monster_vector;

    while(!in_file.eof())
    {
        getline(in_file, line);
        split(line, ',', data, 2);

        if(stoi(data[1]) == getRoomsCleared() + 1)//if the challenge rating of the monsters is say 2 and you've cleared 1 room, you can fight them (specified in write up)
        {
            monster_vector.push_back(data[0]);
        } else
        {
            //do nothing, can't fight those ones yet
        }
    }

    string chosen_monster;
    /*
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i) << endl;
    }
    */

    chosen_monster = monster_vector.at(rand() % monster_vector.size());//chooses random monster in the vector containing the possible monsters
    
    cout << chosen_monster << " AHEAD! THEY LOOK HOSTILE!" << endl;

    // Use equation given to calculate whether or not the party can defeat the monster.
    int num_weapons = 0;
    int upgrade_bonus = 0;
    int d = 0;
    int a = 0;
    vector<string> weapon_vector;
    
    for(int i = 0; i < party_members.size(); i++)
    {
        if((party_members.at(i)).getWeapon().getWeaponName() == "")
        {
            weapon_vector.push_back(party_members.at(i).getWeapon().getWeaponName());
        } else 
        {
            num_weapons++;
            upgrade_bonus += party_members.at(i).getWeapon().getUpgradeLevel();

            if(party_members.at(i).getArmor() == true)//if a party member has armor
            {
                a++;//increment armor count
            }
            //we want to know if each paty member has a different weapon
            weapon_vector.push_back(party_members.at(i).getWeapon().getWeaponName());

            cout << i << endl;
            if(i < 4)
            {
                /*
                cout << "weapon vector: " << weapon_vector.at(i) << endl;
                cout << "party weapon: " << party_members.at(i + 1).getWeapon().getWeaponName() << endl;
                doesn't work correctly
                */
                if(weapon_vector.at(i) == party_members.at(i + 1).getWeapon().getWeaponName())
                {
                    d += 0;
                } else
                {
                    d += 1;
                }
            }
        }
    }

    cout << "weapons: " << num_weapons << endl;
    int rnd;//to be used for indexes of random events

    if(num_weapons >= 1)//fight or surrender choice
    {
        char choice;
        cout << "Fight (F) or Surrender (S)?" << endl;
        cin >> choice;

        while(choice != 'F' && choice != 'S')
        {
            cout << "Invalid input" << endl;
            cin >> choice;
        }

        if(choice == 'S')
        {
            rnd = rand() % (party_members.size() - 1);
            cout << rnd << endl;
            cout << party_members.at(rnd).getName() << " has been locked in the room with the " << chosen_monster << " you must leave without them." << endl;
            removePartyMember(rnd);//if we surrender, we lose a random party member (not plus one because it can't be the player)
            return -1;//-1 for surrender
        }
        //if we've chosen to fight then just continue with the rest of the funciton
    } else//if nobody in the party has a weapon then you have to surrender
    {
        cout << "Your party has no weapons, you must surrender" << endl;
        rnd = rand() % party_members.size() - 1;
        cout << party_members.at(rnd).getName() << " has been locked in the room with the " << chosen_monster << " you must leave without them." << endl;
        removePartyMember(rnd);//if we surrender, we lose a random party member (not plus one because it can't be the player)
        return -1;//-1 for surrender
    }

    if(d == 4)//all 5 members have different weapons
    {

    } else
    {
        d = 0;
    }

    int w = num_weapons + upgrade_bonus;
    int c = getRoomsCleared() + 1;//this will always be the challenge rating of the encountered monster

    //two random numbers between 1 and 6 will be used in the equation
    int r1 = rand() % 6 + 1;
    int r2 = rand() % 6 + 1;

    //final equation as specified in write up
    int outcome = (r1 * w + d) - ((r2 * c) / a);
    cout << "NUMBERS: " << endl;
    cout << r1 << endl;
    cout << w << endl;
    cout << d << endl;
    cout << r2 << endl;
    cout << c << endl;
    cout << a << endl;
    cout << "END NUMBERS " << endl;
    cout << "outcome: " << outcome << endl;
    bool b;

    if(outcome > 0)//party wins
    {
        cout << "*****" << endl;
        cout << "Results: " << endl;
        cout << "Your party has defeated the " << chosen_monster << "!" << endl;
        cout << "You're rewarded with: " << endl;
        cout << 10 * c << " gold" << endl;
        cout << 5 * c << " ingredients" << endl;
        b = true;
        addGold(10 * c);
        addIngredients(5 * c);
        //10% chance the monster drops a key
        if((rand() % 1 + 1) == 1)
        {
            addKeys(1);
            cout << "1 key" << endl;
        }

        cout << "*****" << endl;

        for(int i = 0; i < party_members.size(); i++)
        {
            if(rand() % 2 + 1 == 1)//50% chance to lose a point of hunger
            {
                party_members.at(i).removeFullness(1);
            }
        }
        //ONCE DEFEATED IT SHOULD NOT APPEAR AGAIN, NEEDS IMPLEMENTATION!!!!!!!!!!!!!!!
    } else//party loses
    {
        b = false;
        removeGold((getGold() / 4) - 0.5);//party loses 1/4 of their gold rounded down to the nearest integer
        removeIngredients(rand() % 30 + 1);//randomly remove up to 30kg of ingredients
        cout << "*****" << endl;
        cout << "Results: " << endl;
        cout << "After a tough fight, your party was defeated by the " << chosen_monster << endl;
        cout << "You're forced to flee, dropping some of your items in the process: " << endl;
        cout << "-" << (getGold() / 4) - 0.5 << " gold" << endl;
        cout << "-" << rand() % 30 + 1 << " ingredients" << endl;

        //each member besides the player independently has a 10% chance of being slain
        for(int i = 0; i < party_members.size(); i++)
        {
            if((party_members.at(i)).getIsPlayer() == true)//this ensures that the player is not at risk of dying here
            {
                if(rand() % 2 + 1 == 1)//50% chance to lose a point of hunger
                {
                    party_members.at(i).removeFullness(1);
                }
            } else
            {
                if(rand() % 2 + 1 == 1)//50% chance to lose a point of hunger
                {
                    party_members.at(i).removeFullness(1);
                }

                if((party_members.at(i)).getArmor() == true)//if they have armor they are less likely to die
                {
                    if(rand() % 100 + 1 <= 5)//5% chance with armor
                    {
                        cout << party_members.at(i).getName() << " has lost their fight with the " << chosen_monster << ". They won't be returning" << endl;
                        removePartyMember(i);
                    }
                    //else they survive
                } else
                {
                    if(rand() % 10 + 1 == 1)//10% chance without armor
                    {
                        cout << party_members.at(i).getName() << " has lost their fight with the " << chosen_monster << ". They won't be returning" << endl;
                        removePartyMember(i);
                    }
                    //else they survive
                }
            }
        }
        cout << "*****" << endl;
    }

    return b;
}

int Party::getMisfortune()//1, 2, 3, or 4 as specified in write up
{
    // Have a 40 percent chance of a list of misfortunes falling upon the party and its members.

    return 1;
}

void Party::removePartyMember(int index)
{
    party_members.erase(party_members.begin() + index);
}

void Party::addPartyMember(Member member)
{
    party_members.push_back(member);
}

void Party::printPartyMembers()
{
    for(int i = 0; i < party_members.size(); i++)
    {
        cout << (party_members.at(i)).getName() << endl;
        cout << party_members.at(i).getFullness() << endl;
        cout << i << endl;
    }
}

bool Party::doorPuzzle()
{
    // Basically make rock, paper, scizzors and implement it.
    return 1;
}
bool Party::npcPuzzle(string answer)
{
    // Prompt the user with a riddle by reading from a file with said riddle and answer in it. Check their answer.
    return 1;
}

int Party::investigate()
{
    // Investigates a space that has not yet been explored and has a chance of certain events taking place that will be implemented.
    return 1;
}

