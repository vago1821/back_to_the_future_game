#ifndef GAMEDRIVER_H
#define GAMEDRIVER_H
#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
 
using namespace std;
 
class GameDriver {
    public:
        // Default Constructor
        GameDriver();
        // Parameterized Constructor
        GameDriver(vector<Character> charNames);
        void populateCharacters();
        void printCharacterMenu();
        void displayMainMenu() const;
        void displayCharacterDetails(int i);
        void playGame();
 
    private:
        vector<Character> charNames;   
};
 
#endif
