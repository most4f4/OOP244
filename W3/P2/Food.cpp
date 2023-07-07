#include "Food.h"
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



/*
The Food class should at least hold the following information.
Food name; up to 30 characters
Calorie number; valid between 0 and 3000 calories (including 3000).
Time of consumption; values 1, 2, 3 or 4 (see Meal time and their code)
*/

#include <iostream>
#include "cstring.h"
#include "Food.h"


using namespace std;

namespace sdds 
{
	void Food::setEmpty()
	{
		f_name[0] = '\0';
		f_calNo = -1;
	}

	bool Food::isValid()const
	{
		return (f_name[0] != '\0' && f_calNo != -1);
	}

	void Food::setName(const char foodName[])
	{
		strnCpy(f_name, foodName, MAX_CHARS);
	}

	void Food::set(const char foodName[], int CaloryNumber, int dayTime)
	{
		if (foodName == nullptr || CaloryNumber < 0 || CaloryNumber > 3000 ||
			dayTime<1 || dayTime >4)
		{
			setEmpty();
		}
		else 
		{
			setName(foodName);
			f_calNo = CaloryNumber;
			f_time = dayTime;
		}
	}

	void Food::display() const
	{
		if (isValid())
		{
			cout << "| ";
			cout.setf(ios::left);
			cout.fill('.');
			cout.width(30);
			cout << f_name;
			cout.fill(' ');
			cout.unsetf(ios::left);
			cout << " | ";

			cout.setf(ios::right);
			cout.width(4);
			cout << f_calNo;
			cout.unsetf(ios::right);
			cout << " | ";

			cout.setf(ios::left);
			cout.width(10);
			switch(f_time) 
			{
			case 1: 
				cout << "Breakfast";
				break;
			case 2:
				cout << "Lunch";
				break;
			case 3:
				cout << "Dinner";
				break;
			case 4:
				cout << "Snack";
				break;
			}
			cout.unsetf(ios::left);
			cout << " |" << endl;
		}
		else
		{
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}

	int Food::calorie() const
	{
		return f_calNo;
	}



}