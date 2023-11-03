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

}