/*
*****************************************************************************
						  Workshop - #10
Full Name  : Mostafa Hasanalipourshahrabadi
Student ID#: 154581227
Email      : mhasanalipourshahrab@myseneca.ca
Section    : NAA
Date       : 2023-11-06

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_SEARCHNLIST_H__
#define SDDS_SEARCHNLIST_H__

#include <iostream>
#include "Collection.h"
#include "Car.h"
#include "Student.h"
#include "Employee.h"

using namespace std;
namespace sdds {

	/// <summary>
	/// This function template searches for a specified key in an array of templated objects.
	/// If a match is found, the function adds all matching objects to the provided Collection.
	/// </summary>
	/// 
	/// <typeparam name="T1"> The type of objects in the Collection and the array. </typeparam>
	/// <typeparam name="T2"> The type of the key to be searched for in the array. </typeparam>
	/// 
	/// <param name="obj"> A reference to a Collection of templated objects </param>
	/// <param name="arr"> An array of templated objects of the same type as the Collection </param>
	/// <param name="numElements"> Number of elements in the array of objects </param>
	/// <param name="key"> A key templated value to search for, in the array of objects </param>
	/// 
	/// <returns> true if at least one match is found and false otherwise </returns>
	/// 
	/// 
	/// Requirements:
	/// 1- The == operator must be defined for objects of type T1 and T2.
	/// 2- The Collection class must have a member function named add that adds an object of type T1.
	///
	template <typename T1, typename T2>
	bool search(Collection<T1>& obj, T1 arr[], int numElements, T2 key) {	
		bool result = false;
		for (int i = 0; i < numElements; i++) {
			if (arr[i] == key) { // REQUIREMENT 1 
				result = true;
				obj.add(arr[i]); // REQUIREMENT 2
			}
		}
		return result;
	}
	
	/// <summary>
	/// This function prints the provided title in the fist line and in following lines
	/// it prints the row number and by the elements of the given constant array.
	/// </summary>
	/// 
	/// <typeparam name="T"> The type of objects in the array. </typeparam>
	/// 
	/// <param name="title"> he title to be printed before listing the array elements. </param>
	/// <param name="arr"> A constant array of templated objects of type T.</param>
	/// <param name="numElements"> Number of elements in the array. </param>
	/// 
	/// Requirements:
	/// The insertion operator << must be defined for objects of type to enable printing 
	/// elements using cout.
	///
	template <typename T>
	void listArrayElements(const char* title, const T arr[], int numElements) {
		cout << title << endl;
		for (int i = 0; i < numElements; i++) {
			cout << i + 1 << ": " << arr[i] << endl; // REQUIREMENT 1
		}
	}

}

#endif // !SDDS_SEARCHNLIST_H__
