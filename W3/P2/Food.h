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

#ifndef SDDS_FOOD_H
#define SDDS_FOOD_H

#define MAX_CHARS 30

namespace sdds 
{
	class Food 
	{
		char f_name[MAX_CHARS+1];
		int f_calNo;
		int f_time;
	public:
		void setEmpty();
		bool isValid()const;
		void setName(const char foodName[]);
		void set(const char foodName[], int CaloryNumber, int dayTime);
		void display() const;
		int calorie() const;
	};

}

#endif 