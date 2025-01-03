/***********************************************************************
Workshop 1: Compiling modular source code
File	w1p2.cpp
Version 1.0
Author	Fardad Soleimanloo  2241
Description:
   This provides some source code in a single file to break
   into modules and compile together

Revision History
-----------------------------------------------------------
Name: Babak Ghafourigivi
Student ID: 165118233
Student email: bghafourigivi@myseneca.ca
Date: 14 Jan 2023
***********************************************************************/

#ifndef SENECA_IO_H
#define SENECA_IO_H
namespace seneca
{
    // prints the int value in width of fieldWidth
    void printInt(int value, int fieldWidth);
    // erturns number of digits in an integer
    int intDigits(int value);
    // if the user enters non digit values, the function will hang in an endless loop.
    int getInt(int min, int max);
    // moves the cursor backwards
    void goBack(int n);
    // displays the user interface menu
    int menu(int noOfSamples);
    // Draws a line and adds a label
    void labelLine(int n, const char *label);
    // Draws a line
    void line(int n);
}
#endif