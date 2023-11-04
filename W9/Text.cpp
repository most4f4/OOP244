#include <fstream>
#include <cstring>
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
               m_filename = new char[strlen(src.m_filename) + 1];
               strcpy(m_filename, src.m_filename);
           }

           if (src.m_content) {
               m_content = new char[strlen(src.m_content) + 1];
               strcpy(m_content, src.m_content);
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

           m_filename = new char[strlen(filename) + 1];
           strcpy(m_filename, filename);

           read();

       } 
   }

   std::ostream& operator<<(std::ostream& leftOperand, const Text& rightOperand)
   {
       // TODO: insert return statement here
   }

}