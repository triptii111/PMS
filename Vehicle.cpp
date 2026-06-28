#include "Vehicle.h"

Vehicle::Vehicle() {
    regNumber  = "";
    ownerName  = "";
    vehicleType = "";
}

Vehicle::Vehicle(string reg, string owner, string type) {
    regNumber  = reg;
    ownerName  = owner;
    vehicleType = type;
}
