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

#include <iostream>
#include "LabelMaker.h"
#include "cstring.h"
using namespace std;

namespace sdds
{
	//creates a dynamic array of Labels to the size of noOfLabels
	LabelMaker::LabelMaker(int noOfLabels)
	{
		if (noOfLabels > 0)
		{
			numLabels = noOfLabels;
			labels = new Label[noOfLabels]; // Allocate dynamic memory for the labels array
		}

	}

	LabelMaker::~LabelMaker()
	{
		delete[] labels;  // Deallocate the dynamic memory for the labels array
		labels = nullptr;  // Set the labels pointer to nullptr
	}

	void LabelMaker::readLabels()
	{
		cout << "Enter " << numLabels << " labels:" << endl;

		for (int i = 0; i < numLabels; i++) 
		{
			cout << "Enter label number " << i + 1<< endl;
			labels[i].readLabel(); // Read the label for the current index
		}
	}

	void LabelMaker::printLabels()
	{
		for (int i = 0; i < numLabels; i++) 
		{
			labels[i].printLabel(); // Print the label for the current index
			cout << endl;
		}
	}

}