#include <iostream>
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


}
