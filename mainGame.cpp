// CSCI 1300 Fall 2020
// Author: Vanshita Gosain
// Recitation: 324
// Project 3

#include "GameDriver.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Character.h"
#include "Score.h"
#include <cstdlib>
#include <ctime>
#include "Date.h"

using namespace std;

int main() {
    // Using the functions from GameDriver.cpp this will run the game.
    cout << "BACK TO THE FUTURE!!!" << endl;
    GameDriver backToTheFuture;
    backToTheFuture.displayMainMenu();
    backToTheFuture.playGame();
    cout << "Have a nice day!" << endl;
    return 0;
}

// g++ -std=c++11 mainGame.cpp Character.cpp GameDriver.cpp Score.cpp Date.cpp