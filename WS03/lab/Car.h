/***********************************************************************
// OOP244 Workshop #03 p1
// Name: Babak Ghafourigivi
// Student ID: 165118233
// Student email: bghafourigivi@myseneca.ca
// Section: ZAA
// Date: 05 Feb 2024
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef _SENECA_CAR_H
#define _SENECA_CAR_H

namespace seneca {
    class Car
    {
        char m_licencePlate[8];
        char* m_makeModel;
        char* m_serviceDesc;
        double m_cost;

    public:
        bool isEmpty() const;
        void setEmpty();
        void deallocateMemory();
        void set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost);
        void display() const;

    };
}
#endif
