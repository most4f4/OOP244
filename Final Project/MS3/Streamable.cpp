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
