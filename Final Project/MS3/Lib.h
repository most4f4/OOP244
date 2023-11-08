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
    const int SDDS_LIBRARY_CAPACITY = 5000;

}


#endif // !SDDS_LIB_H__
