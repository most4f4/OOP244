#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_

#include <iostream>
#include "Shape.h"

namespace sdds {

	class LblShape : public Shape {

		char* m_label{};

	protected:

		const char* lable() const;

	};

}


#endif