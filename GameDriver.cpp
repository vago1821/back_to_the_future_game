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

GameDriver::GameDriver() {
    vector<Character> charNames = {};
}
GameDriver::GameDriver(vector<Character> charNames) {
    charNames = charNames;
}

// uses the Character class inside the GameDriver class .The fuction populateCharacters() uses the Character to create an object of characters. Appends this information about these characters into the vector string parameters. 
void GameDriver::populateCharacters() {
    Character marty = Character("Marty", "is your ordinary teenage boy who is the son of George McFly and Lorraine Baines. He was born in Hill Valley and he is close friends with Dr.Emmett Brown, also called Doc.");
    Character george = Character("George", "father of Marty McFly. Bullied by Biff up until adulthood until Marty encourages him to stand up for himself. Which leads him to win over his future wife Lorraine and became successful.");
    Character docBrown = Character("Dr. Brown", "is known to be a crazy scientist around his neighborhood. Though his work is regarded with admiration by many others, he also has gotten himself trouble with the Libyans.");
    Character biff = Character("Biff", "always bullies others to get what he wants. In the original timeline he bullied George but that wasn't until Marty had gone back into the future and altered the outcome.");

    charNames.push_back(marty);
    charNames.push_back(george);
    charNames.push_back(docBrown);
    charNames.push_back(biff);
}

// When selected option 2 in the main menu this will print out a menu of characters, user can select which one they want to know about.
void GameDriver::printCharacterMenu() {
    cout << "Select a character you want to learn about: " << endl;
    for (int i = 0; i < charNames.size(); i++) {
        cout << i << ": " << charNames[i].getcharName();
        cout << endl;
    }
}

// After the user has chosen a character this will print out the information we used the Character class to enter above. It will print name of character and a little bit about them.
void GameDriver::displayCharacterDetails(int i) {
    if (i < charNames.size()){
        charNames[i].displayCharacterStory();
        cout << endl;
    }
}

// To display the Main Menu of the game.
void GameDriver::displayMainMenu() const {
    cout << "----Menu----" << endl;
    cout << "1. Game survival guide." << endl;
    cout << "2. Learn about the characters" << endl;
    cout << "3. Start the game" << endl;
    cout << "4. Where will you time travel to?" << endl;
    cout << "5. Quit" << endl;
}

