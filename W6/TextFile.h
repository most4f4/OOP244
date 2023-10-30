/*
*****************************************************************************
                          Workshop - #6 (P1)
Full Name  : Mostafa Hasanalipourshahrabadi
Student ID#: 154581227
Email      : mhasanalipourshahrab@myseneca.ca
Section    : NAA
Date       : 2023-07-08

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_TEXTFILE_H_
#define SDDS_TEXTFILE_H_

#include <iostream>

namespace sdds {

   class TextFile; // forward declaration

   class Line {

      char* m_value{ nullptr }; // initialized to nullptr

      operator const char* () const; //Returns the address held in the m_value attribute.
      Line() {};
      Line& operator=(const char*);
      ~Line();

      friend class TextFile;

      // copy and copy assignment prevention
      Line(Line&) = delete;
      Line& operator=(const Line&) = delete;

   };

   class TextFile {
      Line* m_textLines{ nullptr }; // initialized to nullptr
      char* m_filename{ nullptr }; // initialized to nullptr
      unsigned m_noOfLines;
      unsigned m_pageSize;

      void setFilename(const char* fname, bool isCopy = false);
      void setNoOfLines();
      void loadText();
      void saveAs(const char *fileName)const;
      void setEmpty();
   public:
      TextFile(unsigned pageSize = 15);
      TextFile(const char* filename, unsigned pageSize = 15);
      TextFile(const TextFile& source);
      TextFile& operator=(const TextFile& src);
      ~TextFile();
      std::ostream& view(std::ostream& ostr)const;
      std::istream& getFile(std::istream& istr);
      operator bool()const;
      unsigned lines()const;
      const char* name()const;
      const char* operator[](unsigned index)const;
   };
   std::ostream& operator<<(std::ostream& ostr, const TextFile& text);
   std::istream& operator>>(std::istream& istr, TextFile& text);

}

#endif // !SDDS_TEXTFILE_H_
