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
	MotorVehicle::MotorVehicle(const char* plateNumber, int vehicleYear, const char* location)
	{
		strCpy(licensePlate, plateNumber);
		strCpy(address, location);
		year = vehicleYear;
	}

	void MotorVehicle::moveTo(const char* location)
	{
		//check if the new address is different from the current address
		if (strCmp(address, location) != 0) {
			cout << "|";
			cout.setf(ios::right);
			cout.width(8);
			cout << licensePlate << "| |";
			cout.width(20);
			cout << address << " ---> ";
			cout.unsetf(ios::right);
			cout.width(20);
			cout.setf(ios::left);
			cout << location;
			cout.unsetf(ios::left);
			cout << "|" << endl;

			//change the address to a new location
			strCpy(address, location);
		}
	}

	std::ostream& MotorVehicle::write(std::ostream& os) const
	{
		cout << "|";
		cout.width(5);
		cout << year << " | " << licensePlate << " | " << address;
		return os;
	}

	std::istream& MotorVehicle::read(std::istream& in)
	{
		cout << "Built year: ";
		in >> year;
		while (!in || year < 0) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invaild input, enter another year: ";
			cin >> year;
		}

		cout << "License plate: ";
		in >> licensePlate;
		while (!in) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invaild input, enter another plate number: ";
			cin >> licensePlate;
		}


		cout << "Current location: ";
		in >> address;

		while (address[0] == '\0') {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input. enter another address: ";
			cin.getline(address, ADDRESS_SIZE);
		}

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