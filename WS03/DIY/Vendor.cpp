/***********************************************************************
// OOP244 Workshop #03 p2
// Name: Babak Ghafourigivi
// Student ID: 165118233
// Student email: bghafourigivi@myseneca.ca
// Section: ZAA
// Date: 08 Feb 2024
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Vendor.h"

using namespace std;
namespace seneca {

	void Vendor::setEmpty() {
		m_numOrders = 0;

		for (int i = 0; i < MAX_ORDERS; ++i) {
			m_orders[i] = nullptr;
		}
	}

	void Vendor::takeOrders() {

		cout << "Seneca Icecream shop\n";
		cout << "          @\n";
		cout << "        (' .)\n";
		cout << "       (*.`. )\n";
		cout << "        \\###/\n";
		cout << "         \\#/\n";
		cout << "          V\n";

		cout << "How many Icecreams?\n> ";
		cin >> m_numOrders;

		for (int i = 0; i < m_numOrders; i++) {
			cout << "Order number " << i + 1 << ":\n";
			m_orders[i] = new Icecream();
			m_orders[i]->getOrder();
		}
	}
	void Vendor::displayOrders() {
		double totalOrderPrice = 0.0;

		cout << "\n********** Order Summary **********";

		for (int i = 0; i < m_numOrders; i++) {
			cout << endl;
			cout << "Order No: " << i + 1 << ":" << endl;
			cout << "Order details:                Price\n";
			cout << "-----------------------------------\n";
			totalOrderPrice += m_orders[i]->printOrder();
		}

		cout << "-----------------------------------\n";
		cout.setf(ios::left);
		cout.width(24);
		cout << fixed << setprecision(2) << "Price:";
		cout.unsetf(ios::left);

		cout.setf(ios::right);
		cout.width(11);
		cout << totalOrderPrice << endl;
		cout.unsetf(ios::right);

		double tax = totalOrderPrice * 0.13;

		cout.setf(ios::left);
		cout.width(24);
		cout << "Tax:";
		cout.unsetf(ios::left);

		cout.setf(ios::right);
		cout.width(11);
		cout << tax << endl;
		cout.unsetf(ios::right);

		cout.setf(ios::left);
		cout.width(24);
		cout << "Total Price ($):";
		cout.unsetf(ios::left);

		cout.setf(ios::right);
		cout.width(11);
		cout << totalOrderPrice + tax << endl;
		cout.unsetf(ios::right);

		clearData();
	}

	void Vendor::clearData() {
		for (int i = 0; i < m_numOrders; ++i) {
			delete m_orders[i];
		}
		setEmpty();
	}

}