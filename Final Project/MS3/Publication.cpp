#include <iostream>
#include <cstring>
#include <iomanip>
#include "Publication.h"

using namespace std;
namespace sdds {

	void Publication::setEmpty()
	{
		m_title = nullptr;
		m_shelfId[0] = "\0";
		m_membership = 0;
		m_libRef = -1;
		m_date.setToToday();
	}

	Publication::Publication()
	{
		setEmpty();
	}

	void Publication::set(int member_id)
	{
		if (member_id > 9999 && member_id <= 99999) {
			m_membership = member_id;
		}
		else {
			m_membership = 0;
		}
	}

	void Publication::setRef(int value)
	{
		m_libRef = value;
	}

	void Publication::resetDate()
	{
		m_date.setToToday();
	}

	char Publication::type() const
	{
		return 'P';
	}

	bool Publication::onLoan() const
	{
		return m_membership != 0;
	}

	Date Publication::checkoutDate() const
	{
		return m_date;
	}

	bool Publication::operator==(const char* title) const
	{
		return strstr(m_title, title) != nullptr;
	}

	Publication::operator const char* () const
	{
		return m_title;
	}

	int Publication::getRef() const
	{
		return m_libRef;
	}

	Publication::operator bool() const
	{
		return m_title != nullptr && m_shelfId[0] != '\0';
	}

	bool Publication::conIO(ios& io)const
	{
		return (&io == &cin || &io == &cout);
	}

	ostream& Publication::write(ostream& os) const
	{
		if (conIO(os)) {
			os << "| " << m_shelfId << " | " << left << setw(30) << setfill('.') << m_title << " | ";
			if (m_membership != 0) {
				os << m_membership;
			}
			else {
				os << " N/A ";
			}
			os << " | " << m_date << " | ";
		}
		else {
			os << type() << '\t' << m_shelfId << '\t' << m_title << '\t';
			if (m_membership != 0) {
				os << m_membership;
			}
			else {
				os << " N/A ";
			}
			os << '\t' << m_date;
		}

		return os;
	}


}
