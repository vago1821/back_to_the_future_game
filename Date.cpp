// CSCI 1300 Fall 2020
// Author:  Jasmin Godinez
// Recitation: 324
// Project 3
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Date.h"
 
using namespace std;
 
Date::Date(int Month, int Day, int Year)//main declaration for all varibles
//we declared it to the new varibles so it can call from the date.h file
{
    month = Month;
    day = Day;
    year = Year;
}
int Date::setDay(){//used the random function 
    day=rand() %30+1;//since most days in the month are around 30 days
    return day;
}
int Date::setMonth(){
    srand((unsigned)time(0));
    month=rand() %12+1;//there are only 12 months in a year
    return month;
}
int Date::setYear(){
    srand((unsigned)time(0));
    year=1960+rand() %20+1;//the year can be adjustable but because we have only been up to the year 2020 we limit it from 1960-2020
    return year;
 
}
 
void Date::printDATE(int MONTH, int DAY, int YEAR){
    cout << "You landed in " << MONTH << "/" << DAY << "/" << YEAR << endl;//prints out the date
}

