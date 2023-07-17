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

#ifndef SDDS_MOTORVEHICLE_H_
#define SDDS_MOTPRVEHICLE_H_
#include <iostream>

#define PLATE_NUM_SIZE 9 // Size of the license plate array
#define ADDRESS_SIZE 64 // Size of the address array

namespace sdds {

	class MotorVehicle {
	private:

		// License plate number of the vehicle
		char licensePlate[PLATE_NUM_SIZE]{ '\0' };

		// Address where the vehicle is located
		char address[ADDRESS_SIZE]{ '\0' };

		// Year when the vehicle was built
		int year{ 0 };

	public:
		MotorVehicle() {};

		// Constructor that initializes license plate and year
		MotorVehicle(const char* plateNumber, int vehicleYear, const char* location = "Factory");

		// Moves the vehicle to a new address
		void moveTo(const char* location);

		// Writes the object's data to an output stream
		std::ostream& write(std::ostream& os) const;

		// Reads the object's data from an input stream
		std::istream& read(std::istream& in);
	};

	// Overloaded output stream operator
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle);

	// Overloaded input stream operator
	std::istream& operator>>(std::istream& in, MotorVehicle& vehicle);
}


#endif
