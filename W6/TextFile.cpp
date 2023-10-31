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

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"

using namespace std;
namespace sdds {

    Line::operator const char* () const {
        return (const char*)m_value;
    }

    Line& Line::operator=(const char* lineValue) {
        delete[] m_value;
        m_value = new char[strLen(lineValue) + 1];
        strCpy(m_value, lineValue);
        return *this;
    }

    Line::~Line() {
        delete[] m_value;
        m_value = nullptr;
    }

    void TextFile::setEmpty()
    {
        delete[] m_textLines;
        m_textLines = nullptr;

        delete[] m_filename;
        m_filename = nullptr;

        m_noOfLines = 0;
    }

    void TextFile::setFilename(const char* fname, bool isCopy)
    {
        delete[] m_filename;

        int prefixLength = isCopy ? 2 : 0;
        m_filename = new char[strLen(fname) + prefixLength + 1];

        if (isCopy) {
            strCpy(m_filename, "C_");
            strCat(m_filename, fname);
        }
        else {
            strCpy(m_filename, fname);
        }
    }

    void TextFile::setNoOfLines()
    {
        ifstream readfile(m_filename);
        m_noOfLines = 0;
        char ch;

        if (readfile) {
            while (readfile.get(ch))
            {
                if (ch == '\n') {
                    m_noOfLines++;
                }

                // Increase m_noOfLines by one if the last line doesn't have a newline character
                m_noOfLines++;
            }
        }
        else setEmpty();

        if (m_noOfLines == 0) setEmpty();

    }

    void TextFile::loadText()
    {
        if (m_filename != nullptr) {

            // Ensure m_textLine is deleted to prevent memory leak
            delete[] m_textLines;
            m_textLines = nullptr;

            // dynamically allocate an array of Lines with the size of m_noOfLines
            m_textLines = new Line[m_noOfLines];

            // a local instance of ifstream using the file name (m_filename) to read the lines of the text file.
            ifstream readfile(m_filename);

            //Read the line using a local C++ string object and the getline helper function
            string line;
            int count = 0;

            while (getline(readfile, line)) {

                //set the m_textLines array elements to the values returned by the c_str() method of the string object
                m_textLines[count] = line.c_str();
                count++;
            }

            m_noOfLines = count;
        }
        
    }

    void TextFile::saveAs(const char* fileName) const
    {
        //Use a local ofstream object to open a new file using the name kept in the argument filename
        ofstream newFile(fileName);

        //Loop through the elements of the m_textLines array and write them in the opened file adding a new line to the end of each line.
        for (unsigned int i = 0; i < m_noOfLines; i++) {
            newFile << m_textLines[i] << endl;
        }

    }

    TextFile::TextFile(unsigned pageSize)
    {
        setEmpty();
        m_pageSize = pageSize;
    }

    TextFile::TextFile(const char* filename, unsigned pageSize)
    {
        setEmpty();
        m_pageSize = pageSize;

        if (filename != nullptr && filename[0] != '\0') {
            setFilename(filename);
            setNoOfLines();
            loadText();
        }

    }

    sdds::TextFile::TextFile(const TextFile& source)
    {
        
        setEmpty();
        m_pageSize = source.m_pageSize;

            if (source.m_textLines != nullptr && source.m_noOfLines > 0) {
                setFilename(source.m_filename, true);

                m_noOfLines = source.m_noOfLines;
                m_textLines = new Line[m_noOfLines];

                for (unsigned i = 0; i < m_noOfLines; i++) {
                    m_textLines[i].m_value = new char[strLen(source.m_textLines[i].m_value) + 1];
                    strCpy(m_textLines[i].m_value, source.m_textLines[i].m_value);
                }

                saveAs(m_filename);
            }        

    }

    TextFile& TextFile::operator=(const TextFile& source)
    {
        
        if (this != &source) {

            if (m_textLines != nullptr) {
                delete[] m_textLines;
                m_textLines = nullptr;
            }

            if (source.m_textLines != nullptr && source.m_noOfLines > 0) {
                m_noOfLines = source.m_noOfLines;
                m_textLines = new Line[m_noOfLines];

                for (unsigned i = 0; i < m_noOfLines; i++) {
                    m_textLines[i].m_value = new char[strLen(source.m_textLines[i].m_value) + 1];
                    strCpy(m_textLines[i].m_value, source.m_textLines[i].m_value);
                }

                saveAs(m_filename);
            }
        }

        return *this;
    }

    TextFile::~TextFile()
    {
        setEmpty();
    }

    std::ostream& TextFile::view(std::ostream& ostr) const
    {

        if (m_filename == nullptr || m_noOfLines == 0) {
            return ostr;
        }

        ostr << m_filename << endl;

        //underline the file name with '=' character
        for (int i = 0; i < strLen(m_filename); i++) {
            ostr << '=';
        }
        ostr << endl;

        unsigned int lineCounter = 0;

        // Print lines one by one
        for (unsigned int i = 0; i < m_noOfLines; i++) {
            ostr << m_textLines[i] << endl;
            lineCounter++;

            // Pause after printing m_pageSize lines
            if (lineCounter == m_pageSize) {
                cout << "Hit ENTER to continue...";
                cin.get();
                lineCounter = 0;
            }
        }

        return ostr;

    }

    std::istream& TextFile::getFile(std::istream& istr)
    {
        string filename;
        getline(istr, filename);

        setFilename(filename.c_str());
        setNoOfLines();
        loadText();

        return istr;
    }

    TextFile::operator bool() const
    {
        return (m_textLines != nullptr && m_noOfLines > 0);
    }

    unsigned TextFile::lines() const
    {
        return m_noOfLines;
    }

    const char* TextFile::name() const
    {
        return m_filename;
    }

    const char* TextFile::operator[](unsigned index) const
    {
        if (m_textLines == nullptr || m_noOfLines == 0) {
            return nullptr;
        }

        return m_textLines[index % m_noOfLines];
    }

    std::ostream& operator<<(std::ostream& ostr, const TextFile& text)
    {
        text.view(ostr);
        return ostr;
    }

    std::istream& operator>>(std::istream& istr, TextFile& text)
    {
        text.getFile(istr);
        return istr;
    }

}



