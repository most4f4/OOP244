/*
*****************************************************************************
						  Workshop - #8
Full Name  : Mostafa Hasanalipourshahrabadi
Student ID#: 154581227
Email      : mhasanalipourshahrab@myseneca.ca
Section    : NAA
Date       : 2023-11-02

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "LblShape.h"

using namespace std;

namespace sdds {

	const char* LblShape::label() const
	{
		return m_label;
	}

	LblShape::LblShape(const char* label)
	{

		if (label != nullptr) {

			m_label = new char[strlen(label) + 1];

			strcpy(m_label, label);

		}

	}

	LblShape::~LblShape()
	{
		delete[] m_label;
		m_label = nullptr;
	}

	void LblShape::getSpecs(std::istream& is)
	{
		char temp[100];
		//string temp;
		
		is.getline(temp, 100, ',');
		//getline(is, temp, ',')
		
		delete[] m_label;

		m_label = new char[strlen(temp) + 1];
		//m_lable = new char[strlen(temp.c_str())+1];
		//m_label = new char[temp.length() + 1];
		

		strcpy(m_label, temp);
		//strcpy(m_label, temp.c_str());

	}

}

