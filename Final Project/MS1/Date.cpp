// Final Project Milestone 1 
// Date Module
// File	Date.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name: Mostafa Hasanalipourshahrabadi
// Date: 2023-07-15
// Reason: Developed read/write/Comparison operator overload methods
//                   /operator- /bool type conversion operator 
// 
/////////////////////////////////////////////////////////////////
/*
*****************************************************************
                          Final project milestone 1
Full Name  : Mostafa Hasanalipourshahrabadi
Student ID#: 154581227
Email      : mhasanalipourshahrab@myseneca.ca
Section    : NAA
Date       : 2023-07-15

Authenticity Declaration:
I declare this submission is the result of my own work and has
not been shared with any other student or 3rd party content
provider. This submitted piece of work is entirely of my own
creation.
*****************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"
namespace sdds {
   bool Date::validate() {
      errCode(NO_ERROR);
      if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
         errCode(YEAR_ERROR);
      }
      else if (m_mon < 1 || m_mon > 12) {
         errCode(MON_ERROR);
      }
      else if (m_day < 1 || m_day > mdays()) {
         errCode(DAY_ERROR);
      }
      return !bad();
   }
   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
      mon--;
      return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
   }
   int Date::systemYear()const {
      time_t t = time(NULL);
      tm lt = *localtime(&t);
      return lt.tm_year + 1900;
   }
   void Date::setToToday() {
      time_t t = time(NULL);
      tm lt = *localtime(&t);
      m_day = lt.tm_mday;
      m_mon = lt.tm_mon + 1;
      m_year = lt.tm_year + 1900;
      errCode(NO_ERROR);
   }
   int Date::daysSince0001_1_1()const { // Rata Die day since 0001/01/01 
      int ty = m_year;
      int tm = m_mon;
      if (tm < 3) {
         ty--;
         tm += 12;
      }
      return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
   }
   Date::Date() :m_CUR_YEAR(systemYear()) {
      setToToday();
   }
   Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
      m_year = year;
      m_mon = mon;
      m_day = day;
      validate();
   }
   const char* Date::dateStatus()const {
      return DATE_ERROR[errCode()];
   }
   int Date::currentYear()const {
      return m_CUR_YEAR;
   }
   int Date::getDaysSince0001_1_1() const
   {
       return daysSince0001_1_1();
   }
   void Date::errCode(int readErrorCode) {
      m_ErrorCode = readErrorCode;
   }
   int Date::errCode()const {
      return m_ErrorCode;
   }
   bool Date::bad()const {
      return m_ErrorCode != 0;
   }
  
   ostream& operator<<(ostream& os, const Date& rightOperand) {
      return rightOperand.write(os);
   }
   istream& operator>>(istream& is, Date& rightOperand) {
      return rightOperand.read(is);
   }

   /*============================= MY CODE ==============================*/

   std::istream& Date::read(std::istream& is)
   {
       errCode(NO_ERROR);

       is >> m_year;
       is.ignore(); 
       is >> m_mon;
       is.ignore();
       is >> m_day;

       if (is.fail()) {
           is.clear();
           is.ignore(1000, '\n');
           errCode(CIN_FAILED);
       }
       else {
           validate();
       }

       is.ignore(1000, '\n');
       return is;
   }

   std::ostream& Date::write(std::ostream& os) const
   {
       if (bad()) {
           os << dateStatus();
       } else {
           os << m_year << "/";
           os.setf(ios::right);
           os.width(2);
           os.fill('0');
           os << m_mon << "/";
           os.width(2);
           os.fill('0');
           os << m_day;
           os.fill(' ');
           os.unsetf(ios::right);
       }
       return os;
   }

   Date::operator bool() const
   {
       return !bad();
   }

   bool operator==(const Date& leftOperand, const Date& rightOperand)
   {
       return leftOperand.getDaysSince0001_1_1() == rightOperand.getDaysSince0001_1_1();
   }

   bool operator!=(const Date& leftOperand, const Date& rightOperand)
   {
       return leftOperand.getDaysSince0001_1_1() != rightOperand.getDaysSince0001_1_1();
   }

   bool operator>=(const Date& leftOperand, const Date& rightOperand)
   {
       return leftOperand.getDaysSince0001_1_1() >= rightOperand.getDaysSince0001_1_1();
   }

   bool operator<=(const Date& leftOperand, const Date& rightOperand)
   {
       return leftOperand.getDaysSince0001_1_1() <= rightOperand.getDaysSince0001_1_1();
   }

   bool operator>(const Date& leftOperand, const Date& rightOperand)
   {
       return leftOperand.getDaysSince0001_1_1() > rightOperand.getDaysSince0001_1_1();
   }

   bool operator<(const Date& leftOperand, const Date& rightOperand)
   {
       return leftOperand.getDaysSince0001_1_1() < rightOperand.getDaysSince0001_1_1();
   }

   bool operator-(const Date& leftOperand, const Date& rightOperand)
   {
       return leftOperand.getDaysSince0001_1_1() - rightOperand.getDaysSince0001_1_1();
   }

}
