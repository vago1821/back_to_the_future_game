// CSCI 1300 Fall 2020
// Author: Vanshita Gosain
// Recitation: 324
// Project 3

#include <iostream>
#include "Character.h"
#include <string>

using namespace std;

Character::Character() // Constructor
{
    charName = {};
    charBackground = "";
} 
Character::Character(string name, string background) // Parameterized constructor
{
    charName = name;
    charBackground = background;
}
string Character::getcharName()
{
    return charName;
}
string Character::getcharBackground() const
{
    return charBackground;
}
void Character::setcharName(string name)
{
    charName = name;
}
void Character::setcharBackground(string background)
{
    charBackground = background;
}
void Character::displayCharacterStory() // In GameDriver.cpp this function when called upon prints out the desired character's name and background.
{
    cout << charName << " Background: " << charBackground;
}
