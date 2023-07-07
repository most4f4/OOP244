/*
*****************************************************************************
						  Workshop - #3 (P1)
Full Name  : Mostafa Hasanalipourshahrabadi
Student ID#: 154581227
Email      : mhasanalipourshahrab@myseneca.ca
Section    : NAA
Date       : 2023-05-31

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
#include "cstring.h"


namespace sdds {

	void strCpy(char* des, const char* src)
	{
		int i;
		for (i = 0; src[i] != '\0'; i++) {
			des[i] = src[i];
		};
		des[i] = { '\0' };

	}

	void strnCpy(char* des, const char* src, int len)
	{
		int i;
		for (i = 0; src[i] != '\0' && i != len; i++) {
			des[i] = src[i];
		}
		if (i < len)
		{
			des[i] = { '\0' };
		}
	}

	int strCmp(const char* s1, const char* s2)
	{
		int i, found = 0;
		for (i = 0; found == 0; i++) {
			if (s1[i] > s2[i])
			{
				found = 1;
				return 1;
			}
			else if (s1[i] < s2[i])
			{
				found = 1;
				return -1;
			}
			else if (s1[i] == '\0' && s2[i] == '\0')
			{
				found = 1;
			}
		}
		return 0;
	}

	int strnCmp(const char* s1, const char* s2, int len)
	{
		int i, found = 0;
		for (i = 0; found == 0 && i < len; i++) {
			if (s1[i] > s2[i])
			{
				found = 1;
				return 1;
			}
			else if (s1[i] < s2[i])
			{
				found = 1;
				return -1;
			}
			else if (s1[i] == '\0' && s2[i] == '\0')
			{
				found = 1;
			}
		}
		return 0;
	}

	int strlen(const char* s)
	{
		int count = 0;
		for (int i = 0; s[i] != '\0'; i++) {
			count++;
		}
		return count;
	}

	const char* strStr(const char* str1, const char* str2) {
		int i, j, index, count = 0;
		for (i = 0; str2[i] != '\0'; i++) {
			count++;
		}
		for (i = 0, j = 0; str1[i] != '\0'; i++) {
			if (str1[i] == str2[j]) {
				while (j < count && str1[i + j] == str2[j]) {
					j++;
				}
				if (j == count) {
					index = i;
					return str1 + index;
				}
			}
			j = 0;
		}
		return nullptr;
	}

	void strCat(char* des, const char* src) {
		int count = 0;
		for (int i = 0; des[i] != '\0'; i++) {
			count++;
		}
		int j = 0;
		for (int i = 0; src[i] != '\0'; i++) {
			des[count] = src[j];
			count++;
			j++;
		}
		des[count] = '\0';
	}

}

