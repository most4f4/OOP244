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

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds{

    FILE* fptr;

    bool openFile(const char file[]){
        fptr = fopen(file, "r");
        return fptr != NULL;
    }

    int noOfRecords(){
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }

    void closeFile(){
        if (fptr)
            fclose(fptr);
    }

    bool read(char* code){
        return fscanf(fptr, "%[^,],", code) == 1;
    }

    bool read(int& population)
    {
        return fscanf(fptr, "%d\n", &population) == 1;
    }

} 