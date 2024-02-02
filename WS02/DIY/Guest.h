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

#ifndef _SENECA_GUEST_H
#define _SENECA_GUEST_H

namespace seneca {

    struct Guest {
        char* m_firstName;
        char* m_lastName;
        bool m_adult;
    };


    // sets the Guest variables and sets the m_adult flag to true if the age is greater than or equal to 18
    void set(Guest& guest, const char* first, const char* last, int age);

    // Prints the guest name:
    // "Name Surname(child)"
    // The child flag is printed if the guest is not an adult
    // and if the names are not set, "Vacated!" is printed.
    void print(const Guest& guest);

    // books the guest information from the console:
    // Name: Jake<ENTER>
    // Last name: Doe<ENTER>
    // Age: 10<ENTER>
    void book(Guest& guest);

    // vacates the guest by deallocating its memory.
    void vacate(Guest& guest);

}
#endif




