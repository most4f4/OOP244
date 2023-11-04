#include <fstream>
#include <cstring>
#include "Text.h"

using namespace std;

namespace sdds {

   int Text::getFileLength() const {

      int len = 0;

      ifstream fin(m_filename);

      while (fin) {

         fin.get();

         len += !!fin;

      }

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

}