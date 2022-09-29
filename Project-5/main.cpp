//---------------------------------------------------
// Purpose: Implement menu-based spreadsheet program.
// Author: Dawson Sanders
//---------------------------------------------------
#include <cmath>
#include <cstdlib>
#include <iostream>

// Global constants
const int ROWS = 9;
const int COLS = 9;

//---------------------------------------------------
// Read and convert location string to row col value
//---------------------------------------------------
void get_location(int &row, int &col)
{
    // Initialize variables
    row = -1;
    col = -1;

    // Loop until a valid location is entered
    while (row < 0 || row > ROWS-1 || col < 0 || col > COLS-1)
    {
        // Get user input
        std::cout << "Enter location between A1 and I9: ";
        std::string location = "";
        std::cin >> location;
   
        // Calculate col between 0 and COLS-1
        if (location.length() > 0)
            col = location[0] - 'A';
 
        // Print error message
        if (col < 0 || col > COLS-1)
            std::cout << "Error: column should be between A and I" << std::endl;

        // Calculate row between 0 and ROWS-1
        if (location.length() > 1)
            row = location[1] - '1';
 
        // Print error message
        if (row < 0 || row > ROWS-1)
            std::cout << "Error: row should be between 1 and 9" << std::endl;
    }
}

void get_final_location(int &row, int &col)
{
    // Initialize variables
    row = -1;
    col = -1;

    // Loop until a valid location is entered
    while (row < 0 || row > ROWS-1 || col < 0 || col > COLS-1)
    {
        // Get user input
        std::cout << "Enter location where you want the result: ";
        std::string location = "";
        std::cin >> location;
   
        // Calculate col between 0 and COLS-1
        if (location.length() > 0)
            col = location[0] - 'A';
 
        // Print error message
        if (col < 0 || col > COLS-1)
            std::cout << "Error: column should be between A and I" << std::endl;

        // Calculate row between 0 and ROWS-1
        if (location.length() > 1)
            row = location[1] - '1';
 
        // Print error message
        if (row < 0 || row > ROWS-1)
            std::cout << "Error: row should be between 1 and 9" << std::endl;
    }
}

//---------------------------------------------------
// Print command menu to user and get input
//---------------------------------------------------
int get_menu_choice()
{
    // Print command menu
    std::cout << "Welcome to MiniCalc the PF1 Killer App\n"
        << "   0) Quit the program\n"
        << "   1) Store specified data value\n"
        << "   2) Store random data values\n"
        << "   3) Calculate minimum of data values\n"
        << "   4) Calculate maximum of data values\n"
        << "   5) Calculate sum of data values\n"
        << "   6) Calculate average of data values\n"
        << "   7) Calculate standard deviation of data values\n";

    // Initialize variables
    std::string input = "";
    int command = -1;

    // Loop until a valid location is entered
    while (command < 0 || command > 7)
    {
        // Get user input
        std::cout << "Enter command: ";
        std::cin >> input;
        if (input.length() == 1)
            command = input[0] - '0';

        // Print error message
        if (command < 0 || command > 7)
            std::cout << "Error: command should be between 0 and 7" << std::endl;
    }
    return command;
}

//---------------------------------------------------
// Print the 2D array
//---------------------------------------------------
void print_array(float array[ROWS][COLS])
{
    // Print values
    std::cout << "     ";
    for (int col = 0; col < COLS; col++)
        std::cout << char('A' + col) << "   ";
    std::cout << std::endl;

    // Print line
    std::cout << "   +";
    for (int col = 0; col < COLS; col++)
        std::cout << "---+";
    std::cout << "\n";

    // Print board
    for (int row = 0; row < ROWS; row++)
    {
        // Print values
        std::cout << " " << row + 1 << " | ";
        for (int col = 0; col < COLS; col++)
            std::cout << array[row][col] << " | ";
        std::cout << std::endl;

        // Print line
        std::cout << "   +";
        for (int col = 0; col < COLS; col++)
            std::cout << "---+";
        std::cout << "\n";
    }
}

void storeValue(float array[ROWS][COLS])
{
    int row1, col1, row2, col2;
    std::cout << "Enter Value: ";
    float value;
    std::cin >> value;
    get_location(row1,col1);
    get_location(row2,col2);
    for (int row = row1; row <= row2; row++)
        for (int col = col1; col <= col2; col++)
            array[row][col] = value;  
}

