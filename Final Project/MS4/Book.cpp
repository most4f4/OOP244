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
		// TODO: insert return statement here
	}



}

