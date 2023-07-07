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