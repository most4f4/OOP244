/*
*****************************************************************************
                          Workshop - #9
Full Name  : Mostafa Hasanalipourshahrabadi
Student ID#: 154581227
Email      : mhasanalipourshahrab@myseneca.ca
Section    : NAA
Date       : 2023-11-04

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include <fstream>
#include "cstring.h"
#include "Text.h"

using namespace std;

namespace sdds {

   int Text::getFileLength() const {

       // Initialize the variable to store the file length.
      int len = 0;

      // Open the input file stream with the specified filename.
      ifstream fin(m_filename);

      // Loop until the end of the file is reached.
      while (fin) {

         // Attempt to read a character from the file.
         fin.get();

         // Check if the read operation was successful (fin is true) and increment len by 1.
         len += !!fin;

      }

      // Close the file stream and return the total number of characters read.
      return len;

   }

   const char& Text::operator[](int index) const
   {
       return m_content[index];
   }

   Text::Text(const Text& src)
   {
       *this = src; 
   }

   Text& Text::operator=(const Text& src)
   {
       if (this != &src) {

           delete[] m_filename;
           m_filename = nullptr;

           delete[] m_content;
           m_content = nullptr;

           if (src.m_filename) {
               m_filename = new char[strLen(src.m_filename) + 1];
               strCpy(m_filename, src.m_filename);
           }

           if (src.m_content) {
               m_content = new char[strLen(src.m_content) + 1];
               strCpy(m_content, src.m_content);
           }

           return *this;
       }

   }
   
   Text::~Text()
   {
       delete[] m_filename;
       m_filename = nullptr;

       delete[] m_content;
       m_content = nullptr;

   }

   Text::Text(const char* filename)
   {
       if (filename) {

           m_filename = new char[strLen(filename) + 1];
           strCpy(m_filename, filename);

           read();

       } 
   }

   void Text::read()
   {

       if (m_content) delete[] m_content;

       m_content = new char[strLen(getFileLength()) + 1];

   }

   void Text::write(std::ostream& os) const
   {

       if (m_content) {
           os << m_content;
       }

   }

   std::ostream& operator<<(std::ostream& leftOperand, const Text& rightOperand)
   {
       rightOperand.write(leftOperand);
       return leftOperand;
   }

}