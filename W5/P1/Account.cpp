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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds
{
	void Account::setEmpty() {
		m_number = -1;
		m_balance = 0.0;
	}
	// New account
	Account::Account() {
		m_number = 0;
		m_balance = 0.0;
	}
	Account::Account(int number, double balance) {
		setEmpty();
		if (number >= 10000 && number <= 99999
			&& balance > 0) {
			m_number = number;
			m_balance = balance;
		}
	}
	std::ostream& Account::display() const {
		if (*this) {
			cout << " ";
			cout << m_number;
			cout << " | ";
			cout.width(12);
			cout.precision(2);
			cout.setf(ios::fixed);
			cout << m_balance;
			cout << " ";
		}
		else if (~*this) {
			cout << "  NEW  |         0.00 ";
		}
		else {
			cout << "  BAD  |    ACCOUNT   ";
		}
		return cout;
	}

	Account::operator bool() const
	{
		return (m_number >= 10000 && m_number <= 99999 && m_balance >= 0.0);
	}

	Account::operator int() const
	{
		return m_number;
	}

	Account::operator double() const
	{
		return m_balance;
	}

	bool Account::operator~() const
	{
		return m_number == 0;
	}

	Account& Account::operator=(int number)
	{
		if (m_number == 0) // Check if the account is new
		{
			if (number >= 10000 && number <= 99999)
			{
				m_number = number;
			}
			else
			{
				setEmpty();
			}
		}
		return *this;
	}

	Account& Account::operator=(Account& src)
	{
		// Check if the left account is new and the right account is valid
		if (m_number == 0 && src)
		{
			m_number = src.m_number;
			m_balance = src.m_balance;
			src.m_number = 0; // Reset balance of the right account to zero
			src.m_balance = 0.0; // Reset account number of the right account to zero (new)
		}
		return *this;
	}

	Account& Account::operator+=(double number)
	{
		if (*this && number > 0)
		{
			m_balance += number;
		}
		return *this;
	}

	Account& Account::operator-=(double number)
	{
		if (*this && m_balance >= number && number >= 0)
		{
			m_balance -= number;
		}
		return *this;
	}

	Account& Account::operator<<(Account& src)
	{
		// Check if the accounts are not the same and both accounts are valid
		if (m_number != src.m_number && *this && src)
		{
			m_balance += src.m_balance;
			src.m_balance = 0.0;

		}

		return *this;
	}

	Account& Account::operator>>(Account& src)
	{
		// Check if the accounts are not the same and both accounts are valid
		if (m_number != src.m_number && *this && src)
		{
			src.m_balance += m_balance;
			m_balance = 0.0;
		}

		return *this;
	}

	double operator+(const Account& left, const Account& right)
	{
		if (left && right)
		{
			return left.m_balance + right.m_balance; // Return the sum of the balances
		}
		return 0.0; // Return zero if any of the accounts is invalid
	}

	double& operator+=(double& left, const Account& right)
	{
		if (right)
		{
			left += right.m_balance;
		}
		return left;
	}

}