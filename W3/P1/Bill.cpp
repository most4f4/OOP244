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
#include "Bill.h"
#include "Item.h"


using namespace std;
namespace sdds {
    

    void Bill::setEmpty()
    {
        m_title[0] = '\0';
        m_items = nullptr;
    }


    bool Bill::isValid() const
    {
        // Check if m_title and m_items are valid
        if (m_title[0] == '\0' || m_items == nullptr)
        {
            return false;
        }

        // Loop through all the Items in m_items and check if they are valid
        for (int i = 0; i < m_noOfItems; i++)
        {
            if (!m_items[i].isValid())
            {
                return false;
            }
        }

        // All checks passed, the Bill is valid
        return true;
    }

    double Bill::totalTax()const
    {
        double sum = 0.0;

        for (int i = 0; i < m_itemsAdded; i++)
        {
            sum += m_items[i].tax();
        }

        return sum;
    }

    double Bill::totalPrice() const
    {
        double sum = 0.0;

        for (int i = 0; i < m_itemsAdded; i++)
        {
            sum += m_items[i].price();
        }

        return sum;
    }

    void Bill::Title() const
    {
        cout << "+--------------------------------------+" << endl;
        if (isValid())
        {
            cout << "| ";
            cout.setf(ios::left);
            cout.width(36);            
            cout << m_title << " |"   << endl;
            cout.unsetf(ios::left);

        }
        else 
        {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
    }

    void Bill::footer() const
    {
        cout << "+----------------------+---------+-----+" << endl;
        if (isValid())
        {
            cout << "|                Total Tax: ";
            cout.setf(ios::fixed);
            cout.setf(ios::right);
            cout.width(10);
            cout.precision(2);
            cout << totalTax();
            cout << " |" << endl;
            cout << "|              Total Price: ";
            cout.width(10);
            cout << totalPrice();
            cout << " |" << endl;
            cout << "|          Total After Tax: ";
            cout.width(10);
            cout << totalTax() + totalPrice();
            cout << " |" << endl;
            cout.unsetf(ios::right);


        }
        else
        {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+--------------------------------------+" << endl;
    }

    void Bill::init(const char* title, int noOfItems)
    {
        // Check if arguments are invalid
        if (title == nullptr || noOfItems <= 0) 
        {
            setEmpty(); // Set the Bill to an empty state
            
        }
        else 
        {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strnCpy(m_title, title, 36);

            // Dynamically allocate an array of Items
            m_items = new Item[m_noOfItems];

            // Set all the dynamically allocated Items to empty
            for (int i = 0; i < m_noOfItems; i++)
            {
                m_items[i].setEmpty();
            }

        }

    }

    bool Bill::add(const char* item_name, double price, bool taxed)
    {
        // Check if there is space to add an item
        if (m_itemsAdded < m_noOfItems)
        {
            // Set the values of the next available item
            m_items[m_itemsAdded].set(item_name, price, taxed);

            // Increment the counter for the number of added items
            m_itemsAdded++;

            return true;
        }
        return false; // Unable to add more items, return false
    }

    
    void Bill::display() const
    {
        Title();
        for (int i = 0; i < m_noOfItems; i++)
        {
            m_items[i].display();
        }
        footer(); 
    }

    void Bill::deallocate()
    {
        delete[] m_items;
        m_items = nullptr;
    }

}