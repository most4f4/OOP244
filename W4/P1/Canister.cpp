/*
*****************************************************************************
						  Workshop - #4 (P1)
Full Name  : Mostafa Hasanalipourshahrabadi
Student ID#: 154581227
Email      : mhasanalipourshahrab@myseneca.ca
Section    : NAA
Date       : 2023-06-08

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;
namespace sdds {

	void Canister::setToDefault()
	{
		// Set attributes to default values
		m_contentName = nullptr;
		m_height = 13.0;
		m_diameter = 10.0;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	bool Canister::isEmpty() const
	{
		return m_contentVolume < 0.00001;
	}

	bool Canister::hasSameContent(const Canister& C) const
	{
		if (m_contentName != nullptr && C.m_contentName != nullptr)
		{
			return strCmp(m_contentName, C.m_contentName) == 0;
		}
		return false;
	}

	void Canister::setName(const char* Cstr)
	{
		if (Cstr != nullptr && m_usable)
		{
			// Deallocate any existing content name
			delete[] m_contentName;
			m_contentName = nullptr;

			//Allocate dynamicmemory to the length of Cstr
			m_contentName = new char[strlen(Cstr) + 1];

			//Copy the Cstr into the newly allocated memory
			strCpy(m_contentName, Cstr);
		}
	}

	Canister::Canister()
	{
		setToDefault();
	}

	Canister::Canister(const char* contentName)
	{
		setToDefault();
		setName(contentName);
	}

	Canister::Canister(double height, double diameter, const char* contentName)
	{
		//Sets the attributes to their default values
		setToDefault();

		//Check the dimensions are within acceptable values
		if (height >= 10.0 && height <= 40.0 &&
			diameter >= 10.0 && diameter <=30.0)
		{
			m_height = height;
			m_diameter = diameter;
			m_contentVolume = 0.0;
			m_usable = true;
			setName(contentName);
		}
		else
		{
			// Set the Canister as unusable
			m_usable = false;
		}
	}

	Canister::~Canister()
	{
		//Deallocates the dynamic memory pointed by the content name attribute.
		delete[] m_contentName;
		m_contentName = nullptr;
	}

	void Canister::clear()
	{
		// check if it is an unusable Canister
		if (!m_usable) 
		{
			//Deallocate the memory pointed by the content name attribute
			delete[] m_contentName;

			//Set the content name attribute to nullptr
			m_contentName = nullptr;

			//Set the content volume attribute to 0.0
			m_contentVolume = 0.0;

			//Set the usable flag attribute to true
			m_usable = true;
		}

	}

	double Canister::volume() const
	{
		return m_contentVolume;
	}

	double Canister::capacity() const
	{
		const double PI = 3.14159265;
		return PI*(m_height - 0.267)*(m_diameter/2)*(m_diameter/2);
	}

	Canister& Canister::setContent(const char* contentName)
	{
		// Render the canister unusable if contentName argument is null
		if (contentName == nullptr)
		{
			m_usable = false;
		}
		// Set the content name if the canister is empty
		else if(isEmpty())
		{
			setName(contentName);
		}
		// Render the canister unusable if the content name is not the same
		else if (!hasSameContent(contentName))
		{
			m_usable = false;
		}
		
		return *this;
	}

	Canister& Canister::pour(double quantity)
	{
		if (m_usable && quantity > 0.0 &&
			(quantity + volume() <= capacity())) 
		{
			m_contentVolume += quantity;
		}
		else 
		{
			m_usable = false;
		}
		return *this;
	}

	Canister& Canister::pour(Canister& C)
	{
		setContent(C.m_contentName);

		if (C.volume() > capacity() - volume())
		{
			// Reduce the content volume of the argument by capacity() - volume()
			C.m_contentVolume -= (capacity() - volume());
			// Set the content volume of the current object to capacity()
			m_contentVolume = capacity();

		}
		else
		{
			// Pour the content volume of the argument using pour() method
			pour(C.m_contentVolume);
			// Set the content volume of the argument to 0
			C.m_contentVolume = 0.0;
		}
		return *this;
	}

	std::ostream& Canister::display() const
	{
		// Prints all the number values with one digit after the decimal point
		cout.setf(ios::fixed);
		cout.precision(1);
		//In 7 spaces prints the capacity
		cout.width(7);
		cout << capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";

		if (!m_usable) 
		{
			cout << " of Unusable content, discard!";
		}
		else if (m_contentName != nullptr) 
		{
			cout << " of ";
			//In 7 spaces prints the volume
			cout.width(7);
			cout << volume() << "cc   " << m_contentName;
		}

		cout.unsetf(ios::fixed);
		return cout;
	}
}