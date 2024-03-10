/***********************************************************************
// OOP244 Workshop #03 p2
// Name: Babak Ghafourigivi
// Student ID: 165118233
// Student email: bghafourigivi@myseneca.ca
// Section: ZAA
// Date: 08 Feb 2024
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#ifndef VENDOR_H
#define VENDOR_H

#include "Icecream.h"

namespace seneca {

	class Vendor {
	private:
		static const int MAX_ORDERS = 10;
		Icecream* m_orders[MAX_ORDERS];
		int m_numOrders;

	public:
		void setEmpty();
		void takeOrders();
		void displayOrders();
		void clearData();

	};
}

#endif