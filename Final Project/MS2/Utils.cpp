/***********************************************************************
// OOP244 Utils Module
// File	Utils.h
// Version 1.0
// Date	2023-07-15
// Author Mostafa Hasanalipourshaharabadi
//
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
**********************************************************************/

/*
*****************************************************************
						  Final project milestone 1
Full Name  : Mostafa Hasanalipourshahrabadi
Student ID#: 154581227
Email      : mhasanalipourshahrab@myseneca.ca
Section    : NAA
Date       : 2023-07-15

Authenticity Declaration:
I declare this submission is the result of my own work and has
not been shared with any other student or 3rd party content
provider. This submitted piece of work is entirely of my own
creation.
*****************************************************************
*/

#include <iostream>
#include "Utils.h"

using namespace std;
namespace sdds {

	int getUserInt(const int min, const int max) {
		
        int userInput;
        bool validInput = false;

        do {
            cin >> userInput;
            if (cin.fail() || userInput < min || userInput > max) {
                cout << "Invalid Selection, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else {
                validInput = true;
            }
        } while (!validInput);

        return userInput;

	}


}