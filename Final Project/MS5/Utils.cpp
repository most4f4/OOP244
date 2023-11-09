/* Citation and Sources...
Final Project Milestone 4
Module: Utils
Filename: Utils.cpp
Version 1.0
Author	Mostafa Hasanalipourshahrabadi
Revision History
-----------------------------------------------------------
Date      Reason
2023/11/08  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include <iostream>
#include "Utils.h"

using namespace std;
namespace sdds {

    Utils ut;

    char* Utils::strcpy(char* des, const char* src)const {
        int i;
        for (i = 0; src[i]; i++) des[i] = src[i];
        des[i] = char(0);
        return des;
    }

    int Utils::strlen(const char* str)const {
        int len;
        for (len = 0; str[len]; len++);
        return len;
    }

    char* Utils::strncpy(char* des, const char* src, int len)const {
        int i = 0;
        while (i < len - 1 && src[i]) {
            des[i] = src[i];
            i++;
        }
        des[i] = src[i];
        return des;
    }

    void Utils::reStrAloCpy(char*& des, const char* src) {
        delete[] des;
        strAloCpy(des, src);
    }

    void Utils::strAloCpy(char*& des, const char* src) {
        des = nullptr;
        if (src) {
            des = new char[ut.strlen(src) + 1];
            ut.strcpy(des, src);
        }
    }

    int getUserInt(const int min, const int max) {

        int userInput;
        bool validInput = false;

        do {
            cin >> userInput;
            if (cin.fail() || userInput < min || userInput > max) {
                cout << "Invalid Selection, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else {
                validInput = true;
            }
        } while (!validInput);

        return userInput;

    }
}