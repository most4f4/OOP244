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
#include "Truck.h"

using namespace std;
namespace sdds {

    Truck::Truck(const char* plateNumber, int vehicleYear, double truckCapacity, const char* truckAddress) 
        :MotorVehicle(plateNumber, vehicleYear) {
        capacity = truckCapacity;
        currentLoad = 0.0;
        moveTo(truckAddress);
    }

    bool Truck::addCargo(double cargo)
    {
        double weight = currentLoad + cargo;
        if (weight <= capacity)
        {
            currentLoad += cargo;
            return true;
        }
        return false;
    }

    bool Truck::unloadCargo()
    {
        if (currentLoad > 0) {
            currentLoad = 0.0;
            return true;
        }
        return false;
    }

    std::ostream& Truck::write(std::ostream& os) const
    {
        MotorVehicle::write(os); // Call the base class write function
        os << " | " << currentLoad << "/" << capacity;
        return os;
    }

    std::istream& Truck::read(std::istream& in)
    {
        MotorVehicle::read(in); // Call the base class read function
        
        cout << "Capacity: ";
        in >> capacity;

        while (!in || capacity < 0.0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invaild input, enter another capacity: ";
            cin >> capacity;
        }

        cout << "Cargo: ";
        in >> currentLoad;
        while (!in) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invaild input, enter another cargo weight: ";
            cin >> currentLoad;
        }

        return in;

    }

    std::ostream& operator<<(std::ostream& os, const Truck& truck)
    {
        return truck.write(os);
    }

    std::istream& operator>>(std::istream& is, Truck& truck) {
        return truck.read(is);
    }

}