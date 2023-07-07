/*
*****************************************************************************
						  Workshop - #3 (P2)
Full Name  : Mostafa Hasanalipourshahrabadi
Student ID#: 154581227
Email      : mhasanalipourshahrab@myseneca.ca
Section    : NAA
Date       : 2023-06-02

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_CALORIELIST_H
#define SDDS_CALORIELIST_H
#include "Food.h"

namespace sdds 
{

	class CalorieList
	{
		Food* food;
		int reportSize; 
		int noOfFoodsAdded; 
		int totalCalories()const; 
		void Title()const; 
		void footer()const; 
		void setEmpty(); 
		bool isValid()const;

	public:
		// sets the CalorieList to accept the "size" number of Food Items. 
		// This function is called to prepare the CalorieList for accepting food items
		void init(int size);

		// Adds Food Items using their Name, Calorie count and time of consumption up to 
		// the number set in the init() function, returns true if successful.
		bool add(const char* item_name, int calories, int when);

		// Displays the report with food information and the total calorie consumed in the day
		// as shown in the report sample
		void display()const;

		// Releases all the memory used. After this function init() can be called for another
		// report;
		void deallocate();
	};

} // end of namespace sdds


#endif 