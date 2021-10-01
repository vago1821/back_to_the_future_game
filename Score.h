// CSCI 1300 Fall 2020
// Author: Vanshita Gosain
// Recitation: 324
// Project 3

#ifndef SCORE_H
#define SCORE_H
#include <string>
using namespace std;

// Purpose of this class is to keep track of the score throught the game.
// Based on the choices that character makes right choice earn more points, somewhat correct earn few, and wrong lose points.

class Score
{
    public:
        // Default
        Score();
        // Parameterized Constructor
        Score(int right, int middle, int wrong, int total);
        int getRight();       // Getter
        int getMiddle();      // Getter
        int getWrong();       // Getter
        int getTotal();       // Getter
        void setRight(int right);    // Setter
        void setMiddle(int middle);  // Setter
        void setWrong(int wrong);    // Setter
        void setTotal(int total);    // Setter

        void addRightPoints(); // adds the Right variable points (5) to total
        void addMiddlePoints(); // adds fewer Middle variable points (3) to total
        void addWrongPoints(); // subtracts the Wrong variable points (-3) to total
        void displayResults(string name); // writes to a text file which prints out the game results.

    private:
        int Right; // the number of points you get for getting a right choice
        int Middle; // the points you get for making the middle choice
        int Wrong;  // the points you get for making the wrong choice
        int Total;  // a running total of all the points you scored in the whole game
};

#endif




