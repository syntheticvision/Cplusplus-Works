/***********************************************************************
// OOP244 Workshop #03 p1
// Name: Babak Ghafourigivi
// Student ID: 165118233
// Student email: bghafourigivi@myseneca.ca
// Section: ZAA
// Date: 05 Feb 2024
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include "Customer.h"
#include "Car.h"


using namespace std;
namespace seneca {

    bool Customer::isEmpty() const {
        if (m_name == nullptr || strcmp(m_name, "") == 0 || m_car == nullptr) {
            return true;
        }
        return false;
    }

    void Customer::setEmpty() {
        m_id = 0;
        m_name = nullptr;
        m_car = nullptr;
    }
    void Customer::deallocateMemory() {
        delete[] m_name;
        m_name = nullptr;
        m_car = nullptr;
    }

    void Customer::set(int customerId, const char* name, const Car* car) 
    {
        deallocateMemory();
        if (name != nullptr &&  strcmp(name, "") != 0 && car != nullptr) {
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
            m_car = car;
            m_id = customerId;
        }
    }
    void Customer:: display() const
    {
        cout << left << setw(15) << "Customer ID:" << right << setw(20) << m_id << endl;
        cout << left << setw(15) << "First Name:" << right << setw(20) << m_name << endl;
        m_car->display();
    }
}