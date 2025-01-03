/***********************************************************************
// Name: Babak Ghafourigivi
// Student ID: 165118233
// Student email: bghafourigivi@myseneca.ca
// Section: ZAA
// Date: 22 Feb 2024
// I received help from a friend and also help from the internet.
***********************************************************************/

#ifndef SENECA_POWER_H
#define SENECA_POWER_H


namespace seneca {
	const int MAX_NAME_LENGTH = 50;

	class Power {
		char m_name[MAX_NAME_LENGTH + 1];
		int m_rarity;

	public:
		Power();
		Power(const char* name, int rarity);
		void setEmpty();
		void createPower(const char* name, int rarity);

		const char* checkName() const;
		int checkRarity() const;
		bool isEmpty() const;
	};
	void displayDetails(Power* powers, int size);
}
#endif