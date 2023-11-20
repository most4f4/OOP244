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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"  
#include "Label.h"
using namespace std;

namespace sdds
{
	Label::Label()
	{
		strCpy(frame, "+-+|+-+|"); // Copy the default frame to the frame member variable
		content = nullptr; 
	}

	Label::Label(const char* frameArg)
	{
		strCpy(frame, frameArg); // Copy the frame argument to the frame member variable
		content = nullptr; 
	}

	Label::Label(const char* frameArg, const char* contents)
	{
		strCpy(frame, frameArg); // Copy the frame argument to the frame member variable
		
		//check the length of contents, and make sure it is not more than 70
		if (strlen(contents) < 71) {
			content = new char[strlen(contents) + 1]; // Allocate dynamic memory for the content
			strCpy(content, contents);
		}
		else
		{
			strnCpy(content, contents, MAX_CHARS); // Copy at most MAX_CHARS characters from contents to content
		}
	}

	Label::~Label()
	{
		delete[] content; // Deallocate the dynamic memory for content
		content = nullptr;
	}

	void Label::readLabel()
	{
		if (content != nullptr) {
			delete[] content; // Deallocate the existing content if it's not nullptr
			content = nullptr;
		}

		const int maxInputSize = 71;
		char input[maxInputSize] = {};

		cout << "> ";

		cin.getline(input, maxInputSize); // Read a line of input from the user and store it in input
		input[maxInputSize - 1] = '\0'; // Ensure the input is null-terminated

		content = new char[strlen(input) + 1]; // Allocate dynamic memory for the content
		strCpy(content, input);
	}

	std::ostream& Label::printLabel() const 
	{
		if (content != nullptr)  // Make sure content has a value;
		{

			int length = strlen(content); // Get the length of the content

			//printing the top line
			cout << frame[0];
			cout.fill(frame[1]);
			cout.width(length + 3);
			cout << frame[2] << endl;

			//printing the second line
			cout << frame[7];
			cout.fill(' ');
			cout.width(length + 3);
			cout << frame[3] << endl;

			//printing the center line (content line)
			cout << frame[7];
			cout.width(length + 1);
			cout << content;
			cout << " " << frame[3] << endl;

			//printing the forth line
			cout << frame[7];
			cout.fill(' ');
			cout.width(length + 3);
			cout << frame[3] << endl;

			//printing the bottom line
			cout << frame[6];
			cout.fill(frame[5]);
			cout.width(length + 3);
			cout << frame[4];
		}
		return cout;
	}

}