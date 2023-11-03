#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_

#include <iostream>
#include "Shape.h"

namespace sdds {

	class LblShape : public Shape {

		char* m_label{}; // initialized to nullptr by default 

	protected:

		const char* label() const;

	public:

		LblShape();

		LblShape(const char* label);

		virtual ~LblShape();

		LblShape(const LblShape& source) = delete;

		LblShape& operator=(const LblShape& source) = delete;

		void getSpecs(std::istream& is);
		


	}; 

}


#endif