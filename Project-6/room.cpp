//---------------------------------------------------
// Purpose: Implementation file for the Room class
// Author: Dawson Sanders
//---------------------------------------------------
#include "room.h"

//------------------------------------------------------------
// Purpose: Constructor function
//------------------------------------------------------------
Room::Room()
{
    roomName = "none";
    roomDescription = "none";
    Treasure = 0;
    Food = "none";
    Creature = "none";
    Item = "none";
}

//------------------------------------------------------------
// Purpose: Destructor function
//------------------------------------------------------------
Room::~Room()
{
}

//------------------------------------------------------------
// Purpose: Set Room Name value
//------------------------------------------------------------
void Room::setroomName(const string roomname)
{
    // cout << "Room Information" << endl;
    roomName = roomname;
}

//------------------------------------------------------------
// Purpose: Set Room Description value
//------------------------------------------------------------
void Room::setroomDescription(const string roomdescription)
{
    roomDescription = roomdescription;
}

//------------------------------------------------------------
// Purpose: Set Treasure value
//------------------------------------------------------------
void Room::setTreasure(const int treasure)
{
    Treasure = treasure;
    if (Treasure > MAX_TREASURE) Treasure = MAX_TREASURE;
        if (Treasure < 0) 
            Treasure = 0;
}

//------------------------------------------------------------
// Purpose: Set Food value
//------------------------------------------------------------
void Room::setFood(const string food)
{
    Food = food;
}

//------------------------------------------------------------
// Purpose: Set Creature value
//------------------------------------------------------------
void Room::setCreature(const string creature)
{
    Creature = creature;
}

//------------------------------------------------------------
// Purpose: Set Item value
//------------------------------------------------------------
void Room::setItem(const string item)
{
    Item = item;
}

//------------------------------------------------------------
// Purpose: Get Room Name value
//------------------------------------------------------------
string Room::getroomName() const
{
    return roomName;
}

//------------------------------------------------------------
// Purpose: Get Room Description value
//------------------------------------------------------------
string Room::getroomDescription() const
{
    return roomDescription;
}

//------------------------------------------------------------
// Purpose: Get Treasure value
//------------------------------------------------------------
int Room::getTreasure() const
{
    return Treasure;
}

//------------------------------------------------------------
// Purpose: Get Food value
//------------------------------------------------------------
string Room::getFood() const
{
    return Food;
}

//------------------------------------------------------------
// Purpose: Get Creature value
//------------------------------------------------------------
string Room::getCreature() const
{
    return Creature;
}

//------------------------------------------------------------
// Purpose: Get Item value
//------------------------------------------------------------
string Room::getItem() const
{
    return Item;
}   

//------------------------------------------------------------
// Purpose: Print all Room data
//------------------------------------------------------------
void Room::Print()
{
    cout << "\nRoom Information" << endl;
    cout << "Name: " << roomName << endl;
    cout << "Description: " << roomDescription << endl;
    cout << "Treasure: " << Treasure << endl;
    cout << "Creature: " << Creature << endl;
    cout << "Food: " << Food << endl;
    cout << "Item: " << Item << endl;
}

//------------------------------------------------------------
// Purpose: Method to print Room 1 Information
//------------------------------------------------------------
void Room::roomInfo1(const string info)
{
    cout << "\nYou just stumbled into a hole in the ground. When you\n";
    cout << "shake off the dirt and leaves you realize you are in\n";
    cout << "the entrance to a cave that looks man made. As you\n";
    cout << "take a look around, you decide it might be fun to explore.\n";
}

void Room::roomInfo2(const string info)
{
    cout << "\nYou have entered the throne room. In the middle\n"; 
    cout << "of the room there is a giant wooden throne with\n";
    cout << "swords molded into it. As you take a closer look at the\n";
    cout << "swords, you see that there are ingravings of trolls\n";
    cout << "chasing humans. Hmmm, maybe this is not a great place to stop for a rest.\n";
    cout << "All of the sudden a troll appears from the left of the throne.\n";
}

//------------------------------------------------------------
// Purpose: Method that simulates player finding gold
//------------------------------------------------------------
void Room::FindTreasure(const int MAX_GOLD)
{
    int gold = 50;
    cout << "\nYou find " << gold << " gold pieces on the ground.";
}

//------------------------------------------------------------
// Purpose: Method that simulates player eating food
//------------------------------------------------------------
void Room::EatFood(const int food)//, int & health)
{
    int health = 0;
    switch (food)
    {
        case CANDY:
        health = health + CANDY_RESTORE;
        cout << "You find a half eaten energy bar on the floor " 
            << "which restores your health by " << CANDY_RESTORE << endl;
        break;
      
        case STEAK:
        health = health + STEAK_RESTORE;
        cout << "You find a warm and jucy steak underneath the table " 
            << "which restores your health by " << STEAK_RESTORE << endl;
        break;
      
        case POTION:
        health = health + POTION_RESTORE;
        cout << "\nYou find a green glowing potion on a shelf " 
            << "which restores your health by " << POTION_RESTORE << endl;
        break;
        
        default:
        cout << "\nYour stomach is rumbling, but there is nothing to eat\n";
        break;
   }
}

//------------------------------------------------------------
// Purpose: Method that simulates player fighting creature
//------------------------------------------------------------
void Room::FightBattle(const int creature)
{
    int damage = 0;
    switch (creature)
    {
        case BUNNY:
        damage = BUNNY_DAMAGE;
        cout << "\nYou trip over a cute bunny and do " 
            << damage << " damage to your health.\n";
        break;
        
        case DWARF:
        damage = DWARF_DAMAGE;
        cout << "\nA drunken dwarf hits you with a beer mug and does " 
            << damage << " damage to your health.\n";
        break;
        
        case TROLL:
        damage = TROLL_DAMAGE;
        cout << "\nThe angry troll kicks you in the rear and does " 
            << damage << " damage to your health.\n";
        break;
        
        default:
        cout << "\nIt is ghostly quiet here, you must be alone\n";
        break;
   }
}

//---------------------------------------------------------------------
// Purpose: Method that simulates player picking up an item for Room 1
//----------------------------------------------------------------------
void Room::itemRoom1(const string item)
{
    cout << "On the floor you see a flashlight under a pile of papers." << endl;
    cout << "You put it in your backback!" << endl;
}

//---------------------------------------------------------------------
// Purpose: Method that simulates player picking up an item for Room 2
//----------------------------------------------------------------------
void Room::itemRoom2(const string item)
{
    cout << "On the floor you see a shovel on the ground." << endl;
    cout << "You put it in your backback!" << endl;
}




