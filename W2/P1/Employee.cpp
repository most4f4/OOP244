#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

   int noOfEmployees;
   Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }


   bool load(Employee& emp)
   {
       bool ok = false;
       char name[128];

       if (read(emp.m_empNo) && read(emp.m_salary) && read(name))
       {
           emp.m_name = new char[strLen(name) + 1];
           strCpy(emp.m_name, name);
           ok = true;
       }
       return ok;
   }

   bool load() {
      bool ok = false;
      int i = 0;
      if (openFile(DATAFILE)) {
         
          noOfEmployees = noOfRecords();

           employees = new Employee[noOfEmployees];
           
           for (int j = 0; j < noOfEmployees; j++)
           {
               i += load(employees[j]);
           }

           if (i != noOfEmployees)
           {
               cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
           }
           else
           {
               ok = true;
           }

           closeFile();
      } else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }

   void display(const Employee& emp)
   {
       cout << emp.m_empNo << ": " << emp.m_name << ", " << emp.m_salary << endl;
   }

   void display()
   {
       cout << "Employee Salary report, sorted by employee number" << endl;
       cout << "no- Empno, Name, Salary" << endl;
       cout << "------------------------------------------------" << endl;

       sort();

       for (int i = 0; i < noOfEmployees; i++)
       {
           cout << i + 1 << "- ";
           display(employees[i]);
       }
   }


   void deallocateMemory()
   {
       for (int i = 0; i < noOfEmployees; i++)
       {
           delete[] employees[i].m_name;
       }

       delete[] employees;
   }

}