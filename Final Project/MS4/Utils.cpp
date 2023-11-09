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
}