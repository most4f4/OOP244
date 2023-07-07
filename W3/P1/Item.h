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


#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_


namespace sdds {

   class Item {
      char m_itemName[21];
      double m_price;
      bool m_taxed;
      void setName(const char* name);
   public:
      void setEmpty();
      void set(const char* name, double price, bool taxed);
      void display()const;
      bool isValid()const;
      double price()const;
      double tax()const;
   };
}

#endif // !SDDS_SUBJECT_H
