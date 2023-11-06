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
#include "Shape.h"

using namespace std;

namespace sdds {

	std::ostream& operator<<(std::ostream& os, const Shape& shape)
	{
		shape.draw(os);
		return os;
	}

	std::istream& operator>>(std::istream& is, Shape& shape)
	{
		shape.getSpecs(is);
		return is;
	}

}