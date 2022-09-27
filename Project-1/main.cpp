//------------------------------------------------------------------------------
// Name: Dawson Sanders
// Date: 9/3/2021
// Description: This program calculates the total volume and mass of dumbells made  
// out of materials such as aluminum, iron, lead, and gold. 
//------------------------------------------------------------------------------
#include <iostream>
#include <cmath>

int main()
{
    // Welcome Statement
    std::cout << "*****************************************************" << std::endl;
    std::cout << "*       Welcome to the Dumbbell Mass Calculator.    *" << std::endl;
    std::cout << "*****************************************************" << std::endl << std::endl;
    
    // Declaring variables
    float sphereRadius = 0.0;
    float handleRadius = 0.0;
    float handleLength = 0.0;
    float Volume = 0.0;
    float Mass = 0.0;
    
    // Read sphere radius 
    std::cout << "Enter sphere radius in cm: ";
    std::cin >> sphereRadius;
    std::cout << "Radius of sphere = " << sphereRadius << " cm" << std::endl << std::endl;
    
    // Read handle radius
    std::cout << "Enter handle radius in cm: ";
    std::cin >> handleRadius;
    std::cout << "Radius of handle = " << handleRadius << " cm" << std::endl << std::endl;
     
    // Read handle length
    std::cout << "Enter handle length in cm: ";
    std::cin >> handleLength;
    std::cout << "Length of handle = " << handleLength << " cm" << std::endl << std::endl;
    
    // Sphere volume formula calculation 
    Volume = (4.0 / 3.0) * M_PI * sphereRadius * sphereRadius * sphereRadius; 
    std::cout << "Sphere volume: " << Volume << " cm^3" << std::endl << std::endl;
    
    // Cylinder volume formula calculation
    Volume = M_PI * handleLength * (handleRadius * handleRadius);
    std::cout << "Handle volume: " << Volume << " cm^3" << std::endl << std::endl;
    
    // Total volume of dumbbell
    Volume = 2 * ((4.0 / 3.0) * M_PI * sphereRadius * sphereRadius * sphereRadius) 
    + M_PI * handleLength * (handleRadius * handleRadius);  
    std::cout << "Total dumbbell volume: " << Volume << " cm^3" << std::endl << std::endl;
    
    // Mass of dumbbell made of Aluminum (density = 2.70 g/cm^3)
    Mass = ((2 * (4.0 / 3.0) * M_PI * (sphereRadius * sphereRadius * sphereRadius)) 
    + (M_PI * handleLength * (handleRadius * handleRadius))) * 2.70;
    std::cout << "Mass of dumbbell made of aluminum: " << Mass << " g" << std::endl << std::endl;

    // Mass of dumbbell made of Iron (density = 7.874 g/cm^3)
    Mass = ((2 * (4.0 / 3.0) * M_PI * (sphereRadius * sphereRadius * sphereRadius)) 
    + (M_PI * handleLength * (handleRadius * handleRadius))) * 7.874;
    std::cout << "Mass of dumbbell made of iron: " << Mass << " g" << std::endl << std::endl;

    // Mass of dumbbell made of Lead (density = 11.29 g/cm^3)
    Mass = ((2 * (4.0 / 3.0) * M_PI * (sphereRadius * sphereRadius * sphereRadius)) 
    + (M_PI * handleLength * (handleRadius * handleRadius))) * 11.29;
    std::cout << "Mass of dumbbell made of lead: " << Mass << " g" << std::endl << std::endl;

    // Mass of dumbbell made of Gold (density = 19.3 g/cm^3)
    Mass = ((2 * (4.0 / 3.0) * M_PI * (sphereRadius * sphereRadius * sphereRadius)) 
    + (M_PI * handleLength * (handleRadius * handleRadius))) * 19.3;
    std::cout << "Mass of dumbbell made of gold: " << Mass << " g" << std::endl << std::endl;
    
    return 0;
}












