/*
*****************************************************************************
						  Workshop - #5 (P2)
Full Name  : Mostafa Hasanalipourshahrabadi
Student ID#: 154581227
Email      : mhasanalipourshahrab@myseneca.ca
Section    : NAA
Date       : 2023-06-16

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
#include "Mark.h"

using namespace std;

namespace sdds {


	Mark::Mark()
	{
		m_mark = 0;
	}

	Mark::Mark(int number)
	{
		if (number >= 0 && number <= 100) 
		{
			m_mark = number;
		}
		else 
		{
			m_mark = -1;
		}
	}

	Mark::operator int() const
	{
		return (m_mark != -1) ? m_mark : 0;
	}

	Mark::operator double() const
	{

		if (m_mark >=0 && m_mark <50) return 0.0;
		else if (m_mark >= 50 && m_mark < 60) return 1.0;
		else if (m_mark >= 60 && m_mark < 70) return 2.0;
		else if (m_mark >= 70 && m_mark < 80) return 3.0;
		else if (m_mark >= 80 && m_mark < 100) return 4.0;
		else return 0.0;

	}

	Mark::operator char() const
	{
		if (m_mark >= 0 && m_mark < 50) return 'F';
		else if (m_mark >= 50 && m_mark < 60) return 'D';
		else if (m_mark >= 60 && m_mark < 70) return 'C';
		else if (m_mark >= 70 && m_mark < 80) return 'B';
		else if (m_mark >= 80 && m_mark < 100) return 'A';
		else return 'X';

	}

	Mark& Mark::operator+=(int number)
	{
		if (m_mark != -1) {
			m_mark += number;
			if (m_mark < 0 || m_mark > 100) {
				m_mark = -1;
			}
		}
		return *this;
	}

	Mark& Mark::operator=(int number)
	{
		if (number >= 0 && number <= 100) {
			m_mark = number;
		}
		else {
			m_mark = -1;
		}
		return *this;
	}

	int& operator+=(int& value, const Mark& mark)
	{
		if (mark.m_mark != -1) {
			value += mark.m_mark;
		}
		return value;
	}

}