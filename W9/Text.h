#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__

#include <iostream>

namespace sdds {

   class Text {

       char* m_filename{ nullptr }; // Hold the name of the file dynamically

       char* m_content{ nullptr }; // Holds the content of the text file dynamically. 

      int getFileLength()const; // Provides read-only access to the content of the text

   protected:

      const char& operator[](int index)const;

   public:

       Text(const Text&);

       Text& operator=(const Text&);

       virtual ~Text();

      Text(const char* filename=nullptr);
      void read();
      virtual void write(std::ostream& os)const;

   };

}
#endif // !SDDS_PERSON_H__

