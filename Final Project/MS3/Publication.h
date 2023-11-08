#ifndef SDDS_PUBLICATION_H__
#define SDDS_PUBLICATION_H__

#include <iostream>
#include "Lib.h"
#include "Date.h"

namespace sdds {

	class Publication {

		const char* m_title{};
		const char* m_shelfId[SDDS_SHELF_ID_LEN+1]{};
		int m_membership{ 0 };
		int m_libRef{ -1 };
		Date m_date;

	public:

		Publication();


	};

}


#endif // !SDDS_PUBLICATION_H__
