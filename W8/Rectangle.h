#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_

#include <iostream>
#include "LblShape.h"

namespace sdds {

	class Rectangle : public LblShape {

		int m_width;

		int m_height;
	
	public:
		
		Rectangle();

		Rectangle(const char* label, int width, int height);

		void getSpecs(std::istream& is);

		void draw(std::ostream& os) const;

	};

}

#endif