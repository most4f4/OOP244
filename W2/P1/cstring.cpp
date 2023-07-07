#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "cstring.h"


namespace sdds {

	// Copies the srouce character string into the destination
	void strCpy(char* des, const char* src)
	{
		int i;
		for (i = 0; src[i] != '\0'; i++) {
			des[i] = src[i];
		};
		des[i] = { '\0' };

	}

	// Copies the source character string into the destination upto "len"
	// characters. The destination will be null terminated only if the number
	// of the characters copied is less than "len"
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

	// Compares two C-strings 
	// returns 0 i thare the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
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

	// returns 0 i thare the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
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

	// returns the lenght of the C-string in characters
	int strLen(const char* s)
	{
		int i, count = 0;
		for (i = 0; s[i] != '\0'; i++) {
			count++;
		}
		return count;
	}

	// returns the address of first occurance of "str2" in "str1"
	// returns nullptr if no match is found
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


	// Concantinates "src" C-string to the end of "des"
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