void random(float array[ROWS][COLS])
{
    int lower, upper;
    std::cout << "Enter Low: ";
    std::cin >> lower;
    std::cout << "Enter High: ";
    std::cin >> upper;
    int row1, col1, row2, col2;
    get_location(row1,col1);
    get_location(row2,col2);
    for (int row = row1; row <= row2; row++)
        for (int col = col1; col <= col2; col++)
            array[row][col] = (rand() % (upper - lower + 1)) + lower; 
         
}

void minimum(float array[ROWS][COLS], int row1, int col1, int row2, int col2)
{
    float minimum = array[row1][col1];
    for (int row = row1; row <= row2; row++) 
    {
        for (int col = col1; col <= col2; col++) 
        {
            if (array[row][col] < minimum) 
                minimum = array[row][col];
        }
    }
    get_final_location(row1, col1);
    array[row1][col1] = minimum;
}
  
   
void maximum(float array[ROWS][COLS], int row1, int col1, int row2, int col2)
{
    float maximum = array[row1][col1];
    for (int row = row1; row <= row2; row++) 
    {
        for (int col = col1; col <= col2; col++) 
        {
            if (array[row][col] > maximum) 
                maximum = array[row][col];
        }
    }
    get_final_location(row1, col1);
    array[row1][col1] = maximum;     
}
   

void Sum(float array[ROWS][COLS], int row1, int col1, int row2, int col2) 
{
    float sum = 0;
    int count = 0;
    for (int row = row1; row <= row2; row++) 
    {
        for (int col = col1; col <= col2; col++) 
        {
            sum += array[row][col];
            count++;
        }
    }
    float sumValues = sum;
    get_final_location(row1, col1);
    array[row1][col1] = sumValues;
}


void average(float array[ROWS][COLS], int row1, int col1, int row2, int col2) 
{
    float sum = 0;
    int count = 0;
    for (int row = row1; row <= row2; row++) 
    {
        for (int col = col1; col <= col2; col++) 
        {
            sum += array[row][col];
            count++;
        }
    }
    
    float average = sum / count;
    get_final_location(row1, col1);
    array[row1][col1] = average;
}

void standard(float array[ROWS][COLS], int row1, int col1, int row2, int col2)
{
    float sum = 0;
    int count = 0;
    for (int row = row1; row <= row2; row++) 
    {
        for (int col = col1; col <= col2; col++) 
        {
            sum += array[row][col];
            count++;
        }
    }
    
    float average = sum / count;
    float total = 0;
    count = 0;
    for (int row = row1; row <= row2; row++) 
    {
        for (int col = col1; col <= col2; col++) 
        {
            float difference = array[row][col] - average;
            total = total + difference * difference;
            count++;
        }
    }
    
    float deviance = total / count;
    float standard = sqrt(deviance);
    get_final_location(row1, col1);
    array[row1][col1] = standard;
    
}

//---------------------------------------------------
// Main program
//---------------------------------------------------
int main()
{
    // Initialize spreadsheet array
    float data[ROWS][COLS];
    for (int row = 0; row < ROWS; row++)
        for (int col = 0; col < COLS; col++)
            data[row][col] = 0;
    print_array(data);
    
    // Loop processing menu commands
    int command = get_menu_choice();
    while (command != 0)
    {
        if (command == 1)
            storeValue(data);
        if (command == 2)
            random(data);
        if (command == 3)
        {
            int row1, col1, row2, col2;
            get_location(row1, col1);
            get_location(row2, col2);
            minimum(data, row1, col1, row2, col2);
        }
        if (command == 4)
        {
            int row1, col1, row2, col2;
            get_location(row1, col1);
            get_location(row2, col2);
            maximum(data, row1, col1, row2, col2);
        }
        if (command == 5)
        {
            int row1, col1, row2, col2;
            get_location(row1, col1);
            get_location(row2, col2);
            Sum(data, row1, col1, row2, col2);
        }
        if (command == 6)
        {
            int row1, col1, row2, col2;
            get_location(row1, col1);
            get_location(row2, col2);
            average(data, row1, col1, row2, col2);
        }
        if (command == 7)
        {
            int row1, col1, row2, col2;
            get_location(row1, col1);
            get_location(row2, col2);
            standard(data, row1, col1, row2, col2);
        }
      
        print_array(data);
     
        // Get next command
        command = get_menu_choice();
    }
    return 0;
}




