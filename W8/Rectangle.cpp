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
        //first line
        os << '+';
        os.setf(ios::right);
        os.width(m_width - 1);
        os.fill('-');
        os << '+' << endl;
        os.fill(' ');
        os.unsetf(ios::right);

        //second line
        os << '|';
        os.setf(ios::left);
        os.width(m_width - 2);
        os << label() << '|' << endl;

        //next (m_height - 3) lines
        for (int i = 0; i < m_height - 3; i++) {
            os << '|';
            os.setf(ios::right);
            os.width(m_width - 1);
            os.fill(' ');
            os << '|' << endl;
            os.unsetf(ios::right);
        }

        //last line
        os << '+';
        os.setf(ios::right);
        os.width(m_width - 1);
        os.fill('-');
        os << '+' << endl;
        os.unsetf(ios::right);
    }

}