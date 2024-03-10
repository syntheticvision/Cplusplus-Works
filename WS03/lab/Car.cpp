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
#include <iomanip>
#include <cstdio>
#include <cstring>
#include "Car.h"


using namespace std;
namespace seneca {

    bool Car::isEmpty() const {
        if (m_makeModel == nullptr || m_serviceDesc == nullptr || m_makeModel[0] == '\0'
            || m_serviceDesc[0] == '\0')
        {
            return true;
        }
        return false;
    }

    void Car::setEmpty()
    {
        m_licencePlate[0] = '\0';
        m_makeModel = nullptr;
        m_cost = 0.0;
        m_serviceDesc = nullptr;
    }

    void Car::deallocateMemory() {
        delete[] m_makeModel;
        delete[] m_serviceDesc;
        m_makeModel = nullptr;
        m_serviceDesc = nullptr;
    }

    void Car::set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost) {
        deallocateMemory();
        if (serviceDesc != nullptr && carMakeModel != nullptr && strcmp(serviceDesc, "") != 0
            && strcmp(carMakeModel, "") != 0 && plateNo[0] != '\0') {
            m_makeModel = new char[strlen(carMakeModel) + 1];
            m_serviceDesc = new char[strlen(serviceDesc) + 1];
            strcpy(m_makeModel, carMakeModel);
            strcpy(m_serviceDesc, serviceDesc);
            strcpy(m_licencePlate, plateNo);
            m_cost = serviceCost;
        }
    }

    void Car ::display() const {
        if (m_licencePlate[0] != '\0' || m_makeModel != nullptr || m_serviceDesc != nullptr)
        {
            cout << left << setw(15) << "License Plate:" << right << setw(20) << m_licencePlate << endl;
            cout << left << setw(15) << "Model:" << right << setw(20) << m_makeModel << endl;
            cout << left << setw(15) << "Service Name:" << right << setw(20) << m_serviceDesc << endl;
            cout << left << setw(15) << "Service Cost:" << right << setw(20) << fixed << setprecision(2) << m_cost << endl;
        }
        else {
            return;
        }
    }
}