//---------------------------------------------------
// Purpose: Header file for the Room class
// Author: Dawson Sanders
//---------------------------------------------------
#include <cstdlib>
#include <iostream>
using namespace std;

// Food constants
const int CANDY = 0;
const int STEAK = 1;
const int POTION = 2;
const int CANDY_RESTORE = 10;
const int STEAK_RESTORE = 20;
const int POTION_RESTORE = 40;

// Creature constants
const int BUNNY = 0;
const int DWARF = 1;
const int TROLL = 2;
const int BUNNY_DAMAGE = 5;
const int DWARF_DAMAGE = 10;
const int TROLL_DAMAGE = 20;

//Other contants
const int MAX_TREASURE = 100;

class Room
{
    private:
        string roomName;
        string roomDescription;
        int Treasure;
        string Food;
        string Creature;
        string Item;
  
    public:
        Room ();
        ~Room ();

        void setroomName (const string roomname);
        void setroomDescription (const string roomdescription);
        void setTreasure (const int treasure);
        void setFood (const string food);
        void setCreature (const string creature);
        void setItem (const string item);
  

        string getroomName () const;
        string getroomDescription () const;
        int getTreasure () const;
        string getFood () const;
        string getCreature () const;
        string getItem () const;
  

        void Print ();
        void roomInfo1 (const string info);
        void roomInfo2 (const string info);
        void FindTreasure (const int MAX_GOLD);
        void FightBattle (const int creature);
        void EatFood (const int food);
        void itemRoom1 (const string item);
        void itemRoom2 (const string item);
};



