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

		Truck(){};

		Truck(const char* plateNumber, int vehicleYear, double truckCapacity, const char* truckAddress);

		bool addCargo(double cargo);

		bool unloadCargo();

		std::ostream& write(std::ostream& os);

		std::istream& read(std::istream& in);



	};


}


#endif
