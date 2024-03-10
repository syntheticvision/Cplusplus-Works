/***********************************************************************
// OOP244 Workshop #03 p1
// Name: Babak Ghafourigivi
// Student ID: 165118233
// Student email: bghafourigivi@myseneca.ca
// Section: ZAA
// Date: 05 Feb 2024
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef _SENECA_CUSTOMER_H
#define _SENECA_CUSTOMER_H
#include "Car.h"

namespace seneca {
    class Customer
    {
        int m_id;
        char* m_name;
        const Car* m_car;

    public:
        bool isEmpty() const;
        void setEmpty();
        void deallocateMemory();
        void set(int customerId, const char* name, const Car* car);
        void display() const;
        const Car& car()const {
            return *m_car;
        }
    };

}
#endif
