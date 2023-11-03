#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_

#include "LblShape.h"

namespace sdds{

	class Line : public LblShape {

		int m_length;

	public:

		Line();

		Line(const char* str, int length);

		void getSpecs(std::istream& is);

		void draw(std::ostream& os) const;

	};

}



#endif