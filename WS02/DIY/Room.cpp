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
#include "Room.h"
#include "Guest.h"

using namespace std;
namespace seneca
{
    // sets the Room by allocating a dynamic array of guests and setting the room number 
    // (no validation is done for room number)
    void set(Room& room, int numberOfGuests, const char* roomNumber) {
      
            room.m_guests = new Guest[numberOfGuests];
            room.m_noOfGuests = numberOfGuests;
            strcpy(room.m_roomNumber, roomNumber); 
            for (int i = 0; i < numberOfGuests; i++) {
                room.m_guests[i].m_firstName = nullptr;
                room.m_guests[i].m_lastName = nullptr;
                room.m_guests[i].m_adult = false;
            }  


         
    }

    // Prints the room number and names of the guests in the following lines with four 
    // spaces of indentation 
    // See correct_output.txt for the exact format
    void print(const Room& room) {

        if (room.m_guests == 0)
        {
            cout << "Empty Room!" << endl;
        }
        else{
            cout << "Room Number: " << room.m_roomNumber << endl;
        
            for(int i = 0; i < room.m_noOfGuests; ++i)
            {
                if(room.m_guests[i].m_firstName && room.m_guests[i].m_lastName)
                {
                    if(!room.m_guests[i].m_adult)
                    {
                        cout << "    " << room.m_guests[i].m_firstName << " "
                            << room.m_guests[i].m_lastName << "(Child)" << endl;
                    
                    }
                    else
                    {
                        cout << "    " << room.m_guests[i].m_firstName << " "
                            << room.m_guests[i].m_lastName << endl;
                    }
                
                
                
                
                }
                else
                {
                    cout << "    " << "Vacated!" << endl;
                
                
                }
            
            
            }

        
        }


      
    }

    // Books a room by receiving the room number, number of guests and the guest information.
    // See correct_output.txt for the exact format
    void book(Room& room) {
        int guest;
        char tmpRoomNum[6];
        cout << "Room number: ";
        cin >> tmpRoomNum;
        cout << "Number of guests: ";
        cin >> guest;
        set(room, guest, tmpRoomNum);
        for (int i = 0; i < guest; i++)

        {

                cout << i + 1 << ":" << endl;
                book(room.m_guests[i]);

        }
        
  
    }

    // vacates the room by deallocating all the memory used.
    void vacate(Room& room) {
        for(int i = 0; i < room.m_noOfGuests; i++)
        {
            vacate(room.m_guests[i]);
        }

        delete[] room.m_guests;
        room.m_guests = nullptr;

    }

 

}