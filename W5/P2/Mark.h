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

#ifndef  SDDS_MARK_H_
#define SDDS_MARK_H_

#include <iostream>

namespace sdds {

	class Mark {
		int m_mark;
	public:
		Mark();
		Mark(int number);
		operator int() const;
		operator double() const;
		operator char() const;
		Mark& operator+=(int number);
		Mark& operator=(int number);
		friend int& operator+=(int& value, const Mark& mark);
	};
}

#endif // ! SDDS_MARK_H_
