/***********************************************************************
// OOP244 Workshop #4 p2
//
// File	Fridge.h
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: Babak Ghafourigivi
// Student ID: 165118233
// Student email: bghafourigivi@myseneca.ca
// Section: ZAA
// Date: 11 Feb 2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#ifndef SENECA_FRIDGE_H

#define SENECA_FRIDGE_H

#include <cstring>
#include <iostream>

namespace seneca 
{
    const int NAME_LEN = 20;
    const int FRIDGE_CAP = 3;
    class Food 
    {
        char m_name[NAME_LEN]{};
        int m_weight{};

    public:
        const char* name()const;
        int weight()const;
        Food();
        Food(const char* nm, int wei);
    };
    class Fridge 
    {
    private:
        Food m_foods[FRIDGE_CAP]; 
        int m_numFoods;   
        char* m_model;  

    public:
        Fridge(); 
        Fridge(Food far[], int nf, const char* mod = "Ice Age");  
        ~Fridge();
        //Modifiers
        bool addFood(const Food& f);
        void changeModel(const char* m);
        //Queries
        bool fullFridge() const;
           bool findFood(const char* f) const;

        std::ostream& display(std::ostream& os = std::cout) const;
    };
}

#endif
