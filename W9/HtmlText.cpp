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

	void HtmlText::write(std::ostream& os) const
	{
		// Boolean variable to keep track of multiple spaces (MS for Multiple Spaces)
		bool MS = false;

		os << "<html><head><title>";

		(m_title != nullptr) ? os << m_title : os << "No title";

		os << "</title></head>\n<body>\n";

		if (m_title) {
			os << "<h1>" << m_title << "</h1>\n";
		}

		// Loop through the characters of the m_content and convert special characters to HTML entities
		int index = 0;
		char ch;

		while (Text::operator[](index) != '\0') {

			ch = operator[](index);

			switch (ch)
			{
			case ' ':
				if (MS) os << "&nbsp;";
				else {
					os << ' ';
					MS = true;
				}
				break;
			case '<':
				os << "&lt;";
				MS = false;
				break;
			case '>':
				os << "&gt;";
				MS = false;
				break;
			case '\n':
				os << "<br />\n";
				MS = false;
				break;
			default:
				os << ch;
				MS = false;
				break;;
			}

			index++;

		}

		os << "</body>\n</html>";

	}
}