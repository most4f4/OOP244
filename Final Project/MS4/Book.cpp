#include "Book.h"
#include "Utils.h"

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



}

