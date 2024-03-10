/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.cpp
// Version v0.8 Oct 21st 2023
// Author  Jitesh Arora
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: Babak Ghafourigivi
// Student ID: 165118233
// Student email: bghafourigivi@myseneca.ca
// Section: ZAA
// Date: 18 Feb 2024
// I received help from a friend and also help from the internet.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include "bankaccount.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>

using namespace std;
namespace seneca
{
	// Default Constructor with default arguments
	bankAccount::bankAccount(const char* name, bool checking)
	{
		m_userName[0] = '\0';		// Empty string implies is account is not open 
		setup(name, checking);
	}

	// Open bank account: setup can only be done once!
	bool bankAccount::setup(const char* name, bool checking)
	{
		if (isOpen())
			return false;
		if (name == nullptr)
			return false;

		strcpy(m_userName, name);
		m_monthlyTransactions = 0;
		m_checking = checking;
		m_funds = 0;
		return true;
	}

	// Account is open if user name string is not empty
	bool bankAccount::isOpen() const
	{
		return (m_userName[0] != '\0');
	}

	// ADD: Type Conversion, Unary & Binary Operators; + Additional Methods
	bankAccount::operator bool() const
	{
		return isOpen();
	}
	bankAccount::operator double() const
	{
		return m_funds;
	}
	bankAccount& bankAccount::operator++()
	{
		if (isOpen() && m_funds > 0) {
			double interest{};
			if (m_checking) {
				interest = m_funds * checkInterest;
			}
			else {
				interest = m_funds * saveInterest;
			}
			m_funds += interest;
		}
		return *this;
	}
	bankAccount& bankAccount::operator--()
	{
		if (isOpen()) {
			double transFee;
			if (m_checking) {
				transFee = m_monthlyTransactions * chTrFee;
			}
			else
			{
				transFee = m_monthlyTransactions * saveTrFee;
			}
			m_funds -= transFee;
		}
		return *this;
	}
	bool bankAccount::operator+=(double addFund)
	{
		if (isOpen()) {
			m_funds += addFund;
			m_monthlyTransactions++;
			if (addFund >= 0) {
				cout << "Deposit $";
			}
			else
			{
				cout << "Withdraw $";
				addFund = addFund * -1;
			}
			cout << fixed << setprecision(2) << addFund
				<< " for " << this->m_userName << endl;
			return true;
		}
		return false;
	}
	bool bankAccount::operator-=(double subFund)
	{
		return *this += (subFund * -1);
	}
	bool bankAccount::operator==(const bankAccount& accountCheck) const
	{
		if (!strcmp(this->m_userName, accountCheck.m_userName) && this->m_checking == accountCheck.m_checking) {
			double difference = this->m_funds - accountCheck.m_funds;
			if (difference < 0.001 && difference > -0.001)
			{
				return true;
			}
		}
		return false;
	}
	bool bankAccount::operator>(double MoneyCheck) const
	{
		if (isOpen() && this->m_funds > MoneyCheck)
		{
			return true;
		}
		return false;
	}
	bool bankAccount::operator<=(double MoneyCheck) const
	{
		return !(*this > MoneyCheck);
	}

	bool bankAccount::operator<<(bankAccount& AccountForTransfer)
	{
		if (this->isOpen() && AccountForTransfer.isOpen() && AccountForTransfer.m_funds > 0)
		{
			cout << "Transfer $" << AccountForTransfer.m_funds << " from " << AccountForTransfer.m_userName
				<< " to " << this->m_userName << endl;
			*this += AccountForTransfer.m_funds;
			AccountForTransfer -= AccountForTransfer.m_funds;
			return true;
		}
		return false;
	}
	void bankAccount::display(void) const
	{
		if (isOpen()) {
			cout << "Display Account -> User:";
			for (int i = 0; i < (int)(16 - strlen(this->m_userName)); i++)
			{
				cout << "-";
			}
			cout << this->m_userName << " | " << (this->m_checking ? "Checking" : " Savings") << " | Balance: $";
			cout << setw(8) << setfill(' ') << fixed << setprecision(2)
				<< right << this->m_funds << " | Transactions:";
			cout << setw(3) << setfill('0') << this->m_monthlyTransactions << endl;
		}
		else
		{
			cout << "Display Account -> User:------- NOT OPEN" << endl;
		}
	}
	// ADD: Global Helper Functions
	bool operator>(double lhs, const bankAccount& rhs)
	{
		if (lhs > (double)rhs)
		{
			return true;
		}
		return false;
	}
	bool operator<=(double lhs, const bankAccount& rhs)
	{
		return !(lhs > rhs);
	}
}