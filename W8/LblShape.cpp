#include <iostream>
#include <cstring>
#include "LblShape.h"

using namespace std;

namespace sdds {

	const char* LblShape::label() const
	{
		return m_label;
	}

	LblShape::LblShape(const char* label)
	{

		if (label != nullptr) {

			m_label = new char[strlen(label) + 1];

			strcpy(m_label, label);

		}

	}

}

