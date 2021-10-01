// CSCI 1300 Fall 2020
// Author: Vanshita Gosain
// Recitation: 324
// Project 3

#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <vector>
using namespace std;

// Purpose of this class is to work with Menu item 2 and work with CharDriver class to populate the vector name.
// This will print out information when a user wants to know about the characters.
class Character
{
    public:
        // Default constructor
        Character();
        // Parameterized Constructor
        Character (string name, string background);
        string getcharName(); // Getter
        string getcharBackground() const; // Getter
        void setcharName(string name); // Setter
        void setcharBackground(string background); // Setter
        void displayCharacterStory(); // displays character details


    private:
        string charName;
        string charBackground;

};


#endif

