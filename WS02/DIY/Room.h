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

#ifndef _SENECA_ROOM_H
#define _SENECA_ROOM_H
#include "Guest.h"

namespace seneca {

    struct Room {
        char m_roomNumber[6];
        int m_noOfGuests;
        Guest* m_guests;
    };


    // sets the Room by allocating a dynamic array of guests and setting the room number 
    // (no validation is done for room number)
    void set(Room& room, int numberOfGuests, const char* roomNumber);

    // Prints the room number and names of the guests in the following lines with four 
    // spaces of indentation 
    // See correct_output.txt for the exact format
    void print(const Room& room);

    // Books a room by receiving the room number, number of guests and the guest information.
    // See correct_output.txt for the exact format
    void book(Room& room);

    // vacates the room by deallocating all the memory used.
    void vacate(Room& room);


}
#endif




