#ifndef SDDS_STREAMABLE_H__
#define SDDS_STREAMABLE_H__

#include <iostream>

namespace sdds {

	class Streamable {

	public:

		virtual std::ostream& write(std::ostream& os = std::cout)const = 0;

		virtual std::istream& read(std::istream& is = std::cin) = 0;

		virtual bool conIO(std::istream& is)const = 0;

		virtual operator bool()const = 0;

		virtual ~Streamable();

	};

	std::ostream& operator<<(std::ostream& os, const Streamable& rightOperand);

	std::istream& operator>>(std::istream& is, Streamable& rightOperand);

}

#endif // !SDDS_STREAMABLE_H__
