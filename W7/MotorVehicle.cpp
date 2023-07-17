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
			cout << "|[";
			cout.setf(ios::right);
			cout.width(8);
			cout << licensePlate << "]| |[";
			cout.width(20);
			cout << address << "] ---> [";
			cout.unsetf(ios::right);
			cout.width(20);
			cout.setf(ios::left);
			cout << location;
			cout.unsetf(ios::left);
			cout << "]|" << endl;

			//change the address to a new location
			strCpy(address, location);
		}
	}

}