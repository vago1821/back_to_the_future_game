// CSCI 1300 Fall 2020
// Author: Jasmin Godinez
// Recitation: 324
// Project 3
 
#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
 
class Date
{
private://defining my variables in the private 
    int day;//random day choosen
    int month;//random month choosen
    int year;//random year choosen
public:
    //The main consturctors
    //default
    Date(){
        srand(time(NULL));//since we are printing random dates then we can use this fucntion to do so
    }
    Date(int, int, int);//all variables will be integers
 
    int setDay();///setting all of the variables
    int setMonth();//setter
    int setYear();//setter
    void printDATE(int, int, int);//prints variables at the end
 
};
 
#endif
