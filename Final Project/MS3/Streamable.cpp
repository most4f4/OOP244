/* Citation and Sources...
Final Project Milestone 3
Module: Streamable
Filename: Streamable.cpp
Version 1.0
Author	Mostafa Hasanalipourshahrabadi
Revision History
-----------------------------------------------------------
Date      Reason
2023/11/07  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include <iostream>
#include "Streamable.h"

using namespace std;
namespace sdds {

	Streamable::~Streamable()
	{
	}

	std::ostream& operator<<(std::ostream& os, const Streamable& rightOperand)
	{
		if (rightOperand) {
			rightOperand.write(os);
		}
		return os;
	}

	std::istream& operator>>(std::istream& is, Streamable& rightOperand)
	{
		rightOperand.read(is);
		return is;
	}

}
