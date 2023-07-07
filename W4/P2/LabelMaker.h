/*
*****************************************************************************
						  Workshop - #4 (P2)
Full Name  : Mostafa Hasanalipourshahrabadi
Student ID#: 154581227
Email      : mhasanalipourshahrab@myseneca.ca
Section    : NAA
Date       : 2023-06-09

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef LABELMAKER_H
#define LABELMAKER_H

#include "Label.h"

namespace sdds 
{
	class LabelMaker 
	{
		Label* labels;
		int numLabels;
    public:
        LabelMaker(int noOfLabels);

        ~LabelMaker();

        void readLabels();

        void printLabels();
	};
}

#endif