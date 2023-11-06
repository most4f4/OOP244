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

#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_

#include <iostream>
#include "Shape.h"

namespace sdds {

	class LblShape : public Shape {

		char* m_label{nullptr}; 

	protected:

		const char* label() const;

	public:

		LblShape() {};

		LblShape(const char* label);

		virtual ~LblShape();

		LblShape(const LblShape& source) = delete;

		LblShape& operator=(const LblShape& source) = delete;

		void getSpecs(std::istream& is);
		
	}; 

}


#endif