/* Citation and Sources...
Final Project Milestone 2
Module: LibApp
Filename: LibApp.h
Version 1.0
Author	Mostafa Hasanalipourshahrabadi
Revision History
-----------------------------------------------------------
Date      Reason
2023/11/06  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
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



