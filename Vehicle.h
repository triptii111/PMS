#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle {
public:
    string regNumber;
    string ownerName;
    string vehicleType;

    Vehicle();
    Vehicle(string reg, string owner, string type);
};

#endif
