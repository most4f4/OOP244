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



#ifndef SDDS_BILL_H_
#define SDDS_BILL_H_
#include "Item.h"
namespace sdds {
   class Bill {
      char m_title[37]; // title of the shopping list
      Item* m_items; // pointer to the dynamically allocated array of Items
      int m_noOfItems; // size of the dynamically allocated array of Items
      int m_itemsAdded; // number of the Items added by the add method
      double totalTax()const; // returns the total tax applied to the Items
      double totalPrice()const; // returns the sum of prices of Items
      void Title()const; // Prints the title of the shopping list
      void footer()const; // prints the footer contaning total tax, price and total price after tax
      void setEmpty(); // sets the Bill to an emtpy state
      bool isValid()const; // returns true is the Bill and all of its Items are valid
   public:
      void init(const char* title, int noOfItems);
      bool add(const char* item_name, double price, bool taxed);
      void display()const;
      void deallocate();
   };
}
#endif // !SDDS_TRANSCRIPT_H
