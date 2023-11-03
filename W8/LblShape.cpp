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

