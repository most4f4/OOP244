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

#ifndef LABEL_H
#define LABEL_H
#include <iostream>

#define MAX_CHARS 70

namespace sdds 
{

	class Label 
	{
		char frame[9];
		char* content;

	public:
		//Creates an empty label and defaults the frame to "+-+|+-+|"
		Label();
		//Creates an empty label and sets the frame to the frameArg argument.
		Label(const char* frameArg);

		Label(const char* frameArg, const char* contents);
		//Makes sure there is no memory leak when the label goes out of scope.
		~Label();
		//Reads the label from console up to 70 characters and stores it in the Label 
		void readLabel();

		std::ostream& printLabel()const;




	};




}


#endif