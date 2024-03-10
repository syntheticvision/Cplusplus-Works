/***********************************************************************
// OOP244 Workshop #4 p1
//
// File	Fridge.cpp
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
#include <cstring>
#include <iostream>
#include <iomanip>
#include "Fridge.h"

using namespace std;

namespace seneca
{
   const char *Food::name() const
   {
      return m_name;
   }
   int Food::weight() const
   {
      return m_weight;
   }
   Food::Food() {}

   Food::Food(const char *nm, int wei)
   {
      strncpy(m_name, nm, NAME_LEN);
      m_weight = wei;
   }

   Fridge::Fridge()
   {
      m_numFoods = 0;
      m_model = nullptr;
   }
   Fridge::Fridge(Food far[], int nf, const char *mod) : Fridge()
   {
      if (nf > 0 && mod != nullptr && mod[0] != '\0')
      {
         m_numFoods = nf;
         m_model = new char[strlen(mod) + 1];
         strcpy(m_model, mod);

         for (int i = 0; i < nf && i < FRIDGE_CAP; i++)
         {
            m_foods[i] = far[i];
         }
      }
   }
   Fridge::~Fridge()
   {
      delete[] m_model;
      m_model = nullptr;
   }
   bool Fridge::addFood(const Food &f)
   {
      if (m_numFoods < FRIDGE_CAP)
      {
         m_foods[m_numFoods] = f;
         m_numFoods++;
         return true;
      }
      else
      {
         return false;
      }
   }
   void Fridge::changeModel(const char *m)
   {
      if (m != nullptr && m[0])
      {
         delete[] m_model;
         m_model = new char[strlen(m) + 1];
         strcpy(m_model, m);
      }
   }
   bool Fridge::fullFridge() const
   {
      if (m_numFoods == FRIDGE_CAP)
      {
         return true;
      }
      else
      {
         return false;
      }
   }

   bool Fridge::findFood(const char *f) const
   {
      bool result = false;

      for (int i = 0; i < m_numFoods; i++)
      {
         if (!strcmp(m_foods[i].name(), f))
         {
            result = true;
         }
      }
      return result;
   }

   std::ostream &Fridge::display(std::ostream &os) const

   {
      if (this->m_model != nullptr)
      {
         os << "Fridge Model: " << this->m_model << endl;

         os << "Food count: " << this->m_numFoods << " Capacity: " << FRIDGE_CAP << endl;

         os << "List of Foods" << endl;

         if (this->m_numFoods > 0)
         {
            for (int i = 0; i < this->m_numFoods; i++)
            {
               os << setw(NAME_LEN) << right << this->m_foods[i].name() << " | " << this->m_foods[i].weight() << endl;
            }
         }
      }
      return os;
   }
}
