#include "HtmlText.h"
#include "cstring.h"

namespace sdds {

	HtmlText::HtmlText(const char* filename, const char* title)

		: Text(filename) // Pass the filename to its base class
	{

		// Check if the title is not null, then dynamically allocate the attribute
		if (title != nullptr && title[0] != '\0') {

			m_title = new char[strLen(title) + 1];
			strCpy(m_title, title);

		}

	}

	HtmlText::~HtmlText()
	{
		delete[] m_title;
		m_title = nullptr;
	}

	HtmlText::HtmlText(const HtmlText& src)
	{
		*this = src;
	}

	HtmlText& HtmlText::operator=(const HtmlText& src)
	{
		if (this != &src) {

			Text::operator=(src);
			// (Text&)*this = src;
			
			delete[] m_title;
			m_title = nullptr;
			
			if (src.m_title) {
				m_title = new char[strLen(src.m_title) + 1];
				strCpy(m_title, src.m_title);
			}
		}

		return *this;
		
	}
}