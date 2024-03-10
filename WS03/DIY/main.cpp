/***********************************************************************
// OOP244 Workshop #03 p2: tester program 
//
// File	main.cpp
// Version 1.0
// Date: September 28, 2023
// Author: Yosef Ashibani
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: Babak Ghafourigivi
// Student ID: 165118233
// Student email: bghafourigivi@myseneca.ca
// Section: ZAA
// Date: 08 Feb 2024
// I received some help for this workshop from a friend of mine. Some parts of the codes I couldn't figure out 
// exactly how to write them and were tricky.
***********************************************************************/

#include "Vendor.h"
#include "Icecream.h"
#include "Vendor.cpp"
#include "Icecream.cpp"

using namespace seneca;
int main() {
    Vendor vendor;
    vendor.setEmpty();
    vendor.takeOrders();
    vendor.displayOrders();
    vendor.clearData();
    return 0;
}
