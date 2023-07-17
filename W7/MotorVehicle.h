#ifndef SDDS_MOTORVEHICLE_H_
#define SDDS_MOTPRVEHICLE_H_
#include <iostream>

#define PLATE_NUM_SIZE 9
#define ADDRESS_SIZE 64

namespace sdds {
	class MotorVehicle {
	private:
		char licensePlate[PLATE_NUM_SIZE]{ '\0' };
		char address[ADDRESS_SIZE]{ '\0' };
		int year{ 0 };
	public:
		MotorVehicle() {};
		MotorVehicle(const char* plateNumber, int vehicleYear);
		void moveTo(const char* location);
		std::ostream& write(std::ostream& os) const;





	};
}


#endif
