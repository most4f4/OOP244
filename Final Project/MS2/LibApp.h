/*
*****************************************************************
                          Final project milestone 2
Full Name  : Mostafa Hasanalipourshahrabadi
Student ID#: 154581227
Email      : mhasanalipourshahrab@myseneca.ca
Section    : NAA
Date       : 2023-11-06

Authenticity Declaration:
I declare this submission is the result of my own work and has
not been shared with any other student or 3rd party content
provider. This submitted piece of work is entirely of my own
creation.
*****************************************************************
*/

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H

#include "Menu.h"

namespace sdds {

   class LibApp {

       bool m_changed;
       Menu m_mainMenu;
       Menu m_exitMenu;

       bool confirm(const char* message);
       void load();  
       void save();  
       void search();  
       void returnPub();  
       void newPublication();
       void removePublication();
       void checkOutPub();

   public:

       LibApp();
       void run();
   };
}

#endif // !SDDS_LIBAPP_H



