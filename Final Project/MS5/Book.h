/* Citation and Sources...
Final Project Milestone 5
Module: Book
Filename: Book.h
Version 1.0
Author	Mostafa Hasanalipourshahrabadi
Revision History
-----------------------------------------------------------
Date      Reason
2023/11/08  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__

#include <iostream>
#include "Publication.h"

namespace sdds {

	class Book : public Publication {

		char* m_author{nullptr};
	
	public:

		Book();
		Book(const Book& src);
		Book& operator=(const Book& src);
		virtual ~Book();
		char type()const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);
		void set(int member_id);
		operator bool() const;

	};

}


#endif // !SDDS_BOOK_H__
