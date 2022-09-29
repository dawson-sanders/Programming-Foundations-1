//------------------------------------------------------------
// Purpose: Program to simulate the classic 1970s adventure game.
//          Rooms in the maze are described by separate functions.
//          The user finds gold/food as they travel, fights a
//          variety of creatures, and eventually finds the exit.
//
// Author: John Gauch
// Author: Dawson Sanders
//------------------------------------------------------------
#include "player.h"
#include "room.h"

int main()
{
    // Initialize game
    srandom(time(NULL));

    // Create room1
    Room room1;
    room1.setroomName("entrance");
    room1.setroomDescription("\nYou just stumbled into a hole in the ground. When you\n"
    "shake off the dirt and leaves you realize you are in\n"
    "the entrance to a cave that looks man made. As you\n"
    "take a look around, you decide it might be fun to explore.\n");
    room1.setTreasure(100);
    room1.setCreature("BUNNY");
    room1.setFood("STEAK");
    room1.setItem("flashlight");
    room1.Print();
   
   
    // Create room2
    Room room2;
    room2.setroomName("throne room");
    room2.setroomDescription("\nYou have entered the throne room. In the middle\n" 
    "of the room there is a giant wooden throne with\n"
    "swords molded into it. As you take a closer look at the\n"
    "swords, you see that there are ingravings of trolls\n"
    "chasing humans. Hmmm, maybe this is not a great place to stop for a rest.\n"
    "All of the sudden a troll appears from the left of the throne.\n");
    room2.setTreasure(100);
    room2.setCreature("TROLL");
    room2.setFood("CANDY");
    room2.setItem("shovel");         
    room2.Print();
   
    // Create player
    Player player;
    player.setName("Dawson");
    player.setGold(0);
    player.setHealth(MAX_HEALTH);
    player.setItems("");
   
    // Call Player methods
    player.Print();
 
   

    // Call Room1 methods
    Room room; 
    room.roomInfo1("");
    room.FindTreasure(100);
    room.FightBattle(BUNNY);
    room.EatFood(STEAK);
    room.itemRoom1("");
  
    int gold;
    gold = player.getGold();
    gold = gold + 50;           // 50 is for finding gold
    player.setGold(gold);
  
    int health;
    health = player.getHealth();
    health = health - 5;           // 5 is from tripping over bunny damage
    player.setHealth(health);
   
    health = player.getHealth();
    health = health + 20;           // 20 is from eating steak to add 20 to health
    player.setHealth(health); 
                        
    // Call Player methods for Room1
    player.addItem("flashlight");
    player.Print();
   
   // Call Room2 methods
    room.roomInfo2("");
    room.FindTreasure(100);
    room.FightBattle(TROLL);
    room.EatFood(CANDY);
    room.itemRoom2("");
  
    gold = player.getGold();
    gold = gold + 50;           // 50 is for finding gold
    player.setGold(gold);
  
    health = player.getHealth();
    health = health - 20;           // 10 is from troll damage
    player.setHealth(health);
   
    health = player.getHealth();
    health = health + 10;           // 10 is from eating candy to add 10 to health
    player.setHealth(health); 
   
    // Call Player methods for Room2
    player.addItem("shovel");
    player.Print();
  
    return 0;
}
