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

}