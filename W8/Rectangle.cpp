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
        if (height >= 3 && width >= strlen(LblShape::label()) + 2) {
            m_height = height;
            m_width = width;
        }
        else
        {
            m_height = 0;
            m_width = 0;
        }
    }

    void Rectangle::getSpecs(std::istream& is)
    {
        LblShape::getSpecs(is);

        is >> m_width;
        is.ignore(); // ignore the separator
        is >> m_height;
        is.ignore(1000, '\n');

    }

    void Rectangle::draw(std::ostream& os) const
    {
        if (m_width > 0 && m_height > 0 && LblShape::label() != nullptr) {
            //first line
            os << '+';
            os.width(m_width - 1);
            os.fill('-');
            os << '+' << endl;
            os.fill(' ');

            //second line
            os << '|';
            os.setf(ios::left);
            os.width(m_width - 2);
            os << label() << '|' << endl;
            os.unsetf(ios::left);


            //next (m_height - 3) lines
            for (int i = 0; i < m_height - 3; i++) {
                os << '|';
                os.width(m_width - 1);
                os.fill(' ');
                os << '|' << endl;
            }

            //last line
            os << '+';
            os.width(m_width - 1);
            os.fill('-');
            os << '+' << endl;
            os.fill(' ');

        }

    }

}