// This is the whole game. It is all stored in this function.
// It has a loop which presents the Main Menu until user exits and switch cases to perform different options in the game.
void GameDriver::playGame() {
    int option = 0;
    ifstream inFile;
    string line;
    int miniMenuChoice = 0;
    int i;
    populateCharacters();
    Score myScore = Score(0, 0, 0, 0);
    Date date;
    int m = 0;
    int d = 0;
    int y = 0;
    m = date.setMonth();
    d = date.setDay();
    y = date.setYear();
    string name;
    while (option != 5) {
        cin >> option;
    switch(option) {
        case 1:
            // Infile Stream
            inFile.open("gameRules.txt");
            if (inFile.fail()) {
                cout << "File failed to open.";
            }
            else {
                while(getline(inFile, line)) {
                        cout << line << endl;
                }
            }
            cout << endl;
            inFile.close();
        break;
        case 2:
                printCharacterMenu();
                cin >> i;
                if (i <= 3) {
                    displayCharacterDetails(i);
                    cout << endl;
                }
                else {
                    cout << "Not an option." << endl;
                    cout << endl;
                }
        break;
        case 3:
            cout << "You wake up to what looks like an early version of Hill Valley and realize you are in 1955. You head to Lou’s Cafe/Diner to figure out your next course of action." << endl;
            cout << "The owner looks at you funny and asks what do you want to buy?" << endl;
            cout << "Cafe Menu" << endl;
            while(miniMenuChoice <= 0 || miniMenuChoice > 3)
            {
                cout << "1. Order a Pepsi" << endl;
                cout << "2. Get a coffee" << endl;
                cout << "3. Use the phone to find Doc's number" << endl;
                cin >> miniMenuChoice;
                // SCENE 1
                if (miniMenuChoice == 1) {
                    cout << "Owner looks at you and asks, \"What's a Pepsi?\"" << endl;
                    cout << endl;
                    myScore.addWrongPoints();
                } else if (miniMenuChoice == 2) {
                    myScore.addMiddlePoints();
                } else if (miniMenuChoice == 3) {
                    cout << "You go use the phone and search for Dr.Brown’s phone number. You give him a call but he doesn’t answer so you rip off the phone book page, realizing that it has his address: 1640 Riverside Drive, Hill Valley" << endl;
                    cout << endl;
                    myScore.addRightPoints();
                } else {
                    cout << "Not an option, try again." << endl;
                    cout << endl;
                }
            }
            // SCENE 2
            miniMenuChoice = 0;
            cout << "As you are about to leave to find Dr.Brown, a big guy and his gang show up, who looks a lot like Biff only younger. He and his friends start to bully a guy next to you. To your surprise it is George McFly, your father who is your age right now. Biff continues and George looks helpless. What will you do?" << endl;
            while (miniMenuChoice <= 0 || miniMenuChoice > 3)
            {
                cout << "1. Stand up and fight Biff" << endl;
                cout << "2. Encourage George to stand up to Biff" << endl;
                cout << "3. Avoid the confrontation and focus on getting to Doc" << endl;
                cin >> miniMenuChoice;
                if (miniMenuChoice == 1) {
                    cout << "Unfortunately you have made an unnecessary enemy and endangered your existence. Hurry and head to Doc Brown." << endl;
                    cout << endl;
                    myScore.addWrongPoints();
                } else if (miniMenuChoice == 2) {
                    cout << "Involvement with George and Biff didn't do much. You continue to try and find Doc." << endl;
                    cout << endl;
                    myScore.addMiddlePoints();
                } else if (miniMenuChoice == 3) {
                    cout << "Great choice! Involvement in the past can be risky." << endl;
                    cout << endl;
                    myScore.addRightPoints();
                } else {
                    cout << "Not an option, try again." << endl;
                    cout << endl;
                }
            }
            // SCENE 3
            miniMenuChoice = 0;
            cout << "You see your young father George peeping through a girl's window from a tree. He suddenly falls off the tree, but thankfully lands on his feet. But suddenly a car comes his way. What will you do?" << endl;
            while(miniMenuChoice <= 0 || miniMenuChoice > 2)
            {
                cout << "1. Hide behind the tree and let your father get hit." << endl;
                cout << "2. Try to save him but get slightly injured in the process." << endl;
                cin >> miniMenuChoice;
                if (miniMenuChoice == 1) {
                    cout << "Thankfully the car wasn't going too fast. George is a little hurt, but the man who hit him is your mother, Lorraine's father. This is actually how your parents first met. You have saved history from altering! Afterwards you continue to go to Doc Brown's house so you can get back to the future." << endl;
                    cout << endl;
                    myScore.addRightPoints();
                } else if (miniMenuChoice == 2) {
                    cout << "You find yourself in someone's house. The man who hit you took you to his house to take care of you. The man is actually your mother, Lorraine's father. Your mother tries to flirt with you however you remember you need to find Doc Brown so that you can get back to the future. You leave in the middle of dinner and go to his house." << endl;
                    cout << endl;
                    myScore.addMiddlePoints();
                } else {
                    cout << "Not an option, try again." << endl;
                    cout << endl;
                }
            }
            // SCENE 4
            miniMenuChoice = 0;
            cout << "To further prevent your presence from affecting the current time, Doc suggests you do something to try to fit in the decade more. What do you do?" << endl;
            while(miniMenuChoice <= 0 || miniMenuChoice > 3)
            {
                cout << "1. Buy some food and talk to a few people." << endl;
                cout << "2. Buy new clothes from the 50s and interact with only the salesperson." << endl;
                cout << "3. Keep wearing the same clothes." << endl;
                cin >> miniMenuChoice;
                if (miniMenuChoice == 1) {
                    myScore.addWrongPoints();
                } else if (miniMenuChoice == 2) {
                    myScore.addRightPoints();
                } else if (miniMenuChoice == 3) {
                    myScore.addMiddlePoints();
                } else {
                    cout << "Not an option, try again." << endl;
                    cout << endl;
                }
            }
            // SCENE 5
            miniMenuChoice = 0;
            cout << "You are at school with George when you see Biff bothering Lorraine. This makes you mad because, though she doesn’t know it yet, she is your mother. Biff starts to bother her more, you want to help her but also remember what Doc Brown said about avoiding interactions as much as possible." << endl;
            while(miniMenuChoice <= 0 || miniMenuChoice > 3)
            {
                cout << "1. Encourage George to fight Biff" << endl;
                cout << "2. Go up to Biff and punch his face" << endl;
                cout << "3. Stand there and watch" << endl;
                cin >> miniMenuChoice;
                if (miniMenuChoice == 1) {
                    myScore.addRightPoints();
                } else if (miniMenuChoice == 2) {
                    myScore.addWrongPoints();
                } else if (miniMenuChoice == 3) {
                    myScore.addMiddlePoints();
                } else {
                    cout << "Not an option, try again." << endl;
                    cout << endl;
                }
            }
            // SCENE 6
            miniMenuChoice = 0;
            cout << "Without any success in trying to make your young parents fall in love again. It’s time for the \"Enchantment Under The Sea\" school dance, and your mother Lorraine, who is currently infatuated with you wants you to take her. Doc has instructed you to get your parents together before you leave. Also, you really don’t want to take your mom on a date, but it doesn't seem like George has a chance." << endl;
            while(miniMenuChoice <= 0 || miniMenuChoice > 3)
            {
                cout << "1. Try to force George and Lorraine together knowing it’ll most likely fail." << endl;
                cout << "2. Go to the dance with Lorraine and try to get her and George together once you're there." << endl;
                cout << "3. Don’t go to the dance and hope your parents will figure it out." << endl;
                cin >> miniMenuChoice;
                if (miniMenuChoice == 1) {
                    myScore.addWrongPoints();
                } else if (miniMenuChoice == 2) {
                    myScore.addRightPoints();
                } else if (miniMenuChoice == 3) {
                    myScore.addMiddlePoints();
                } else {
                    cout << "Not an option, try again." << endl;
                    cout << endl;
                }
            }
            // SCENE 7
            miniMenuChoice = 0;
            cout << "You ended up driving Lorraine to the dance, but you leave to go find George so that he can make his move. When you come back after explaining to George the plan to win Lorraine, you see Biff has entered the car and Lorraine is struggling to escape from his grasp. Lorraine yells for help. You can save her but may alter history. George might be able to save her, but will try if you convince him. What will you do?" << endl;
            while(miniMenuChoice <= 0 || miniMenuChoice > 2)
            {
                cout << "1. FIGHT HIM, nobody lays hands on your mother!" << endl;
                cout << "2. Convince George to save her instead! This is his chance to win her over!" << endl;
                cin >> miniMenuChoice;
                if (miniMenuChoice == 1) {
                    myScore.addWrongPoints();
                } else if (miniMenuChoice == 2) {
                    myScore.addRightPoints();
                } else {
                    cout << "Not an option, try again." << endl;
                    cout << endl;
                }
            }
                cout << "Enter your name: ";
                myScore.displayResults(name);
        break;
        case 4:
            date.printDATE(m,d,y);
            cout << endl;
        break;
        default:
            if(option != 5) {
                cout << "Invalid option. Please try again." << endl;
                cout << endl;
            }
        break;
        }
        if (option != 5) {
            displayMainMenu();
        }
    }
}

 