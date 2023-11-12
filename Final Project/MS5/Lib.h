/* Citation and Sources...
Final Project Milestone 5
Module: 
Filename: Lib.h
Version 1.0
Author	Mostafa Hasanalipourshahrabadi
Revision History
-----------------------------------------------------------
Date      Reason
2023/11/07  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_LIB_H__
#define SDDS_LIB_H__

namespace sdds {

    // maximum number of day a publication can be borrowed with no penalty
    const int SDDS_MAX_LOAN_DAYS = 15;

    // The width in which the title of a publication should be printed on the console
    const int SDDS_TITLE_WIDTH = 30;

    // The width in which the author name of a book should be printed on the console
    const int SDDS_AUTHOR_WIDTH = 15;

    // The width in which the shelf id of a publication should be printed on the console
    const int SDDS_SHELF_ID_LEN = 4;

    // Maximum number of publications the library can hold.
    const int SDDS_LIBRARY_CAPACITY = 333;

}


#endif // !SDDS_LIB_H__
