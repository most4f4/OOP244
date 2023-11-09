/* Citation and Sources...
Final Project Milestone 4
Module: Publication
Filename: Publication.cpp
Version 1.0
Author	Mostafa Hasanalipourshahrabadi
Revision History
-----------------------------------------------------------
Date      Reason
2023/11/07  Preliminary release
2023/11/08  Edited in MS4 (write function)


-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Utils.h"
#include "Publication.h"

using namespace std;
namespace sdds {

	void Publication::setEmpty()
	{
		if (m_title != nullptr) {
			delete[] m_title;
			m_title = nullptr;
		}
		m_shelfId[0] = '\0';
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

	bool Publication::conIO(ios& io)const {
		return &io == &cin || &io == &cout;
	}

	ostream& Publication::write(ostream& os) const
	{
		if (conIO(os)) {
			os << "| " << m_shelfId << " | ";

			if (ut.strlen(m_title) > SDDS_TITLE_WIDTH) {
				for (int i = 0; i < SDDS_TITLE_WIDTH; i++) {
					os << m_title[i];
				}
			}else {
				os.setf(ios::left);
				os.width(SDDS_TITLE_WIDTH);
				os.fill('.');
				os << m_title;
				os.unsetf(ios::left);
			}

			os << " | ";

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

	istream& Publication::read(istream& istr)
	{
		setEmpty();

		char tempTitle[256]{};
		char tempShelfId[SDDS_SHELF_ID_LEN + 1]{};
		int tempMembership = 0;
		int tempLibRef = -1;
		Date tempDate;

		if (conIO(istr)) {

			cout << "Shelf No: ";
			istr.getline(tempShelfId, SDDS_SHELF_ID_LEN + 1);

			if (strlen(tempShelfId) != SDDS_SHELF_ID_LEN) {
				istr.setstate(ios::failbit);
			}

			cout << "Title: ";
			istr.getline(tempTitle, 256);

			cout << "Date: ";
			istr >> tempDate;

		}
		else {
			istr >> tempLibRef;
			istr.ignore();
			istr.getline(tempShelfId, SDDS_SHELF_ID_LEN + 1, '\t');
			istr.getline(tempTitle, 256, '\t');
			istr >> tempMembership;
			istr.ignore();
			istr >> tempDate;
		}

		if (!tempDate) {
			istr.setstate(ios::failbit);
		}

		if (istr) {
			m_title = new char[strlen(tempTitle) + 1];
			strcpy(m_title, tempTitle);
			strcpy(m_shelfId, tempShelfId);
			set(tempMembership);
			m_date = tempDate;
			setRef(tempLibRef);
		}

		return istr;
	}

	Publication::Publication(const Publication& src)
	{
		operator=(src);
	}

	Publication& Publication::operator=(const Publication& src)
	{
		if (this != &src) {

			delete[] m_title;
			m_title = nullptr;

			if (src.m_title) {
				m_title = new char[strlen(src.m_title) + 1];
				strcpy(m_title, src.m_title);
			}

			strcpy(m_shelfId, src.m_shelfId);
			set(src.m_membership);
			setRef(src.m_libRef);
			m_date = src.m_date;

		}

		return *this;
	}

	Publication::~Publication()
	{
		delete[] m_title;
	}


}
