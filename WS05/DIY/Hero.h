/***********************************************************************
// Name: Babak Ghafourigivi
// Student ID: 165118233
// Student email: bghafourigivi@myseneca.ca
// Section: ZAA
// Date: 22 Feb 2024
// I received help from a friend and also help from the internet.
***********************************************************************/

#ifndef SENECA_HERO_H
#define SENECA_HERO_H
#include <iostream>
#include "Power.h"

namespace seneca {
	class Hero {
		char heroName[MAX_NAME_LENGTH];
		Power* powerList;
		int numPowers;
		int powerLevel;
		void setEmpty();
	public:
		Hero();
		Hero(const char* name, Power* power, int numPower);
		std::ostream& display(std::ostream& ostr = std::cout) const;
		Hero& operator+=(Power&);
		Hero& operator-=(int);
		void deallocate();
		~Hero();
		int getPowerLevel() const;
	};
	bool operator<(Hero& hero1, Hero& hero2);
	bool operator>(Hero& hero1, Hero& hero2);
	void operator>>(Power&, Hero&);
	void operator<<(Hero&, Power&);
	std::ostream& operator<<(std::ostream& os, const Hero& hero);
}

#endif