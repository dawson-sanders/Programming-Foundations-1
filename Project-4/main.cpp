//------------------------------------------------------------
// Purpose: Program to simulate the classic 1970s adventure game.
//          Rooms in the maze are described by separate functions.
//          The user finds gold/food as they travel, fights a
//          variety of creatures, and eventually finds the exit.
//
// Author1: John Gauch
// Author2: Dawson Sanders
//------------------------------------------------------------
#include <cstdlib>
#include <iostream>

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

// Other constants
const int TUITION = 50;
const int BEER = 10;
const int max_gold = 1000;

// Function prototypes
void PrintStatus(int gold, int health);
int FindTreasure(const int max_gold);
void EatFood(const int food, int &health);
int FightBattle(const int creature);
char GetDirection();
void Exit(int &gold, int &health);
void Room1(int &gold, int &health);
void Room2(int &gold, int &health);
void Room3(int &gold, int &health);
void Room4(int &gold, int &health);

// ADD FUNCTION PROTOTYPES HERE
void Room5(int &gold, int &health);
void Room6(int &gold, int &health);
void Room7(int &gold, int &health);

//------------------------------------------------------------
// Purpose: To print the player's status
// Input:   Gold amount, health value
// Output:  None
//------------------------------------------------------------
void PrintStatus(int gold, int health)
{
    if (gold > 2 * health)
        std::cout << std::endl << "You are rich with " << gold 
            << " gold, but your health is only " << health << std::endl;
    else if (health > 2 * gold)
        std::cout << std::endl << "You are strong with " << health 
           << " health, but you only have " << gold << " gold" << std::endl;
    else
        std::cout << std::endl << "Your health is " << health 
           << " and you have " << gold << " gold" << std::endl;
}

//------------------------------------------------------------
// Purpose: To calculate how much treasure is found
// Input:   Maximum amount of gold possible
// Output:  Actual amount of gold found
//------------------------------------------------------------
int FindTreasure(const int max_gold)
{
    int gold = 1 + random() % max_gold;
    if (gold < max_gold/2)
        std::cout << "\nYou find " << gold << " gold pieces on the ground.\n";
    else
        std::cout << "\nYou find a huge mound of " << gold << " gold pieces!\n";
    return gold;
}

//------------------------------------------------------------
// Purpose: To eating food item to restore health.
// Input:   Food item number between [0..2]
// Output:  Health value after eating food.
//------------------------------------------------------------
void EatFood(const int food, int & health)
{
   switch (food)
   {
        case CANDY:
        health = health + CANDY_RESTORE;
        std::cout << "\nYou find a half eaten energy bar on the floor " 
            << "which restores your health by " << CANDY_RESTORE << std::endl;
        break;
        
        case STEAK:
        health = health + STEAK_RESTORE;
        std::cout << "\nYou find a warm and jucy steak underneath the table " 
            << "which restores your health by " << STEAK_RESTORE << std::endl;
        break;
        
        case POTION:
        health = health + POTION_RESTORE;
        std::cout << "\nYou find a green glowing potion on a shelf " 
            << "which restores your health by " << POTION_RESTORE << std::endl;
        break;
        
        default:
        std::cout << "\nYour stomach is rumbling, but there is nothing to eat\n";
        break;
    }

    // Check maximum value for health
    if (health > 100) 
        health = 100;
}

//------------------------------------------------------------
// Purpose: To simulate battle with a creature
// Input:   Creature number between [0..3]
// Output:  Amount of damage done to your health.
//------------------------------------------------------------
int FightBattle(const int creature)
{
    int damage = 0;
    switch (creature)
    {
        case BUNNY:
        damage = 1 + random() % BUNNY_DAMAGE;
        std::cout << "\nYou trip over a cute bunny and do " 
            << damage << " damage to your health.\n";
        break;
        
        case DWARF:
        damage = 1 + random() % DWARF_DAMAGE;
        std::cout << "\nA drunken dwarf hits you with a beer mug and does " 
            << damage << " damage to your health.\n";
        break;
      
        case TROLL:
        damage = 1 + random() % TROLL_DAMAGE;
        std::cout << "\nThe angry troll kicks you in the rear and does " 
            << damage << " damage to your health.\n";
        break;
        default:
        std::cout << "\nIt is ghostly quiet here, you must be alone\n";
        break;
    }
    return damage;
}

