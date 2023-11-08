#ifndef SDDS_PUBLICATION_H__
#define SDDS_PUBLICATION_H__

#include <iostream>
#include "Streamable.h"
#include "Lib.h"
#include "Date.h"

namespace sdds {

	class Publication : public Streamable {

		char* m_title{};
		char m_shelfId[SDDS_SHELF_ID_LEN+1]{};
		int m_membership{ 0 };
		int m_libRef{ -1 };
		Date m_date;
		void setEmpty();

	public:

		Publication();
		virtual void set(int member_id);
		void setRef(int value);
		void resetDate();
		virtual char type()const;
		bool onLoan()const;
		Date checkoutDate()const;
		bool operator==(const char* title)const;
		operator const char* ()const;
		int getRef()const;
		operator bool() const;
		bool conIO(std::ios& io)const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);

		Publication(const Publication& src);
		Publication& operator=(const Publication& src);
		virtual ~Publication();

	};

}


#endif // !SDDS_PUBLICATION_H__
