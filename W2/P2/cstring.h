/*
*****************************************************************************
						  Workshop - #2 (P2)
Full Name  : Mostafa Hasanalipourshahrabadi
Student ID#: 154581227
Email      : mhasanalipourshahrab@myseneca.ca
Section    : NAA
Date       : 2023-05-27


Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef NAMESPACE_CSTRING_H
#define NAMESPACE_CSTRING_H

namespace sdds {

	void strCpy(char* des, const char* src);

	void strnCpy(char* des, const char* src, int len);

	int strCmp(const char* s1, const char* s2);

	int strnCmp(const char* s1, const char* s2, int len);

	int strLen(const char* s);

	const char* strStr(const char* str1, const char* str2);

	void strCat(char* des, const char* src);

}



#endif