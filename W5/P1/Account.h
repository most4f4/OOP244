/*
*****************************************************************************
                          Workshop - #5 (P1)
Full Name  : Mostafa Hasanalipourshahrabadi
Student ID#: 154581227
Email      : mhasanalipourshahrab@myseneca.ca
Section    : NAA
Date       : 2023-06-15

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      ~Account() {};

      std::ostream& display()const;

      operator bool() const; // returns true if the account is valid 
      operator int() const; // returns the account number
      operator double() const; // returns the balance value

      bool operator~() const; // returns true if the account is new or not set     
      Account& operator=(int number); // Sets the account number of the NEW account to the integer value.
      Account& operator=(Account& src); // Moves the balance and the account number from one account to a NEW account;
      Account& operator+=(double number); // Deposits the value of the double to the balance
      Account& operator-=(double number); // Withdrawes the the double value from balance )
      Account& operator<<(Account& src); // Moves funds from the right account to the left
      Account& operator>>(Account& src); // Moves funds from the left account to the right
      //Returns the sum of the balances of the two accounts
      friend double operator+(const Account& leftOperand, const Account& rightOperand);
      // Returns the sum of the balance of the right account should and the left value
      friend double& operator+=(double& leftOperand, const Account& rightOperand);
   };


   
   
}
#endif // SDDS_ACCOUNT_H_