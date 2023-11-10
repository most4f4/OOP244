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

#include "Book.h"
#include "Utils.h"
#include "Lib.h"

using namespace std;
namespace sdds {

	Book::Book()
	{
	}

	Book::Book(const Book& src): Publication(src)
	{
		ut.strAloCpy(m_author, src.m_author);
		
	}

	Book& sdds::Book::operator=(const Book& src)
	{
		if (this != &src) {
			Publication::operator=(src);
			ut.reStrAloCpy(m_author, src.m_author);
		}
		return *this;
	}

	Book::~Book()
	{
		delete[] m_author;
	}

	char Book::type() const
	{
		return 'B';
	}

	std::ostream& Book::write(std::ostream& os) const
	{
		Publication::write(os);

		if (conIO(os)) {

			os << " ";

			if (ut.strlen(m_author) > SDDS_AUTHOR_WIDTH) {
				for (int i = 0; i < SDDS_AUTHOR_WIDTH; i++) {
					os << m_author[i];
				}
			}
			else {
				os.setf(ios::left);
				os.width(SDDS_AUTHOR_WIDTH);
				os.fill(' ');
				os << m_author;
				os.unsetf(ios::left);
			}
			os << " |";

		}
		else {

			os << '\t' << m_author;

		}

		return os;

	}

	std::istream& Book::read(std::istream& istr)
	{
		char tempAuthor[257]{};

		Publication::read(istr);

		delete[] m_author;
		m_author = nullptr;

		if (conIO(istr)) {

			istr.ignore();
			cout << "Author: ";
			istr.getline(tempAuthor, 257);

		}
		else {

			istr.ignore();
			istr.getline(tempAuthor, 257);
		}

		if (istr) {
			ut.reStrAloCpy(m_author, tempAuthor);
		}

		return istr;

	}

	void Book::set(int member_id)
	{
		Publication::set(member_id);
		Publication::resetDate();
	}

	Book::operator bool() const
	{
		return Publication::operator bool() && m_author != nullptr && m_author[0] != '\0';
	}



}

