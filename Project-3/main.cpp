//------------------------------------------------------------------------------
// Name: Dawson Sanders
// Date: 10/1/21
// Description: This program allows users to encrypt/decrypt messages using two 
// variations of the classic caesar cipher algorithim 
//------------------------------------------------------------------------------
#include <iostream>
 
int main()
{
    // Declare variables
    char message[120];
    char character;
    int x;
    int option;
    int shiftValue;
    
    // Welcome Statement 
    std::cout << "Welcome to Dawson's Caesar Cipher" << std::endl;
    
    // Asking user if they want to encode or decode a message
    std::cout << "To encode/decode a message choose one of the following options: " << std::endl;
    std::cout << 1 << ") Encrypt the message regularly " << std::endl;
    std::cout << 2 << ") Decrypt the message regularly " << std::endl;
    std::cout << 3 << ") Encrypt the message with improved security " << std::endl;
    std::cout << 4 << ") Decrypt the message with improved security " << std::endl;
    std::cout << "Enter selection: ";
    std::cin >> option;
    
    // Regular Encryption choice 
    switch (option)   
    {
        case 1:
            do
            {
                std::cout << "Enter shift value between 1 and 25: ";
                std::cin >> shiftValue;
            }
            while (shiftValue < 1 || shiftValue > 25);
     
            std::cout << "Enter a message to encode: ";
            std::cin.ignore();
            std::cin.getline(message, 120);
       
            for(x = 0; message[x] != '\0'; x++)
            {
                character = message[x];
    
                if (character >= 'a' && character <= 'z')
                {
                    character = character - shiftValue;
                    if (character < 'a')
                        character = character + 26; 
                    if (character > 'z')
                        character = character - 'z' + 'a' - 1;
                    message[x] = character;
                }
                else if (character >= 'A' && character <= 'Z')
                {
                    character = character - shiftValue;
                    if (character < 'A')
                        character = character + 26; 
                    if (character > 'Z')
                        character = character - 'Z' + 'A' - 1;
                    message[x] = character;
                }
            }
            std::cout << message;
            break;
    
        // Regular Decryption choice
        case 2:
            do
            {
                std::cout << "Enter shift value between 1 and 25: ";
                std::cin >> shiftValue;
            }
            while (shiftValue < 1 || shiftValue > 25);
        
            std::cout << "Enter a messsage to decode: ";
            std::cin.ignore();
            std::cin.getline(message, 120);
        
        
            for (x = 0; message[x] != '\0'; x++)
            {
                character = message[x];
        
                if (character >= 'a' && character <= 'z')
                {       
                    character = character + shiftValue;
        
                    if (character > 'z')
                        character = character - 26; 
                    if (character < 'a')
                        character = character + 'z' - 'a' + 1;
                    message[x] = character;
                }
                else if (character >= 'A' && character <= 'Z')
                {
                    character = character + shiftValue;

                    if (character > 'Z')
                        character = character - 26; 
                    if (character > 'a')
                        character = character + 'Z' - 'A' + 1;
                    message[x] = character;
                }
            }
            std::cout << message;
            break;
    
   

        // Improved Security Encryption choice 
        case 3:
            do
            {
                std::cout << "Enter shift value between 1 and 25: ";
                std::cin >> shiftValue;
            }
            while (shiftValue < 1 || shiftValue > 25);
       
        
            std::cout << "Enter a message to encode: " << std::endl;
            std::cin.ignore();
            std::cin.getline(message, 120);
        
    	
            for(x = 0; message[x] != '\0'; x++)
            {
                character = message[x];
        
                if (character >= 'a' && character <= 'z')
                {
                    character = character - shiftValue;
                    shiftValue = shiftValue % 25 + 10;
        
                    if (character < 'a')
                        character = character + 26; 
                    if (character > 'z')
                        character = character - 'z' + 'a' - 1;
                    message[x] = character;
                }
                else if (character >= 'A' && character <= 'Z')
                {
                    character = character - shiftValue;
                    shiftValue = shiftValue % 25 + 10;
            
                    if (character < 'A')
                        character = character + 26; 
                    if (character > 'Z')
                        character = character - 'Z' + 'A' - 1;
                    message[x] = character;
                }
            }
            std::cout << message;
            break;

        // Improved Security Decryption choice
        case 4:
            do
            {
                std::cout << "Enter shift value between 1 and 25: ";
                std::cin >> shiftValue;
            }
            while (shiftValue < 1 || shiftValue > 25);
        
            std::cout << "Enter a messsage to decode: " << std::endl;
            std::cin.ignore();
            std::cin.getline(message, 120);
        
            for (x = 0; message[x] != '\0'; x++)
            {
                character = message[x];
                if (character >= 'a' && character <= 'z')
                {
                    character = character + shiftValue;
                    shiftValue = shiftValue % 25 + 10;
                    if (character > 'z')
                        character = character - 26; 
                    if (character < 'a')
                        character = character + 'z' - 'a' + 1;
                    message[x] = character;
                }
                else if (character >= 'A' && character <= 'Z')
                {
                    character = character + shiftValue;
                    shiftValue = shiftValue % 25 + 10;
                    if (character > 'Z')
                        character = character - 26; 
                    if (character > 'a')
                        character = character + 'Z' - 'A' + 1;
                    message[x] = character;
                }
            }
            std::cout << message;
            break;

        default:
        std::cout << "Invalid option try again please" << std::endl;
    }
    return 0;
}





