/*
*****************************************************************************
						  Workshop - #8
Full Name  : Mostafa Hasanalipourshahrabadi
Student ID#: 154581227
Email      : mhasanalipourshahrab@myseneca.ca
Section    : NAA
Date       : 2023-11-02

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include <iostream>
#include "Line.h"

using namespace std;

namespace sdds {



	Line::Line() : LblShape()
	{
		m_length = 0;
	}

	Line::Line(const char* str, int length) : LblShape(str)
	{
		if (length > 0) {
			m_length = length;
		}
	}

	void Line::getSpecs(std::istream& is)
	{
		LblShape::getSpecs(is);

		is >> m_length;

		is.ignore(1000, '\n');
		// while (is.get() != '\n') {}
		
	}

	void Line::draw(std::ostream& os) const
	{
		if (m_length > 0 && LblShape::label() != nullptr) {
			os << LblShape::label() << endl;

			for (int i = 0; i < m_length; i++) {
				os << '=';
			}
		}
	}

}