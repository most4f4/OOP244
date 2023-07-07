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


#include <iostream>
#include "cstring.h"
#include "CalorieList.h"



using namespace std;

namespace sdds
{
	int CalorieList::totalCalories() const
	{
		int sum = 0;

		for (int i = 0; i < noOfFoodsAdded; i++)
		{
			sum += food[i].calorie();
		}
		return sum;
	}

	void CalorieList::setEmpty()
	{
		food = nullptr;
	}

	bool CalorieList::isValid() const
	{
		// Check if food pointer is valid
		if (food == nullptr)
		{
			return false;
		}

		// Loop through all the Items in food report and check if they are valid
		for (int i = 0; i < reportSize; i++)
		{
			if (!food[i].isValid())
			{
				return false;
			}
		}

		// All checks passed, the report is valid
		return true;
	}

	void CalorieList::Title() const
	{

		cout << "+----------------------------------------------------+" << endl;

		if (isValid())
		{
			cout << "|  Daily Calorie Consumption                         |" << endl;
		}
		else
		{
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}

		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;


	}

	void CalorieList::footer() const
	{

		cout << "+--------------------------------+------+------------+" << endl;
		if (isValid()) 
		{

			cout << "|    Total Calories for today:";
			cout.setf(ios::right);
			cout.width(9);
			cout << totalCalories();
			cout.unsetf(ios::right);
			cout << " |            |" << endl;
		}
		else 
		{
			cout << "|    Invalid Calorie Consumption list                |" << endl;
		}

		cout << "+----------------------------------------------------+" << endl;
	}

	void CalorieList::display() const
	{
		Title();
		for (int i = 0; i < reportSize; i++)
		{
			food[i].display();
		}
		footer();
	}

	void CalorieList::init(int size)
	{
		if (size <= 0)
		{
			setEmpty();
		}
		else
		{
			reportSize = size;
			noOfFoodsAdded = 0;
			food = new Food[reportSize];
			for (int i = 0; i < reportSize; i++)
			{
				food[i].setEmpty();
			}
		}
	}

	// Adds Food Items using their Name, Calorie count and time of consumption up to 
	// the number set in the init() function, returns true if successful.
	bool CalorieList::add(const char* item_name, int calories, int when)
	{
		if (noOfFoodsAdded < reportSize)
		{
			food[noOfFoodsAdded].set(item_name, calories, when);
			noOfFoodsAdded++;
			return true;
		}
		return false;
	}

	void CalorieList::deallocate()
	{
		delete[] food;
		food = nullptr;
	}


} // end of namespace sdds
