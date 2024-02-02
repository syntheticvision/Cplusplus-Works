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
#include <cstdio>
#include <cstring>
#include "Guest.h"

using namespace std;
namespace seneca
{
    // sets the Guest variables and sets the m_adult flag to true if the age is greater than or equal to 18
    void set(Guest& guest, const char* first, const char* last, int age) {
       
      if(first && last && strcmp(first, "") != 0 && strcmp(last, "") != 0)
      {
          guest.m_firstName = new char[strlen(first) + 1];
          guest.m_lastName = new char[strlen(last) + 1];
          strcpy(guest.m_firstName, first);
          strcpy(guest.m_lastName, last);
          if (age >= 18)
          {
              guest.m_adult = true;


          }
          else
          {
              guest.m_adult = false;

          }  
      }
      else
      {
          guest.m_firstName = nullptr;
          guest.m_lastName = nullptr;
      
      }
 

    }

    // Prints the guest name:
    // "Name Surname(child)"
    // The child flag is printed if the guest is not an adult
    // and if the names are not set, "Vacated!" is printed.
    void print(const Guest& guest){

        if (guest.m_firstName && guest.m_lastName) {

            if(!guest.m_adult)
            {
                cout << guest.m_firstName << " " << guest.m_lastName << "(Child)" << endl;
            
            }
            else
            {
                cout << guest.m_firstName << " " << guest.m_lastName << endl;
            }

        }
        else
        {
            cout << "Vacated!" << endl;
        
        }
        
        
    
    }

    // books the guest information from the console:
    // Name: Jake<ENTER>
    // Last name: Doe<ENTER>
    // Age: 10<ENTER>
    void book(Guest& guest) {
        int age;
        char name[200], family[200];

        cout << "Name: ";
        cin >> name;
        cout << "Lastname: ";
        cin >> family;
        cout << "Age: ";
        cin >> age;
        set(guest, name, family, age);


    }

    // vacates the guest by deallocating its memory.
    void vacate(Guest& guest) {

        delete[] guest.m_firstName;
        guest.m_firstName = nullptr;
        delete[] guest.m_lastName;
        guest.m_lastName = nullptr;
    }

}