#ifndef SDDS_SEARCHNLIST_H__
#define SDDS_SEARCHNLIST_H__

#include <iostream>
#include "Collection.h"

namespace sdds {

	/// <summary>
	/// The search function goes through all the elements of the array of objects 
	/// and adds all the matches found to the Collection object.
	/// </summary>
	/// <typeparam name="T1"></typeparam>
	/// <typeparam name="T2"></typeparam>
	/// <param name="obj"> A reference to a Collection of templated objects </param>
	/// <param name="arr"> An array of templated objects </param>
	/// <param name="numElements"> Number of elements in the array of objects </param>
	/// <param name="key"> A key templated value to search for, in the array of objects </param>
	/// <returns> true if at least one match is found and false otherwise </returns>
	template <typename T1, typename T2>
	bool search(Collection<T1>& obj, const T1* arr, int numElements, T2 key) {
		
		bool result = false;

		for (int i = 0; i < numElements; i++) {
			if (arr[i] == key) {
				result = true;
				obj.add(arr(i));
			}
		}
		return result;
	}

	
	template <typename T>
	void listArrayElements(const char* title, const T* arr, int numElements) {


		cout << title << endl;

		for (int i = 0; i < numElements; i++) {
			cout << i + 1 << ": " << arr[i] << endl;

		}

	}



}


#endif // !SDDS_SEARCHNLIST_H__
