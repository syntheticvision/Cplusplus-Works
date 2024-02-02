/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File	main.cpp
// Version 1.0
//
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: Babak Ghafourigivi
// Student ID: 165118233
// Student email: bghafourigivi@myseneca.ca
// Section: ZAA
// Date: 01 Feb 2024
// some parts of the codes are done with the help of Siavash Amerigolestan 133733220, 
// and another friend of mine and also some internet research
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Room.h"
#include "Room.cpp"
#include "Guest.h"
#include "Guest.cpp"
using namespace std;
using namespace seneca;


int main() {
    cout << "Testing Guest Functions:" << endl;
    Guest G;
    cout << "\nTesting bad setting\n---------------" << endl;
    set(G, nullptr, "ABC", 10);
    print(G);
    set(G, "ABC", nullptr, 10);
    print(G);
    set(G, "", "ABC", 10);
    print(G);
    set(G, "ABC", "", 10);
    print(G);
    cout << "\nTesting Good setting\n---------------" << endl;
    set(G, "Jane", "Doe", 30);
    print(G);
    vacate(G);
    print(G);
    cout << "------------------------" << endl
        << "\nTesting Guest booking:\n--- Enter the following:" << endl
        << "Jake\nDoe\n10" << endl
        << "------------------------" << endl;
    book(G);
    print(G);
    vacate(G);
    print(G);
    cout << "\nTesting Room Functions: " << endl;
    Room A;
    set(A, 2, "A1010");
    print(A);
    vacate(A);
    print(A);
    cout << "------------------------" << endl
        << "Testing Room booking:\n--- Enter the following:" << endl
        << "A1010\n2\nJane\nDoe\n30\nJake\nDoe\n10" << endl
        << "------------------------" << endl;
    book(A);
    cout << "\nRoom booking data:" << endl
        << "------------------------" << endl;
    print(A);
    cout << "\nPrinting vacated Room:" << endl
        << "------------------------" << endl;
    vacate(A);
    print(A);
    return 0;
}