//------------------------------------------------------------
// Purpose: To get direction from user
// Input:   None
// Output:  Character code for N,S,E,W direction
//------------------------------------------------------------
char GetDirection()
{
    std::cout << "\nWhat direction would you like to go (N,S,E,W): ";
    char direction;
    std::cin >> direction;
    direction = toupper(direction);
    while ((direction != 'N') && (direction != 'S') &&
        (direction != 'E') && (direction != 'W'))
    {
        std::cout << "Sorry, You can not go that way...\n";
        std::cout << "What direction would you like to go (N,S,E,W): ";
        std::cin >> direction;
        direction = toupper(direction);
    }
    return direction;
}

//------------------------------------------------------------
// Purpose: To find the cave exit
// Input:   The gold and health variables
// Output:  None
//------------------------------------------------------------
void Exit(int &gold, int &health)
{
    std::cout << "\n------------------------------------------------------------\n";
    std::cout << "\nYou crawl out of the cave and blink your eyes to\n";
    std::cout << "adjust to the bright sunshine. Congratulations,\n"; 
    std::cout << "you made it out of the cave with " << health << " health!\n";

    if (gold >= TUITION)
    {
        std::cout << "\nYou empty your pockets and discover " << gold << " gold coins.\n";
        std::cout << "This will pay for tuition next semester!!!\n";
    }
    else if (gold >= BEER)
    {
        std::cout << "\nYou notice that you have " << gold << " gold coins in your pocket.\n";
        std::cout << "This will pay for beer and pizza next semester!!!\n";
    }
    else 
    {
        std::cout << "\nYou check your pocket and find " << gold << " gold coins.\n";
        std::cout << "Exploring caves sure is a hard way to make money!!!\n";
    }
   
    // Leave program
    exit(0);
}

//------------------------------------------------------------
// Purpose: To visit a room in the cave
// Input:   The gold and health variables
// Output:  None
//------------------------------------------------------------
void Room1(int &gold, int &health)
{
    std::cout << "\n------------------------------------------------------------\n";
    std::cout << "\nYou have entered room 1.\n";
    std::cout << "\nYou just stumbled into a hole in the ground. When you\n";
    std::cout << "shake off the dirt and leaves you realize you are in\n";
    std::cout << "the entrance to a cave that looks man made. As you\n";
    std::cout << "take a look around, you decide it might be fun to explore.\n";
    std::cout << "As you enter the mouth of the cave you notice something on the\n";
    std::cout << "ground by the left wall of the cave. As you approach you notice\n";
    std::cout << "that its gold!\n";
   
    gold = FindTreasure(1000);
    PrintStatus(gold, health);
    char direction;
   
    do
    {
        switch (GetDirection())
        {
            case 'N':
            Room2(gold, health);
            break;
       
            case 'S':
            Room7(gold, health);
            break;
       
            default:
            std::cout << "\nOption not available please enter another direction" << std::endl;
        }
    }
    while (direction != 'N' || direction != 'S');
}

//------------------------------------------------------------
// Purpose: To visit a room in the cave
// Input:   The gold and health variables
// Output:  None
//------------------------------------------------------------
void Room2(int &gold, int &health)
{
    std::cout << "\n------------------------------------------------------------\n";
    std::cout << "\nYou have entered room 2, the throne room.\n";
    std::cout << "\nIn the middle of the room there is a giant wooden throne with\n";
    std::cout << "swords molded into it. As you take a closer look at the\n";
    std::cout << "swords, you see that there are ingravings of trolls\n";
    std::cout << "chasing humans. Hmmm, maybe this is not a great place to stop for a rest.\n";
    std::cout << "All of the sudden a troll appears from the left of the throne.\n";

    int damage = FightBattle(TROLL);
    health = health - damage;
    std::cout << "\nYou then stumble out of the room and try to get your bearings straight. \n";
    PrintStatus(gold, health);
    char direction;
   
    do
    {
        switch (GetDirection())
        {
            case 'N':
            Room5(gold, health);
            break;
       
            case 'S':
            Room1(gold, health);
            break;
       
            case 'E':
            Room3(gold, health);
            break;
       
            case 'W':
            Room4(gold, health);
            break;
       
            default:
            std::cout << "\nOption not available please enter another direction" << std::endl;
        }
    }
    while (direction != 'N' || direction != 'S' || direction != 'E' || direction != 'W');
}

