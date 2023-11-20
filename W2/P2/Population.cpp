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

#include <iostream>
#include "Population.h"
#include "File.h"
#include "cstring.h"

using namespace std;

namespace sdds{
    int numPosts;
    int population;
    PostalCode* postcode;


    void sort() {
        for (int i = 1; i < numPosts; i++) {
            PostalCode current = postcode[i];
            int j = i - 1;

            while (j >= 0 && postcode[j].population > current.population) {
                postcode[j + 1] = postcode[j];
                j--;
            }

            postcode[j + 1] = current;
        }
    }

    bool load(PostalCode& post) {
        char code[7];

        if (read(code) && read(post.population)) {
            post.code = new char[strLen(code) + 1];
            strCpy(post.code, code);
            return true;
        }

        return false;
    }

    bool load(const char filename[]) {
        
        if (!openFile(filename)) {
            cout << "Could not open data file: " << filename << endl;
            return false;
        }

        numPosts = noOfRecords();
        postcode = new PostalCode[numPosts];
        int i = 0;

        for (int j = 0; j < numPosts; j++) {
            if (load(postcode[j]))
                i++;
        }

        closeFile();

        if (i != numPosts) {
            cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
            return false;
        }

        return true;
    }

    void display(const PostalCode& code)
    {
        cout << code.code << ":  " << code.population << endl;
    }

    void display() {
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;

        sort();

        int population = 0;
        for (int i = 0; i < numPosts; i++) {
            cout << i + 1 << "- ";
            display(postcode[i]);
            population += postcode[i].population;
        }

        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << population << endl;
    }


    void deallocateMemory()
    {
        for (int i = 0; i < numPosts; i++) {
            delete[] postcode[i].code;
            postcode[i].code = nullptr;
        }

        delete[] postcode;
        postcode = nullptr;
    }
} 