/***********************************************************************
// OOP244 Workshop #03 p2
// Name: Babak Ghafourigivi
// Student ID: 165118233
// Student email: bghafourigivi@myseneca.ca
// Section: ZAA
// Date: 08 Feb 2024
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#ifndef ICECREAM_H
#define ICECREAM_H

#include <string>

namespace seneca {

	class Icecream {
	private:
		int flavour;
		int n_scoops;
		bool wantsVanillaWafer = false;
		double priceScoop = 5.0;
		double priceChocolate = 1.0;
		double priceVanillaWafer = 5.0;
		double totalPrice;

	public:
		void displayMenu() const;
		void getFlavour();
		void getNumScoops();
		void getOrder();
		double printOrder();

	};
}

#endif
