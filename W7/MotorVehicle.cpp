/*
*****************************************************************************
						  Workshop - #7 
Full Name  : Mostafa Hasanalipourshahrabadi
Student ID#: 154581227
Email      : mhasanalipourshahrab@myseneca.ca
Section    : NAA
Date       : 2023-07-17

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
#include "cstring.h"
#include "MotorVehicle.h"

using namespace std;
namespace sdds {
	MotorVehicle::MotorVehicle(const char* plateNumber, int vehicleYear)
	{
		strCpy(licensePlate, plateNumber);
		year = vehicleYear;
		strCpy(address, "Factory");
	}

	void MotorVehicle::moveTo(const char* location)
	{
		//check if the new address is different from the current address
		if (strCmp(address, location) != 0) {
			//change the address to a new location
			strCpy(address, location);
			
			cout << "|";
			cout.width(8);
			cout << licensePlate << "| |";
			cout.width(20);
			cout << address << " ---> ";
			cout.width(20);
			cout.setf(ios::left);
			cout << location;
			cout.unsetf(ios::left);
			cout << "|" << endl;
		}
	}

	std::ostream& MotorVehicle::write(std::ostream& os) const
	{
		os << "|";
		os.width(5);
		os << year << " | " << licensePlate << " | " << address;
		return os;
	}

	std::istream& MotorVehicle::read(std::istream& in)
	{
		cout << "Built year: ";
		in >> year;
		// Discard up to 1000 characters or until a newline character ('\n') is encountered
		in.ignore(1000, '\n');
		// Clear the error state flags of the input stream
		in.clear();


		cout << "License plate: ";
		// Reads a line of text from the input stream in
		// Up to a maximum of PLATE_NUM_SIZE - 1 characters
		// Stop reading at the newline character '\n'.
		// Store it in the character array licensePlate
		in.getline(licensePlate, PLATE_NUM_SIZE, '\n');

		cout << "Current location: ";
		in.getline(address, ADDRESS_SIZE, '\n');

		return in;
	}

	std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle)
	{
		return vehicle.write(os);
	}

	std::istream& operator>>(std::istream& in, MotorVehicle& vehicle)
	{
		return vehicle.read(in);
	}

}