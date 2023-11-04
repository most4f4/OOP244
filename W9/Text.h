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

        Text(const char* filename = nullptr);

        void read();

        virtual void write(std::ostream& os)const;

    };

    std::ostream& operator<<(std::ostream& leftOperand, const Text& rightOperand);

}
#endif