//------------------------------------------------------------
// Purpose: To visit a room in the cave
// Input:   The gold and health variables
// Output:  None
//------------------------------------------------------------
void Room3(int &gold, int &health)
{
    std::cout << "\n------------------------------------------------------------\n";
    std::cout << "\nYou have entered room 3, an abandoned pub.\n";
    std::cout << "\nThere are piles of dirty dishes and empty beer mugs all over the place.\n";
    std::cout << "You hear someone coming and duck behind a table to hide.\n";

    EatFood(STEAK, health);
    int damage = FightBattle(DWARF);
    health = health - damage;

    PrintStatus(gold, health);
   
    char direction;
   
    do
    {
        switch (GetDirection())
        {
            case 'S':
            Exit(gold, health);
            break;
       
            case 'W':
            Room2(gold, health);
            break;
       
            default:
            std::cout << "\nOption not available please enter another direction" << std::endl;
        }
    }
    while (direction != 'S' || direction != 'W');
}

//------------------------------------------------------------
// Purpose: To visit a room in the cave
// Input:   The gold and health variables
// Output:  None
//------------------------------------------------------------
void Room4(int &gold, int &health)
{
    std::cout << "\n------------------------------------------------------------\n";
    std::cout << "You have entered room 4, the storage room.\n";
    std::cout << "\nYou see huge empty boxes. Looking at the side of one box, you see\n";
    std::cout << "'ACME troll food'. You better get out of here before you end up on the menu.\n";
  
    EatFood(CANDY, health);
    PrintStatus(gold, health);
    char direction;
   
    do
    {
        switch (GetDirection())
        {
            case 'N':
            Room5(gold, health);
            break;
       
            case 'E':
            Room2(gold, health);
            break;
       
            default:
            std::cout << "\nOption not available please enter another direction" << std::endl;
        }
    }
    while (direction != 'N' || direction != 'E');
}

//------------------------------------------------------------
// Purpose: To visit a room in the cave
// Input:   The gold and health variables
// Output:  None
//------------------------------------------------------------
void Room5(int &gold, int &health)
{
    std::cout << "\n------------------------------------------------------------\n";
    std::cout << "You have entered room 5, the courtyard.\n";
    std::cout << "As you walk through the courtyard, the smell of flowers is in the air.\n";
   
    int damage = FightBattle(BUNNY);
    health = health - damage;
    PrintStatus(gold, health);
    char direction;
   
    do
    {
        switch (GetDirection())
        {
            case 'S':
            Room4(gold, health);
            break;
       
            case 'E':
            Room2(gold, health);
            break;
       
            case 'W':
            Room6(gold, health);
            break;
       
            default:
            std::cout << "\nOption not available please enter another direction" << std::endl;
        }
    }
    while (direction != 'S' || direction != 'E' || direction != 'W');
}

//------------------------------------------------------------
// Purpose: To visit a room in the cave
// Input:   The gold and health variables
// Output:  None
//------------------------------------------------------------
void Room6(int &gold, int &health)
{
    std::cout << "\n------------------------------------------------------------\n";
    std::cout << "You have entered room 6, the graveyard.\n";
   
    gold = FindTreasure(1000) + gold;
    FightBattle(10);
    PrintStatus(gold, health);
    char direction;
   
    do
    {
        switch (GetDirection())
        {
            case 'S':
            Room7(gold, health);
            break;
       
            case 'E':
            Room5(gold, health);
            break;
      
            default:
            std::cout << "\nOption not available please enter another direction" << std::endl;
        }
    }
    while (direction != 'S' || direction != 'E');
}

//------------------------------------------------------------
// Purpose: To visit a room in the cave
// Input:   The gold and health variables
// Output:  None
//------------------------------------------------------------
void Room7(int &gold, int &health)
{
    std::cout << "\n------------------------------------------------------------\n";
    std::cout << "You have entered room 7, the war room.\n";
    std::cout << "There are maps of all the kingdoms spread out over the room\n";
  
    EatFood(POTION, health);
    PrintStatus(gold, health);
    char direction;
   
    do
    {
        switch (GetDirection())
        {
            case 'N':
            Room1(gold, health);
            break;
    
            case 'E':
            Exit(gold, health);
            break;
       
            case 'W':
            Room6(gold, health);
            break;
       
            default:
            std::cout << "\nOption not available please enter another direction" << std::endl;
        }
    }
    while (direction != 'N' || direction != 'E' || direction != 'W');
}

//------------------------------------------------------------
// Purpose: The main program
// Input:   None
// Output:  None
//------------------------------------------------------------
int main()
{
    // Initialize game
    int gold = 0;
    int health = 100;
    srandom(time(NULL));
    Room1(gold, health);

    return 0;
}






