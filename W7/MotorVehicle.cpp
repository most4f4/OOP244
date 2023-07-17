#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "MotorVehicle.h"

using namespace std;
namespace sdds {
	MotorVehicle::MotorVehicle(const char* plateNumber, int vehicleYear)
	{
		strCpy(licensePlate, plateNumber);
		strCpy(address, "Factory");
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
		in.getline(licensePlate, PLATE_NUM_SIZE);

		cout << "Current location: ";
		in.getline(address, ADDRESS_SIZE);

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