/* Citation and Sources...
Final Project Milestone 5
Module: LibApp
Filename: LibApp.h
Version 1.0
Author	Mostafa Hasanalipourshahrabadi
Revision History
-----------------------------------------------------------
Date      Reason
2023/11/10  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H

#include "Menu.h"
#include "Lib.h"
#include "Publication.h"
#include "Book.h"

namespace sdds {

   class LibApp {

       bool m_changed;
       Menu m_mainMenu;
       Menu m_exitMenu;
       Menu m_pubType;
       char m_fileName[257]{};
       Publication* m_ppa[SDDS_LIBRARY_CAPACITY]{}; //Publication Pointers Array 
       int m_nolp{0}; //Number Of Loaded Publications 
       int m_llrn{0}; //Last Library Reference Number 

       bool confirm(const char* message);
       void load();  
       void save();  
       int search(int searchType);
       void returnPub();  
       void newPublication();
       void removePublication();
       void checkOutPub();
       Publication* getPub(int libRef);

   public:

       LibApp(const char* fileName);
       void run();
   };
}

#endif // !SDDS_LIBAPP_H



