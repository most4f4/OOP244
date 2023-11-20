/*
*****************************************************************************
                          Workshop - #2 (P2)
Full Name  : Mostafa Hasanalipourshahrabadi
Student ID#: 154581227
Email      : mhasanalipourshahrab@myseneca.ca
Section    : NAA
Date       : 2023-05-27


Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds{
    struct PostalCode{
        char* code;
        int population;
    };

    void sort();
    bool load(const char filename[]);
    bool load(PostalCode& post);
    void display(const PostalCode& code);
    void display();
    void deallocateMemory();

} 
#endif 