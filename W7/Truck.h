#ifndef SDDS_TRUCK_H_
#define SDDS_TRUCK_H_
#include <iostream>
#include "MotorVehicle.h"


namespace sdds {
	class Truck : public MotorVehicle {
	
	private:

		// Maximum weight of cargo the truck can carry in kilograms
		double capacity{ 0.0 };

		// Current cargo load in kilograms
		double currentLoad{ 0.0 };

	public:

		// Default constructor
		Truck(){};

		// Custom constructor
		Truck(const char* plateNumber, int vehicleYear, double truckCapacity, const char* truckAddress);

		// Mutator to add cargo
		bool addCargo(double cargo);

		// Mutator to unload cargo
		bool unloadCargo();

		// Query to write object content to ostream
		std::ostream& write(std::ostream& os) const;

		// Mutator to read object content from istream
		std::istream& read(std::istream& in);
	};

	// Overload the << operator to insert Truck object into ostream
	std::ostream& operator<<(std::ostream& os, const Truck& truck);

	// Overload the >> operator to extract Truck object from istream
	std::istream& operator>>(std::istream& in, Truck& truck);

}


#endif
