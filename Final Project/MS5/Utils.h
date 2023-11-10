/* Citation and Sources...
Final Project Milestone 4
Module: Utils
Filename: Utils.h
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

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

#include <iostream>


namespace sdds {

    class Utils {

    public:

        char* strcpy(char* des, const char* src)const;

        char* strncpy(char* des, const char* src, int len)const;

        int strlen(const char* str)const;

        void reStrAloCpy(char*& des, const char* src);

        void strAloCpy(char*& des, const char* src);

        int getUserInt(const int min, const int max);

        int getUserInt(const int min, const int max, const char* error);

    };
    extern Utils ut;

}

#endif // !SDDS_UTILS_H
