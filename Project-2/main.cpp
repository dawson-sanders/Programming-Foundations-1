//------------------------------------------------------------------------------
// Name: Dawson Sanders
// Date: 9/17/21
// Description: This program simulates a portion of the McDonalds Menu where users
// can select which meal they would like and a price for the meal prints to the screen
//------------------------------------------------------------------------------
#include <iostream>
#include <cmath>
#include <iomanip>

    // Global variables
    const float ChickenPrice = 6.99;
    const float MacPrice = 8.29;
    const float CheeseburgerPrice = 6.39;
    const float McNuggetsPrice = 8.59;
    const float FishPrice = 7.99;
    const float SmallPrice = 1.00;
    const float MediumPrice = 1.50;
    const float LargePrice = 2.00;
    const float TaxRate = 0.065;

    void mealMenu()
    {
        std::cout << "Please select a meal below:" << std::endl;
        std::cout << "  " << 1 << ") Crispy Chicken Sandwich Meal ($6.99)" << std::endl;
        std::cout << "  " << 2 << ") Big Mac Meal ($8.29)" << std::endl;
        std::cout << "  " << 3 << ") Cheeseburger Meal ($6.39)" << std::endl;
        std::cout << "  " << 4 << ") 10 Piece McNuggets Meal ($8.59)" << std::endl;
        std::cout << "  " << 5 << ") Filet O Fish Meal ($7.99)" << std::endl;
    }
    
    void drinkMenu()
    {
        std::cout << "Please select one of the drinks below: " << std::endl;
        std::cout << "  " << 1 << ") Coke " << std::endl;
        std::cout << "  " << 2 << ") Orange Crush " << std::endl;
        std::cout << "  " << 3 << ") Sprite " << std::endl;
        std::cout << "  " << 4 << ") Diet Coke " << std::endl;
    }
    
    void sizeMenu()
    {
        std::cout << "What size would you like? " << std::endl;
        std::cout << "  " << 1 << ") Small (+ $1.00) " << std::endl;
        std::cout << "  " << 2 << ") Medium (+ $1.50) " << std::endl;
        std::cout << "  " << 3 << ") Large (+ $2.00) " << std::endl;
    }

int main()
{
    // Declare local variables
    float Total = 0;
    float Final = 0;
    int Meal = 0;
    int Drink = 0;
    int Size = 0;

    // Prompting meal option outputs 
    std::cout << "Welcome to McDonald's Express Lane" << std::endl << std::endl;
    mealMenu();
    std::cout << "Enter Meal Selection: ";
    std::cin >> Meal; 
    std::cout << std::endl;
    
    // Error checking if user inputs option that is invalid
    while (Meal <= 0 || Meal >= 6)
    {
        std::cout << "Sorry option not available" << std::endl;
        std::cout << "Enter Meal Selection: ";
        std::cin >> Meal;
        std::cout << std::endl;
    }
    
    // Prompting drink option outputs
    drinkMenu();
    std::cout << "Enter Drink Selection: ";
    std::cin >> Drink; 
    std::cout << std::endl;
    
    // Error checking if user inputs option that is invalid
    while (Drink <= 0 || Drink >= 5)
    {
        std::cout << "Sorry option not available" << std::endl;
        std::cout << "Enter Drink Selection: ";
        std::cin >> Drink;
        std::cout << std::endl;
    }
   
    // Prompting size of drink
    sizeMenu();
    std::cout << "Enter Size Selection: ";
    std::cin >> Size; 
    std::cout << std::endl;
    
    // Error checking if user inputs option that is invalid
    while (Size <= 0 || Size >= 4)
    {
        std::cout << "Sorry option not available" << std::endl;
        std::cout << "Enter New Size" << std::endl;
        std::cin >> Size;
        std::cout << "Enter Size Selection: " << Size << std::endl << std::endl;
    }
   
    // Prompting thank you message 
    std::cout << "Thank you for ordering: " << std::endl;
   
    switch (Meal)
    {
        case 1:
        std::cout << "The Crispy Chicken Sandwich Meal ";
        Total = ChickenPrice;
        break;
        
        case 2: 
        std::cout << "The Big Mac Meal ";
        Total = MacPrice;
        break;
    
        case 3:
        std::cout << "The Cheeseburger Meal ";
        Total = CheeseburgerPrice;
        break;
    
        case 4:
        std::cout << "The 10 Piece McNuggets Meal ";
        Total = McNuggetsPrice;
        break;
    
        case 5:
        std::cout << "The Filet O Fish Meal ";
        Total = FishPrice;
        break;    
    }
   
    switch (Size)
    { 
        case 1:
        std::cout << "and a Small ";
        Total += SmallPrice;
        break;
    
        case 2: 
        std::cout << "and a Medium ";
        Total += MediumPrice;
        break;
    
        case 3:
        std::cout << "and a Large ";
        Total += LargePrice;
    }
   
    switch (Drink)
    { 
        case 1:
        std::cout << "Coke ";
        break;
    
        case 2: 
        std::cout << "Orange Crush ";
        break;
    
        case 3:
        std::cout << "Sprite ";
        break;
    
        case 4:
        std::cout << "Diet Coke ";
        break;
    }
    
    // Price calculation
    std::cout << std::endl;
    std::cout << "Your price with 6.5% tax is: $";
    Final = (Total * TaxRate) + Total;
    std::cout << std::fixed << std::setprecision(2) << Final; 
    
    return 0;
}







