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


#include <iostream>
#include "cstring.h"
#include "Item.h"


using namespace std;

namespace sdds {
    
    void Item::setName(const char* name)
    {
        strnCpy(m_itemName, name, 20);
        m_itemName[20] = '\0';
    }

    void Item::setEmpty() 
    {
        m_price = 0.0;
        m_itemName[0] = '\0';
    }

    void Item::set(const char* name, double price, bool taxed)
    {
        if (price < 0.0 || name == nullptr)
        {
            setEmpty();
        }
        else 
        {
            setName(name);
            m_price = price;
            m_taxed = taxed;
        }
    }


    double Item::price() const 
    {
        return m_price;
    }


    double Item::tax() const
    {
        const double taxRate = 0.13;
        return (m_taxed) ? taxRate * m_price : 0.0;

    }


    bool Item::isValid() const 
    {
        if (m_itemName[0] != '\0' && m_price != 0.0 )
        {
            return true;
        }
        return false;
    }

    /*
    Prints an item in the following format. If the Item is valid:
    "| "
    m_itemName; left-justified in 20 spaces, padded with '.' (dots)
    " | "
    m_price; right-justified in 7 spaces with two digits after the decimal point
    " | "
    if m_taxed is true prints "Yes" otherwise prints "No "
    " |"
    Newline
    */
    void Item::display() const
    {
        if (isValid()) {
            cout << "| ";
            cout.fill('.');
            cout.setf(ios::left);
            cout.width(20);
            cout << m_itemName;
            cout << " | ";
            cout.fill(' ');
            cout.unsetf(ios::left);

            cout.setf(ios::fixed);
            cout.width(7);
            cout.precision(2);
            cout << m_price;
            cout << " | ";
            cout.unsetf(ios::fixed);

            m_taxed ? cout << "Yes" : cout << "No ";
            cout << " |" << endl;

        }
        else
        { 
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
    }



}