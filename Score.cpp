// CSCI 1300 Fall 2020
// Author: Vanshita Gosain
// Recitation: 324
// Project 3

#include "Score.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Score::Score() {
    Right = 0;
    Middle = 0;
    Wrong = 0;
    Total = 0;
}
Score::Score(int right, int middle, int wrong, int total=0) {
    Right = right;
    Middle = middle;
    Wrong = wrong;
    Total = total;
}
int Score::getRight() {
    return Right;
}
void Score::setRight(int right) {
    Right = right;
}
int Score::getMiddle() {
    return Middle;
}
void Score::setMiddle(int middle) {
    Middle = middle;
}
int Score::getWrong() {
    return Wrong;
}
void Score::setWrong(int wrong) {
    Wrong = wrong;
}
int Score::getTotal() {
    return Total;
}
void Score::setTotal(int total) {
    Total = total;
}
void Score::addRightPoints(){
    Total += Right + 5;
}
void Score::addMiddlePoints(){
    Total += Middle + 3;
}
void Score::addWrongPoints(){
    Total += Wrong - 3;
}
void Score::displayResults(string name)  {
    ofstream outFile;
    outFile.open("results.txt");
    cin >> name;
    if (outFile.fail()) {
        cout << "File failed to open." << endl;
    }
    else {
        outFile << name << " your final score is: " << getTotal() << endl;
        if (Total <= 10) {
            outFile << "Dear " << name << "unfortunately you changed many events as you visited the past. You have disrupted your timeline and created an alternate one where you parents are not married, and thus erased yourself out of existence." << endl;
        }
        else {
            outFile << "Wow " << name << " that was a wild ride! But you nailed it. You have successfuly gotten back to the future. As you come back home you see your mother and father happily married, their lifestyle even better than before." << endl;
        }
    }
    ifstream inFile;
    inFile.open("results.txt");
    string line;
    if (inFile.fail()) {
        cout << "File failed to open." << endl;
    }
    else {
        while(getline(inFile, line)) {
            cout << line << endl;
        }
    }
    inFile.close();
}



