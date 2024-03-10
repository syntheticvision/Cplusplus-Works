/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.h
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
#pragma once
#ifndef SENECA_BANKACCOUNT_H_
#define SENECA_BANKACCOUNT_H_
namespace seneca
{
   const int	 ACCT_MAXLEN_USER = 16;	// Max Length of user name
   const double chTrFee = 1.25;
   const double saveTrFee = 3.50;
   const double checkInterest = 0.005;
   const double saveInterest = 0.025;

   // Class Definition
   class bankAccount
   {
   private:
      // Data Members
      char	    m_userName[ACCT_MAXLEN_USER];
      double	m_funds;
      bool	    m_checking;
      int		m_monthlyTransactions;
      bool isOpen() const;
   public:
      bankAccount(const char* name = nullptr, bool checking = false);
      bool setup(const char* name, bool checking);

      // ADD: Type Conversion, Unary, Binary Operators & Additional Methods
      // ...
      operator bool() const;
      operator double() const;
      bankAccount& operator++();
      bankAccount& operator--();
      bool operator+= (double addFund);
      bool operator-= (double subFund);
      bool operator== (const bankAccount& accountCheck) const;
      bool operator> (double MoneyCheck) const;
      bool operator<= (double MoneyCheck) const;
      bool operator<<(bankAccount& accountForTransfer);
      void display(void) const;

   };
   // ADD: Global helpers
   // ...
   bool operator> (double lhs, const bankAccount& rhs);
   bool operator<= (double lhs, const bankAccount& rhs);
}
#endif

