/* Citation and Sources...
Final Project Milestone 2
Module: Utils
Filename: Utils.cpp
Version 1.0
Author	Mostafa Hasanalipourshahrabadi
Revision History
-----------------------------------------------------------
Date      Reason
2023/11/06  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
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