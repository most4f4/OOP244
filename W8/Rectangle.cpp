#include <iostream>
#include <cstring>
#include "Rectangle.h"

using namespace std;

namespace sdds {

    Rectangle::Rectangle() : LblShape()
    {
        m_width = 0;
        m_height = 0;
    }

    Rectangle::Rectangle(const char* str, int width, int height) : LblShape(str)
    {
        if (height >= 3 && width >= strlen(label()) + 2) {
            m_height = height;
            m_width = width;
        }
        else
        {
            m_height = 0;
            m_width = 0;
        }
    }

}